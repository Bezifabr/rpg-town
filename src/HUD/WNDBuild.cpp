#include "HUD/WNDBuild.h"

void HUD::WNDBuild::OnInitialize()
{
    optionTXT.loadFromFile("resources/BuildingSlot 64.png");
    changeTXT.loadFromFile("resources/WNDButton.png");

    left.setTexture(changeTXT);
    right.setTexture(changeTXT);

    right.setPosition(convertToWindowPosition(350,400));
    left.setPosition(convertToWindowPosition(25,400));


    buildingPress.setTexture(optionTXT);
    buildingPress.setOriginToCenter();
    buildingPress.setPosition(convertToWindowPosition(100,125));
    buildingPress.loadBuildingTexture("resources/Test/House 64.png");
    buildingPress.setCode("Build_01");
    options.push_back(buildingPress);

    buildingPress.setPosition(convertToWindowPosition(200,125));
    buildingPress.setCode("Build_02");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(convertToWindowPosition(300,125));
    buildingPress.setCode("Build_03");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(convertToWindowPosition(400,125));
    buildingPress.setCode("Build_04");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(convertToWindowPosition(100,225));
    buildingPress.setCode("Build_05");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(convertToWindowPosition(200,225));
    buildingPress.setCode("Build_06");
    options.push_back(buildingPress);

    buildingPress.setPosition(convertToWindowPosition(300,225));
    buildingPress.setCode("Build_07");
    options.push_back(buildingPress);

    buildingPress.setPosition(convertToWindowPosition(400,225));
    buildingPress.setCode("Build_08");
    options.push_back(buildingPress);

    buildingPress.setPosition(convertToWindowPosition(100,325));
    buildingPress.setCode("Build_09");
    options.push_back(buildingPress);
    buildingPress.setPosition(convertToWindowPosition(200,325));
    buildingPress.setCode("Build_10");
    options.push_back(buildingPress);
    buildingPress.setPosition(convertToWindowPosition(300,325));
    buildingPress.setCode("Build_11");
    options.push_back(buildingPress);
    buildingPress.setPosition(convertToWindowPosition(400,325));
    buildingPress.setCode("Build_12");
    options.push_back(buildingPress);
    buildingPress.setPosition(convertToWindowPosition(100,125));
    buildingPress.setCode("Build_13");
    options.push_back(buildingPress);
    buildingPress.setPosition(convertToWindowPosition(200,125));
    buildingPress.setCode("Build_14");
    options.push_back(buildingPress);
}

void HUD::WNDBuild::update()
{

    int limit = maxNumberOfOptions + maxNumberOfOptions * currentPage;

    if(limit > options.size())
        limit = options.size();

    for(int i = currentPage * maxNumberOfOptions; i < limit; i++)
    {
        options[i].update();
    }

    int pagesNumber = options.size()/maxNumberOfOptions;

    if(left.isPressed() && currentPage != 0)
        currentPage--;

    if(right.isPressed() && currentPage != pagesNumber)
        currentPage++;

    left.update();
    right.update();
}

void HUD::WNDBuild::handleEvent(sf::Event& event, sf::Vector2f mousePosition)
{
    int limit = maxNumberOfOptions + maxNumberOfOptions * currentPage;

    if(limit > options.size())
        limit = options.size();

    for(int i = currentPage * maxNumberOfOptions; i < limit; i++)
    {
        options[i].handleEvent(event,mousePosition);
    }

    int pagesNumber = options.size()/maxNumberOfOptions;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
        if(currentPage != pagesNumber)
            currentPage++;
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
        if(currentPage != 0)
            currentPage--;

    left.handleEvent(event,mousePosition);
    right.handleEvent(event,mousePosition);
}

void HUD::WNDBuild::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    int limit = maxNumberOfOptions + maxNumberOfOptions * currentPage;

    if(limit > options.size())
        limit = options.size();

    for(int i = currentPage * maxNumberOfOptions; i < limit; i++)
    {
        target.draw(options[i],states);
    }

    target.draw(left);
    target.draw(right);
}