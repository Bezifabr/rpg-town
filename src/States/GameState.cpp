#include "states/GameState.h"
#include "states/MenuState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void GameState::OnLoad()
{
    hudButtonTexture.loadFromFile("resources/HUDButton.png");

    font.loadFromFile("resources/Text font.ttf");

    btnMenu.setTexture(hudButtonTexture);
    btnMenu.setFont(font);
    btnMenu.setString("Menu");
    btnMenu.setPosition(5,5);

    btnQuests.setTexture(hudButtonTexture);
    btnQuests.setFont(font);
    btnQuests.setString("Missions");
    btnQuests.setPosition(btnMenu.getPosition().x 
    + btnMenu.getGlobalBounds().width + 5 ,5);

    btnStats.setTexture(hudButtonTexture);
    btnStats.setFont(font);
    btnStats.setString("Statistics");
    btnStats.setPosition(btnQuests.getPosition().x
     + btnQuests.getGlobalBounds().width + 5 ,5);

    // Camera Settings
    camera.setCenter(200,200);
    camera.setSize(1000,800);
    statesMachine->setView(camera);

    // Town Settings
    town.addResource("Iron", 1000);
    town.addResource("Wood", 1000);
    town.addResource("Stone", 1000);

    Building build;
    build.loadTexture("resources/Test/House.png");
    build.getTranformable().setPosition(500,500);

    town.addBuilding(build);;

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

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        cout << mousePos.x << " " << mousePos.y << "\n";

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        statesMachine->setCurrent(new MenuState);

    btnMenu.handleEvent(event, mousePos);
    btnQuests.handleEvent(event, mousePos);
    btnStats.handleEvent(event, mousePos);
}

void GameState::OnUpdate()
{
    if(btnMenu.isPressed())
        cout << "Menu window opened" << endl;
    if(btnQuests.isPressed())
        cout << "Missions window opened" << endl;
    if(btnStats.isPressed())
        cout << "Statistics window opened" << endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        camera.move(-5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        camera.move(5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        camera.move(0,-5);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        camera.move(0,5);

    btnMenu.update();
    btnQuests.update();
    btnStats.update();
}


void GameState::Render(sf::RenderTarget& renderTarget)
{
    renderTarget.setView(camera);

    for(auto b : town.getBuildings())
        renderTarget.draw(b.getDrawable());

    renderTarget.setView(renderTarget.getDefaultView());

    renderTarget.draw(btnMenu);
    renderTarget.draw(btnQuests);
    renderTarget.draw(btnStats);
}  


