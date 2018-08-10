#include "ViewManager.h"

void ViewManager::ConnectWithRenderWindow(sf::RenderWindow& rWindow)
{
    window = &rWindow;
}

void ViewManager::setView(const sf::View& view)
{
    window->setView(view);
}

sf::Vector2f ViewManager::ConvertToCoordinate(sf::Vector2i position)
{
    return window->mapPixelToCoords(position, window->getView());
}

sf::Vector2i ViewManager::ConvertToPixels(sf::Vector2f position)
{
    return window->mapCoordsToPixel(position);
}

void ViewManager::SetDefaultView()
{
    window->setView(window->getDefaultView());
}