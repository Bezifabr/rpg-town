#ifndef HUD_WINDOW_MENU_H
#define HUD_WINDOW_MENU_H

#include "Window.h"
#include "Button.h"

namespace HUD
{
    class WNDMenu : public Window
    {

        sf::Texture closeBTN;
        HUD::Button close;

        sf::Texture textureBTN;
        sf::Font font;
        HUD::Button save;
        HUD::Button load;
        HUD::Button options;
        HUD::Button menu;
        HUD::Button back;

    public:
		virtual void update();
		virtual void handleEvent(sf::Event& event, sf::Vector2f mousePosition);
    private:
         virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const;
         virtual void OnInitialize();
    };
}


#endif // ! HUD_WINDOW_MENU_H