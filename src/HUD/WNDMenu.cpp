#include "HUD/WNDMenu.h"

void HUD::WNDMenu::OnInitialize()
{
    closeBTN.loadFromFile("resources/CloseWindowBTN.png");
    close.setTexture(closeBTN);

	sf::Vector2f closePos = ConvertToWindowPosition(450, 15);

    close.setPosition(closePos);

    textureBTN.loadFromFile("resources/MenuButton.png");
    font.loadFromFile("resources/Text font.ttf");

    save.setTexture(textureBTN);
    load.setTexture(textureBTN);
    menu.setTexture(textureBTN);
    back.setTexture(textureBTN);
    options.setTexture(textureBTN);

    save.setFont(font);
    load.setFont(font);
    menu.setFont(font);
    back.setFont(font);
    options.setFont(font);

    save.setString("Save");
    load.setString("Load");
    menu.setString("Back to menu");
    back.setString("Resume");
    options.setString("Options");

    save.setOriginToCenter();
    load.setOriginToCenter();
    menu.setOriginToCenter();
    back.setOriginToCenter();
    options.setOriginToCenter();

    // GM1 <=> Game Menu 1
    save.SetCode("GM1_save");
    load.SetCode("GM1_load");
    menu.SetCode("GM1_menu");
    back.SetCode("GM1_back");
    options.SetCode("GM1_options");

    save.setPosition(GetCenterPosition().x, ConvertToWindowPosition(200,100).y);
    load.setPosition(GetCenterPosition().x, ConvertToWindowPosition(200,175).y);
    options.setPosition(GetCenterPosition().x, ConvertToWindowPosition(200,250).y);
    menu.setPosition(GetCenterPosition().x, ConvertToWindowPosition(200,325).y);
    back.setPosition(GetCenterPosition().x, ConvertToWindowPosition(200,400).y);

}

void HUD::WNDMenu::Update()
{
    if(close.IsPressed())
        SetOpened(false);
        
    if(save.IsPressed())
        {
            lastActionButton = &save;
            lastButtonPressed = true;
        }
    if(load.IsPressed())
        {
            lastActionButton = &load;
            lastButtonPressed = true;
        }
    if(menu.IsPressed())
        {
            lastActionButton = &menu;
            lastButtonPressed = true;
        }
    if(back.IsPressed())
        {
            lastActionButton = &back;
            lastButtonPressed = true;
        }
    if(options.IsPressed())
        {
            lastActionButton = &options;
            lastButtonPressed = true;
        }


    save.Update();
    load.Update();
    menu.Update();
    back.Update();
    options.Update();
}

void HUD::WNDMenu::HandleEvent(sf::Event& event, sf::Vector2f mousePosition)
{
    save.HandleEvent(event,mousePosition);
    load.HandleEvent(event,mousePosition);
    menu.HandleEvent(event,mousePosition);
    back.HandleEvent(event,mousePosition); 
    options.HandleEvent(event,mousePosition); 

    close.HandleEvent(event,mousePosition);
}

void HUD::WNDMenu::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(close,states);
    target.draw(save,states);
    target.draw(load,states);
    target.draw(menu,states);
    target.draw(back,states);
    target.draw(options,states);
}