#ifndef GAME_OBJECT_HH
#define GAME_OBJECT_HH

#include <SFML/Graphics.hpp>

namespace game
{
    class GameObject : public sf::Drawable
    {
    public:
        GameObject(const std::string &path, const sf::Vector2f &scale, const sf::Vector2f &spawn);

        const sf::Vector2f &get_position() const;
        void set_position(const sf::Vector2f &position);
        sf::FloatRect get_size() const;

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        sf::Texture texture;
        sf::Sprite sprite;
    };
}

#endif // GAME_OBJECT_HH
