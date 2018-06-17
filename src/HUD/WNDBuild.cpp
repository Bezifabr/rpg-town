#include "HUD/WNDBuild.h"

void HUD::WNDBuild::OnInitialize()
{
    optionTXT.loadFromFile("resources/BuildingSlot 64.png");
    changeTXT.loadFromFile("resources/btnText.png");

    left.setTexture(changeTXT);
    right.setTexture(changeTXT);

    right.setPosition(convertToWindowPosition(425,400));
    left.setPosition(convertToWindowPosition(25,400));


    test.setTexture(optionTXT);
    test.setOriginToCenter();
    test.setPosition(convertToWindowPosition(100,125));
    test.loadBuildingTexture("resources/Test/House 64.png");
    test.setCode("Build_01");
    options.push_back(test);

    test.setPosition(convertToWindowPosition(200,125));
    test.setCode("Build_02");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(300,125));
    test.setCode("Build_03");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(400,125));
    test.setCode("Build_04");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(100,225));
    test.setCode("Build_05");
    options.push_back(test);
    
    test.setPosition(convertToWindowPosition(200,225));
    test.setCode("Build_06");
    options.push_back(test);

    test.setPosition(convertToWindowPosition(300,225));
    test.setCode("Build_07");
    options.push_back(test);

    test.setPosition(convertToWindowPosition(400,225));
    test.setCode("Build_08");
    options.push_back(test);

    test.setPosition(convertToWindowPosition(100,325));
    test.setCode("Build_09");
    options.push_back(test);
    test.setPosition(convertToWindowPosition(200,325));
    test.setCode("Build_10");
    options.push_back(test);
    test.setPosition(convertToWindowPosition(300,325));
    test.setCode("Build_11");
    options.push_back(test);
    test.setPosition(convertToWindowPosition(400,325));
    test.setCode("Build_12");
    options.push_back(test);
    test.setPosition(convertToWindowPosition(100,125));
    test.setCode("Build_13");
    options.push_back(test);
    test.setPosition(convertToWindowPosition(200,125));
    test.setCode("Build_14");
    options.push_back(test);
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

    if(left.isPressed())
        currentPage--;

    if(right.isPressed())
        currentPage++;
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

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
        currentPage++;
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
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