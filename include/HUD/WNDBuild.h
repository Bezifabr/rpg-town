#ifndef WND_BUILD_H
#define WND_BUILD_H

#include "Window.h"
#include "HUD/BuildingIcon.h"
#include <vector>

namespace HUD
{
    class WNDBuild : public Window
    {
        sf::Texture closeBTN;
        HUD::Button close;

        sf::Texture textureBTN;
        sf::Font font;

        HUD::BuildingIcon test;

        std::vector<HUD::BuildingIcon> options;

        public:
	    	virtual void update();
	    	virtual void handleEvent(sf::Event& event, sf::Vector2f mousePosition);
        private:
            virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const;
            virtual void OnInitialize();

    };
}

#endif // ! WND_BUILD_H