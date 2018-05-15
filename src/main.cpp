#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "RPG Town project");
	window.setFramerateLimit(60);
	
	sf::Font titleFont;
	sf::Font textFont;
	titleFont.loadFromFile("resources/Title font.ttf");
	textFont.loadFromFile("resources/Text font.ttf");

	sf::Text title;
	title.setFont(titleFont);
	title.setCharacterSize(60);
	title.setStyle(sf::Text::Bold);
	title.setString("RPG Town project");
	title.setPosition(300, 200);

	sf::Text desc;
	desc.setFont(textFont);
	desc.setCharacterSize(35);
	desc.setString("This is the very first screen of this project.\n It will appear until I will add some graphics");
	desc.setPosition(250, 275);

	sf::Text author;
	author.setFont(textFont);
	author.setCharacterSize(35);
	author.setPosition(700, 25);
	author.setString("Bezifabr");

	sf::Text TBC;
	author.setFont(textFont);
	TBC.setCharacterSize(35);
	author.setPosition(700, 650);
	author.setString("To be continued...");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(title);
		window.draw(desc);
		window.draw(author);
		window.draw(TBC);
		window.display();
	}

	return 0;
}