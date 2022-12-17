#include <game/move_player_command.hh>

using namespace game;

MovePlayerCommand::MovePlayerCommand(GameObject *object, const sf::Vector2f &delta, float min_x, float max_x) : Command(object), delta(delta)
{
    this->min_x = min_x;
    this->max_x = max_x;
}

void MovePlayerCommand::execute()
{
    auto pos = object->get_position();

    if (pos.x > min_x && pos.x < max_x)
    {
        object->set_position(pos + delta);
    }

    if (pos.x < min_x)
    {
        object->set_position(sf::Vector2f(min_x + 1, pos.y));
    }
    else if (pos.x > max_x - object->get_size().width)
    {
        object->set_position(sf::Vector2f(max_x - object->get_size().width - 1, pos.y));
    }
}
