#ifndef VIEW_MANAGER_H
#define VIEW_MANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>

class ViewManager
{
    sf::RenderWindow* window;

public:
    void ConnectWithRenderWindow(sf::RenderWindow& rWindow);

	void SetView(const sf::View& view);
	sf::Vector2f ConvertToCoordinate(sf::Vector2i position);
	sf::Vector2i ConvertToPixels(sf::Vector2f position);

	void SetDefaultView();
    
};

#endif // VIEW_MANAGER_H