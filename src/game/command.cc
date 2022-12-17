#include <game/command.hh>

using namespace game;

Command::Command(GameObject *object) : object(object) {}
Command::~Command() {}
