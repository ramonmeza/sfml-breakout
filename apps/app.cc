#include <iostream>
#include <memory>
#include <queue>

#include <INIReader.h>
#include <SFML/Graphics.hpp>

#include <game/ball.hh>
#include <game/command.hh>
#include <game/move_ball_command.hh>
#include <game/move_player_command.hh>
#include <game/player.hh>
#include <utils/console.hh>

using namespace game;
using namespace sf;
using namespace std;
using namespace utils;

const Keyboard::Key MOVE_LEFT = Keyboard::Left;
const Keyboard::Key MOVE_RIGHT = Keyboard::Right;

int main(int argc, char *argv[])
{
    cout << "Ready to play some " << console::colorize("Breakout", console::ForegroundColor::Red, console::BackgroundColor::White, console::FormatAttribute::Bold, console::ResetFormatAttribute::All) << "?" << endl;

    INIReader ini("data/config.ini");

    RenderWindow window(VideoMode(ini.GetInteger("window", "width", 800), ini.GetInteger("window", "height", 600)), "SFML Breakout");

    auto ball_scale = Vector2f(ini.GetFloat("ball", "scale", 1), ini.GetFloat("ball", "scale", 1));
    auto ball_spawn = Vector2f(ini.GetFloat("ball.position", "x", 0), ini.GetFloat("ball.position", "y", 0));
    auto ball_direction = Vector2f(1, 1);
    auto ball_speed = ini.GetFloat("ball", "speed", 400);
    Ball ball(ball_scale, ball_spawn, ball_direction, ball_speed);

    const float PLAYER_SPEED = ini.GetFloat("player", "speed", 600);
    auto player_scale = Vector2f(ini.GetFloat("player", "scale", 1), ini.GetFloat("player", "scale", 1));
    auto player_spawn = Vector2f(ini.GetFloat("player.position", "x", 0), ini.GetFloat("player.position", "y", 0));
    Player player(player_scale, player_spawn);

    queue<unique_ptr<Command>> commands;

    Clock clock;
    while (window.isOpen())
    {
        float delta = clock.getElapsedTime().asSeconds();
        clock.restart();

        // handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // update player
        if (Keyboard::isKeyPressed(MOVE_LEFT))
        {
            auto pos = Vector2f(-PLAYER_SPEED, 0) * delta;
            commands.push(make_unique<MovePlayerCommand>(&player, pos, 0, window.getSize().x));
        }
        if (Keyboard::isKeyPressed(MOVE_RIGHT))
        {
            auto pos = Vector2f(PLAYER_SPEED, 0) * delta;
            commands.push(make_unique<MovePlayerCommand>(&player, pos, 0, window.getSize().x));
        }

        // update ball
        commands.push(make_unique<MoveBallCommand>(&ball, window.getSize(), delta));

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
