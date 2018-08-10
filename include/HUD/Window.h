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

		void Initialize();
        void SetBackground(const std::string& source);

		virtual void Update() = 0;
		virtual void HandleEvent(sf::Event& event, sf::Vector2f mousePosition) = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool IsOpened();
        void SetOpened(bool value);

        bool IsButtonPressed();
        std::string GetPressedButtonCode();
    protected:
        bool lastButtonPressed = false;
        HUD::Button* lastActionButton;
        
        virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
        virtual void OnInitialize() = 0;

        sf::Vector2f ConvertToWindowPosition(sf::Vector2f position);
        sf::Vector2f ConvertToWindowPosition(float posX, float posY);

        sf::Vector2f GetCenterPosition();
    };

}

#endif // !HUD_WINDOW_H