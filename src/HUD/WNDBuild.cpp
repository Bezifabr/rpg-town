#include "HUD/WNDBuild.h"

void HUD::WNDBuild::OnInitialize()
{
    optionTXT.loadFromFile("resources/BuildingSlot 64.png");
    changeTXT.loadFromFile("resources/WNDButton.png");

    left.setTexture(changeTXT);
    right.setTexture(changeTXT);

    right.setPosition(ConvertToWindowPosition(350,400));
    left.setPosition(ConvertToWindowPosition(25,400));


    buildingPress.setTexture(optionTXT);
    buildingPress.setOriginToCenter();
    buildingPress.setPosition(ConvertToWindowPosition(100,125));
    buildingPress.LoadBuildingTexture("resources/Test/House 64.png");
    buildingPress.SetCode("Build_01");
    options.push_back(buildingPress);

    buildingPress.setPosition(ConvertToWindowPosition(200,125));
    buildingPress.SetCode("Build_02");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(ConvertToWindowPosition(300,125));
    buildingPress.SetCode("Build_03");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(ConvertToWindowPosition(400,125));
    buildingPress.SetCode("Build_04");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(ConvertToWindowPosition(100,225));
    buildingPress.SetCode("Build_05");
    options.push_back(buildingPress);
    
    buildingPress.setPosition(ConvertToWindowPosition(200,225));
    buildingPress.SetCode("Build_06");
    options.push_back(buildingPress);

    buildingPress.setPosition(ConvertToWindowPosition(300,225));
    buildingPress.SetCode("Build_07");
    options.push_back(buildingPress);

    buildingPress.setPosition(ConvertToWindowPosition(400,225));
    buildingPress.SetCode("Build_08");
    options.push_back(buildingPress);

    buildingPress.setPosition(ConvertToWindowPosition(100,325));
    buildingPress.SetCode("Build_09");
    options.push_back(buildingPress);
    buildingPress.setPosition(ConvertToWindowPosition(200,325));
    buildingPress.SetCode("Build_10");
    options.push_back(buildingPress);
    buildingPress.setPosition(ConvertToWindowPosition(300,325));
    buildingPress.SetCode("Build_11");
    options.push_back(buildingPress);
    buildingPress.setPosition(ConvertToWindowPosition(400,325));
    buildingPress.SetCode("Build_12");
    options.push_back(buildingPress);
    buildingPress.setPosition(ConvertToWindowPosition(100,125));
    buildingPress.SetCode("Build_13");
    options.push_back(buildingPress);
    buildingPress.setPosition(ConvertToWindowPosition(200,125));
    buildingPress.SetCode("Build_14");
    options.push_back(buildingPress);
}

void HUD::WNDBuild::Update()
{

    int limit = maxNumberOfOptions + maxNumberOfOptions * currentPage;

    if(limit > options.size())
        limit = options.size();

    for(int i = currentPage * maxNumberOfOptions; i < limit; i++)
    {
        options[i].Update();
    }

    int pagesNumber = options.size()/maxNumberOfOptions;

    if(left.IsPressed() && currentPage != 0)
        currentPage--;

    if(right.IsPressed() && currentPage != pagesNumber)
        currentPage++;

    left.Update();
    right.Update();
}

void HUD::WNDBuild::HandleEvent(sf::Event& event, sf::Vector2f mousePosition)
{
    int limit = maxNumberOfOptions + maxNumberOfOptions * currentPage;

    if(limit > options.size())
        limit = options.size();

    for(int i = currentPage * maxNumberOfOptions; i < limit; i++)
    {
        options[i].HandleEvent(event,mousePosition);
    }

    int pagesNumber = options.size()/maxNumberOfOptions;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
        if(currentPage != pagesNumber)
            currentPage++;
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
        if(currentPage != 0)
            currentPage--;

    left.HandleEvent(event,mousePosition);
    right.HandleEvent(event,mousePosition);
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