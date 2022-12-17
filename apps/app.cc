#include <iostream>
#include <memory>
#include <queue>

#include <INIReader.h>
#include <SFML/Graphics.hpp>

#include <game/command.hh>
#include <game/move_player_command.hh>
#include <game/player.hh>
#include <utils/console.hh>

const sf::Keyboard::Key MOVE_LEFT = sf::Keyboard::Left;
const sf::Keyboard::Key MOVE_RIGHT = sf::Keyboard::Right;

int main(int argc, char *argv[])
{
    std::cout << "Ready to play some " << utils::console::colorize("Breakout", utils::console::ForegroundColor::Red, utils::console::BackgroundColor::White, utils::console::FormatAttribute::Bold, utils::console::ResetFormatAttribute::All) << "?" << std::endl;

    INIReader ini("data/config.ini");
    const float PLAYER_SPEED = ini.GetFloat("player", "speed", 500);

    sf::RenderWindow window(sf::VideoMode(ini.GetInteger("window", "width", 800), ini.GetInteger("window", "height", 600)), "SFML Breakout");
    sf::CircleShape ball(ini.GetFloat("ball", "radius", 5));
    ball.setFillColor(sf::Color::Green);

    auto player_size = sf::Vector2f(ini.GetFloat("player.size", "x", 1), ini.GetFloat("player.size", "y", 1));
    auto player_spawn = sf::Vector2f(ini.GetFloat("player.position", "x", 0), ini.GetFloat("player.position", "y", 0));
    game::Player player(player_size, player_spawn);

    std::queue<std::unique_ptr<game::Command>> commands;

    sf::Clock clock;
    while (window.isOpen())
    {
        float delta = clock.getElapsedTime().asSeconds();
        clock.restart();

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // update
        if (sf::Keyboard::isKeyPressed(MOVE_LEFT))
        {
            auto pos = sf::Vector2f(-PLAYER_SPEED, 0) * delta;
            commands.push(std::make_unique<game::MovePlayerCommand>(&player, pos, 0, window.getSize().x));
        }
        if (sf::Keyboard::isKeyPressed(MOVE_RIGHT))
        {
            auto pos = sf::Vector2f(PLAYER_SPEED, 0) * delta;
            commands.push(std::make_unique<game::MovePlayerCommand>(&player, pos, 0, window.getSize().x));
        }

        // perform commands
        while (!commands.empty())
        {
            commands.front()->execute();
            commands.pop();
        }

        // draw
        window.clear();
        window.draw(player);
        window.draw(ball);
        window.display();
    }

    return EXIT_SUCCESS;
}
