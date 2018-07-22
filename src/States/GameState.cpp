#include "states/GameState.h"
#include "states/MenuState.h"
#include "StatesMachine.h"
#include "HUD/WNDMenu.h"
#include "HUD/WNDBuild.h"
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
    btnMenu.setPosition(5,1);

    btnQuests.setTexture(hudButtonTexture);
    btnQuests.setFont(font);
    btnQuests.setString("Missions");
    btnQuests.setPosition(btnMenu.getPosition().x 
    + btnMenu.getGlobalBounds().width +1,1);

    btnStats.setTexture(hudButtonTexture);
    btnStats.setFont(font);
    btnStats.setString("Statistics");
    btnStats.setPosition(btnQuests.getPosition().x
     + btnQuests.getGlobalBounds().width +1,1);

    topBarTexture.loadFromFile("resources/Top Bar.png");
    topBar.setTexture(topBarTexture);

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
    build.getTranformable().setPosition(400,375);

    town.addBuilding(build);


    cout << "Game loaded" << endl;
}

void GameState::OnUnload()
{
    cout << "Game unloaded" << endl;
}

void GameState::HandleEvent(sf::Event event, const sf::Window& window)
{
    sf::Vector2f globalMousePos = statesMachine->ConvertToCoordinate(sf::Mouse::getPosition(window));
    sf::Vector2f localMousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
       {
            cout << localMousePos.x << ", " << localMousePos.y << "\n";
            cout << globalMousePos.x << " " << globalMousePos.y << "\n";
       }

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        {
            if(windowOpened == false)
                statesMachine->setCurrent(std::shared_ptr<State>(new MenuState));
            else
                m_CloseWindow();
        }

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
    {
        currentWindow = new HUD::WNDBuild;
        currentWindow->initialize();
        windowOpened = true;
    }

    btnMenu.handleEvent(event, localMousePos);
    btnQuests.handleEvent(event, localMousePos);
    btnStats.handleEvent(event, localMousePos);

    if(windowOpened)
        currentWindow->handleEvent(event,localMousePos);
}

void GameState::OnUpdate()
{
    if(btnMenu.isPressed())
        {
            currentWindow = new HUD::WNDMenu;
            currentWindow->initialize();
            windowOpened = true;
        }
    
    if(btnQuests.isPressed())
        cout << "Missions window opened" << endl;
    if(btnStats.isPressed())
        cout << "Statistics window opened" << endl;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        camera.move(-5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        camera.move(5,0);

    btnMenu.update();
    btnQuests.update();
    btnStats.update();

    if(currentWindow)
        {
            currentWindow->update();

            if(currentWindow->isButtonPressed())
                {
                    cout << currentWindow->getPressedButtonCode() << endl;
                    m_CheckCodes(currentWindow->getPressedButtonCode());
                }

            if(currentWindow->isOpened() == false)
                m_CloseWindow();
        }


}


void GameState::Render(sf::RenderTarget& renderTarget)
{
    renderTarget.setView(camera);

    for(auto b : town.getBuildings())
        renderTarget.draw(b.getDrawable());

    renderTarget.setView(renderTarget.getDefaultView());

    renderTarget.draw(topBar);

    renderTarget.draw(btnMenu);
    renderTarget.draw(btnQuests);
    renderTarget.draw(btnStats);

    if(windowOpened)
        renderTarget.draw((*currentWindow));

    renderTarget.setView(camera);
}  


void GameState::m_CloseWindow()
{
    delete currentWindow;
    currentWindow = nullptr;
    windowOpened = false;
}

void GameState::m_CheckCodes(std::string code)
{    
    if(code == "GM1_back")
        currentWindow->setOpened(false);
    if(code == "GM1_menu")
        statesMachine->setCurrent(std::shared_ptr<State>(new MenuState));
}