#ifndef HUD_WINDOW_MENU_H
#define HUD_WINDOW_MENU_H

#include "Window.h"

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
		virtual void Update(sf::Time deltaTime) override;
		virtual void HandleEvent(sf::Event& event, sf::Vector2f mousePosition) override;
    private:
         virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
         virtual void OnInitialize() override;
    };
}


#endif // ! HUD_WINDOW_MENU_H