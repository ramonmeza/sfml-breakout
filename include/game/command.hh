#ifndef COMMAND_HH
#define COMMAND_HH

#include <game/game_object.hh>

namespace game
{
    class Command
    {
    public:
        Command(GameObject *object);
        virtual ~Command();
        virtual void execute() = 0;

    protected:
        GameObject *object;
    };
}

#endif // COMMAND_HH
