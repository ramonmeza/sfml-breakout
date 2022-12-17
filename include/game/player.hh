#ifndef PLAYER_HH
#define PLAYER_HH

#include <game/game_object.hh>

namespace game
{
    class Player : public GameObject
    {
    public:
        Player(const sf::Vector2f &scale, const sf::Vector2f &spawn);
    };
}

#endif // PLAYER_HH
