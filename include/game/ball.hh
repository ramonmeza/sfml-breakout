#ifndef BALL_HH
#define BALL_HH

#include <game/game_object.hh>

namespace game
{
    class Ball : public GameObject
    {
    public:
        Ball(const sf::Vector2f &scale, const sf::Vector2f &spawn, const sf::Vector2f &direction, float speed);

        void bounce(const sf::Vector2f &factor);

        const sf::Vector2f &get_direction();
        float get_speed() const;

    private:
        sf::Vector2f direction;
        float speed;
    };
}

#endif // BALL_HH
