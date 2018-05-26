#include "HUD/Window.h"
#include <iostream>

using std::cout;
using std::endl;

void HUD::Window::initialize()
{
    setBackground("resources/ingameWindow.png"); 
    background.setOrigin(
    background.getGlobalBounds().left + background.getGlobalBounds().width/2.0f, 
    background.getGlobalBounds().top + background.getGlobalBounds().height / 2.0f
    );
    background.setPosition(500,400);
    opened = true;
    OnInitialize();
}

void HUD::Window::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(background);
    OnDraw(target, states);
} 

void HUD::Window::setBackground(const std::string& source)
{
    texture.loadFromFile(source);
    background.setTexture(texture);
}

sf::Vector2f HUD::Window::convertToWindowPosition(sf::Vector2f position)
{
    return convertToWindowPosition(position.x, position.y);
}

sf::Vector2f HUD::Window::convertToWindowPosition(float posX, float posY)
{
    sf::Vector2f basePos = 
    sf::Vector2f(background.getGlobalBounds().left, background.getGlobalBounds().top);

    return sf::Vector2f(basePos.x + posX, basePos.y + posY);
}

bool HUD::Window::isOpened()
{
    return opened;
}

void HUD::Window::setOpened(bool value)
{
    this->opened = value;
}

sf::Vector2f HUD::Window::getCenterPosition()
{
    return sf::Vector2f(
        background.getGlobalBounds().left + background.getGlobalBounds().width/2,
        background.getGlobalBounds().top + background.getGlobalBounds().height/2);
}

std::map<std::string, bool> HUD::Window::isPressed()
{
    std::map<std::string, bool> m1;
    
    for(auto x: buttons)
    {
        m1[x.first] = buttons[x.first].isPressed();
    }

    if(m1.size() <= 0)
        cout << "Error: Window.cpp isPressed() //m1 is empty" << endl;

    return m1;
}