#ifndef MOVE_PLAYER_COMMAND_HH
#define MOVE_PLAYER_COMMAND_HH

#include <game/command.hh>
#include <game/player.hh>

namespace game
{
    class MovePlayerCommand : public Command
    {
    public:
        MovePlayerCommand(Player *object, const sf::Vector2f &delta, float min_x, float max_x);
        virtual void execute() override;

    private:
        sf::Vector2f delta;
        float min_x;
        float max_x;
    };
}

#endif // MOVE_PLAYER_COMMAND_HH
