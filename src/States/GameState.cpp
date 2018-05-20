#include "states/GameState.h"
#include "states/MenuState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void GameState::OnLoad()
{
    texture.loadFromFile("resources/btnText.png");

    font.loadFromFile("resources/Text font.ttf");

    exit.setTexture(texture);
    exit.setFont(font);
    exit.setString("Close game");
    exit.setPosition(50,50);

    // Camera Settings
   // camera.setViewport(sf::FloatRect(0,0,1000,800));
    camera.setCenter(200,200);
    camera.setSize(1000,800);
    statesMachine->setView(camera);

    cout << "Game loaded" << endl;
}

void GameState::OnUnload()
{
    cout << "Game unloaded" << endl;
}

void GameState::HandleEvent(sf::Event event, const sf::Window& window)
{
    sf::Vector2f mousePos = 
    statesMachine->ConvertToCoordinate(sf::Mouse::getPosition(window));


    exit.handleEvent(event, mousePos);
}

void GameState::OnUpdate()
{
    if(exit.isPressed())
        statesMachine->setCurrent(new MenuState);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        camera.move(-5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        camera.move(5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        camera.move(0,-5);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        camera.move(0,5);

    exit.update();
}


void GameState::Render(sf::RenderTarget& renderTarget)
{
    renderTarget.setView(camera);
    renderTarget.draw(exit);
}  


