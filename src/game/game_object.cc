#include <game/game_object.hh>

using namespace game;

GameObject::GameObject(const std::string &path, const sf::Vector2f &scale, const sf::Vector2f &spawn)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);

    sprite.scale(scale);
    sprite.setPosition(spawn);
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

const sf::Vector2f &GameObject::get_position() const
{
    return sprite.getPosition();
}

void GameObject::set_position(const sf::Vector2f &position)
{
    sprite.setPosition(position);
}

sf::FloatRect GameObject::get_size() const
{
    return sprite.getLocalBounds();
}
