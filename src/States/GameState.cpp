#include "states/GameState.h"
#include "states/MenuState.h"
#include "StateTransition.h"
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
    view->SetView(camera);

    // Town Settings
    town.AddResource("Iron", 1000);
    town.AddResource("Wood", 1000);
    town.AddResource("Stone", 1000);

    Building build;
    build.LoadTexture("resources/Test/House.png");
    build.GetTranformable().setPosition(400,375);

    town.AddBuilding(build);


    cout << "Game loaded" << endl;
}

void GameState::OnUnload()
{
    cout << "Game unloaded" << endl;
}

void GameState::HandleEvent(sf::Event event, const sf::Window& window)
{
    sf::Vector2f globalMousePos = view->ConvertToCoordinate(sf::Mouse::getPosition(window));
    sf::Vector2f localMousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
       {
            cout << localMousePos.x << ", " << localMousePos.y << "\n";
            cout << globalMousePos.x << " " << globalMousePos.y << "\n";
       }

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        {
            if(windowOpened == false)
                transition->Switch(std::shared_ptr<State>(new MenuState));
            else
                CloseWindow();
        }

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
    {
        currentWindow = new HUD::WNDBuild;
        currentWindow->Initialize();
        windowOpened = true;
    }

    btnMenu.HandleEvent(event, localMousePos);
    btnQuests.HandleEvent(event, localMousePos);
    btnStats.HandleEvent(event, localMousePos);

    if(windowOpened)
        currentWindow->HandleEvent(event,localMousePos);
}

void GameState::OnUpdate()
{
    if(btnMenu.IsPressed())
        {
            currentWindow = new HUD::WNDMenu;
            currentWindow->Initialize();
            windowOpened = true;
        }
    
    if(btnQuests.IsPressed())
        cout << "Missions window opened" << endl;
    if(btnStats.IsPressed())
        cout << "Statistics window opened" << endl;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        camera.move(-5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        camera.move(5,0);

    btnMenu.Update(deltaTime);
    btnQuests.Update(deltaTime);
    btnStats.Update(deltaTime);

    if(currentWindow)
        {
            currentWindow->Update(deltaTime);

            if(currentWindow->IsOpened() == false)
                CloseWindow();

            if(currentWindow->IsButtonPressed())
                {
                    cout << currentWindow->GetPressedButtonCode() << endl;
                    CheckCodes(currentWindow->GetPressedButtonCode());
                }
        }


}


void GameState::Render(sf::RenderTarget& renderTarget)
{
    renderTarget.setView(camera);

    for(auto b : town.GetBuildings())
        renderTarget.draw(b.GetDrawable());

    renderTarget.setView(renderTarget.getDefaultView());

    renderTarget.draw(topBar);

    renderTarget.draw(btnMenu);
    renderTarget.draw(btnQuests);
    renderTarget.draw(btnStats);

    if(windowOpened)
        renderTarget.draw((*currentWindow));

    renderTarget.setView(camera);
}  


void GameState::CloseWindow()
{
    delete currentWindow;
    currentWindow = nullptr;
    windowOpened = false;
}

void GameState::CheckCodes(std::string code)
{    
    if(code == "GM1_back")
        currentWindow->SetOpened(false);
    if(code == "GM1_menu")
        transition->Switch(std::shared_ptr<State>(new MenuState));
}