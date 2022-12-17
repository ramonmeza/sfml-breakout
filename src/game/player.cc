#include <game/player.hh>

using namespace game;

Player::Player(const sf::Vector2f &scale, const sf::Vector2f &spawn) : GameObject("data/textures/player.png", scale, spawn)
{
}
