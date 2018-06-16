#include "HUD/WNDBuild.h"

void HUD::WNDBuild::OnInitialize()
{
    textureBTN.loadFromFile("resources/BuildingSlot 64.png");

    test.setTexture(textureBTN);
    test.setOriginToCenter();
    test.setPosition(convertToWindowPosition(100,150));
    test.loadBuildingTexture("resources/Test/House 64.png");
    test.setCode("Build_01");
    options.push_back(test);

    test.setPosition(convertToWindowPosition(200,150));
    test.setCode("Build_02");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(300,150));
    test.setCode("Build_03");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(400,150));
    test.setCode("Build_04");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(100,250));
    test.setCode("Build_05");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(200,250));
    test.setCode("Build_06");
    options.push_back(test);

    test.setPosition(convertToWindowPosition(300,250));
    test.setCode("Build_06");
    options.push_back(test);
}

void HUD::WNDBuild::update()
{
 //   test.update();

    for(auto option : options)
    {
        option.update();
    }
}

void HUD::WNDBuild::handleEvent(sf::Event& event, sf::Vector2f mousePosition)
{
  //  test.handleEvent(event,mousePosition);

    for(auto option: options)
    {
        option.handleEvent(event,mousePosition);
    }
}

void HUD::WNDBuild::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(test,states);
    
    for(auto option: options)
    {
        target.draw(option,states);
    }
}