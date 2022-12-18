#include <game/ball.hh>

using namespace game;

Ball::Ball(const sf::Vector2f &scale, const sf::Vector2f &spawn, const sf::Vector2f &direction, float speed) : GameObject("data/textures/ball.png", scale, spawn)
{
    this->direction = direction;
    this->speed = speed;
}

void Ball::bounce(const sf::Vector2f &factor)
{
    direction.x *= factor.x;
    direction.y *= factor.y;
}

const sf::Vector2f &Ball::get_direction()
{
    return direction;
}

float Ball::get_speed() const
{
    return speed;
}
