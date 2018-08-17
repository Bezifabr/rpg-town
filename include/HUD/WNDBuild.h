#ifndef WND_BUILD_H
#define WND_BUILD_H

#include "Window.h"
#include "HUD/BuildingIcon.h"
#include <vector>

namespace HUD
{
    class WNDBuild : public Window
    {
        int maxNumberOfOptions = 10;
        int currentPage = 0;

        sf::Texture closeTXT;
        HUD::Button close;

        sf::Texture optionTXT;
        sf::Font font;

        sf::Texture changeTXT;
        HUD::Button right;
        HUD::Button left;

        HUD::BuildingIcon buildingPress;

        std::vector<HUD::BuildingIcon> options;

        public:
	    	virtual void Update(sf::Time deltaTime) override;
	    	virtual void HandleEvent(sf::Event& event, sf::Vector2f mousePosition) override;
        private:
            virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
            virtual void OnInitialize() override;

    };
}

#endif // ! WND_BUILD_H