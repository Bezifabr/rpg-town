#include "HUD/WNDMenu.h"

void HUD::WNDMenu::OnInitialize()
{
    closeBTN.loadFromFile("resources/CloseWindowBTN.png");
    close.setTexture(closeBTN);

	sf::Vector2f closePos = convertToWindowPosition(450, 15);

    close.setPosition(closePos);

    textureBTN.loadFromFile("resources/btnText.png");
    font.loadFromFile("resources/text font.ttf");

    save.setTexture(textureBTN);
    load.setTexture(textureBTN);
    menu.setTexture(textureBTN);
    back.setTexture(textureBTN);

    save.setFont(font);
    load.setFont(font);
    menu.setFont(font);
    back.setFont(font);

    save.setString("Save");
    load.setString("Load");
    menu.setString("Back to menu");
    back.setString("Resume");

    save.setOriginToCenter();
    load.setOriginToCenter();
    menu.setOriginToCenter();
    back.setOriginToCenter();

    // GM1 <=> Game Menu 1
    save.setCode("GM1_save");
    load.setCode("GM1_load");
    menu.setCode("GM1_menu");
    back.setCode("GM1_back");

    save.setPosition(getCenterPosition().x, convertToWindowPosition(200,100).y);
    load.setPosition(getCenterPosition().x, convertToWindowPosition(200,200).y);
    menu.setPosition(getCenterPosition().x, convertToWindowPosition(200,300).y);
    back.setPosition(getCenterPosition().x, convertToWindowPosition(200,400).y);

}

void HUD::WNDMenu::update()
{
    if(close.isPressed())
        setOpened(false);
        
    if(save.isPressed())
        {
            lastActionButton = &save;
            lastButtonPressed = true;
        }
    if(load.isPressed())
        {
            lastActionButton = &load;
            lastButtonPressed = true;
        }
    if(menu.isPressed())
        {
            lastActionButton = &menu;
            lastButtonPressed = true;
        }
    if(back.isPressed())
        {
            lastActionButton = &back;
            lastButtonPressed = true;
        }


    save.update();
    load.update();
    menu.update();
    back.update();
}

void HUD::WNDMenu::handleEvent(sf::Event& event, sf::Vector2f mousePosition)
{
    save.handleEvent(event,mousePosition);
    load.handleEvent(event,mousePosition);
    menu.handleEvent(event,mousePosition);
    back.handleEvent(event,mousePosition); 

    close.handleEvent(event,mousePosition);
}

void HUD::WNDMenu::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(close,states);
    target.draw(save,states);
    target.draw(load,states);
    target.draw(menu,states);
    target.draw(back,states);
}