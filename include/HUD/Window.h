#ifndef HUD_WINDOW_H
#define HUD_WINDOW_H

#include <SFML/Graphics.hpp>
#include <map>
#include "HUD/Button.h"

namespace HUD
{

    class Window : public sf::Drawable
    {
        bool opened;
        sf::Sprite background;
        sf::Texture texture;
    public:

        void setBackground(const std::string& source);

		virtual void update() = 0;
		virtual void handleEvent(sf::Event& event, sf::Vector2f mousePosition) = 0;
        void initialize();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool isOpened();
        void setOpened(bool value);

    protected:

        
        virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
        virtual void OnInitialize() = 0;

        sf::Vector2f convertToWindowPosition(sf::Vector2f position);
        sf::Vector2f convertToWindowPosition(float posX, float posY);

        sf::Vector2f getCenterPosition();
    };

}

#endif // !HUD_WINDOW_H