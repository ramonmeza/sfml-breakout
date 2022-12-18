#include <game/move_ball_command.hh>

using namespace game;

MoveBallCommand::MoveBallCommand(Ball *object, const sf::Vector2u &size, float delta) : Command(object)
{
    this->delta = delta;
    this->size = size;
}

void MoveBallCommand::execute()
{
    auto ball = dynamic_cast<Ball *>(object);
    auto pos = object->get_position();

    // bounce
    if (pos.x < 0 || pos.x > size.x - ball->get_size().width)
    {
        ball->bounce(sf::Vector2f(-1, 1));
    }
    if (pos.y < 0 || pos.y > size.y - ball->get_size().height)
    {
        ball->bounce(sf::Vector2f(1, -1));
    }

    // update position
    auto next_pos = pos + (ball->get_speed() * ball->get_direction() * delta);
    ball->set_position(next_pos);
}
