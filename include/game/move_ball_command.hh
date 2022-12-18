#ifndef MOVE_BALL_COMMAND_HH
#define MOVE_BALL_COMMAND_HH

#include <game/command.hh>
#include <game/ball.hh>

namespace game
{
    class MoveBallCommand : public Command
    {
    public:
        MoveBallCommand(Ball *object, const sf::Vector2u &size, float delta);
        virtual void execute() override;

    private:
        float delta;
        sf::Vector2u size;
    };
}

#endif // MOVE_BALL_COMMAND_HH
