#ifndef BUILDING_ICON_H
#define BUILDING_ICON_H

#include "HUD/Button.h"

namespace HUD
{
    class BuildingIcon : public HUD::Button
    {
        sf::Sprite graphic;
        sf::Texture texture;

    public:
        void loadBuildingTexture(const std::string& source);

    private:
        virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setBuildingPosition();
    };
}

#endif // ! BUILDING_ICON_H