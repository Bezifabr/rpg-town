#include <SFML/Graphics.hpp>
#include "UI\Button.h"

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
	title.setPosition(300, 50);


	sf::Text author;
	author.setFont(textFont);
	author.setCharacterSize(35);
	author.setPosition(75, 650);
	author.setString("Bezifabr");

	sf::Text TBC;
	TBC.setFont(textFont);
	TBC.setCharacterSize(35);
	TBC.setPosition(700, 650);
	TBC.setString("To be continued...");

	sf::Texture texture;
	texture.loadFromFile("resources/grass.png");


	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("resources/btnText.png");

	UI::Button btnPlay;
	UI::Button btnLoad;
	UI::Button btnExit;

	btnPlay.setTexture(buttonTexture);
	btnLoad.setTexture(buttonTexture);
	btnExit.setTexture(buttonTexture);

	btnExit.setPosition(350, 400);
	btnExit.setFont(textFont);
	btnExit.setString("Exit");

	btnLoad.setPosition(350, 300);
	btnLoad.setFont(textFont);
	btnLoad.setString("Load");

	btnPlay.setPosition(350, 200);
	btnPlay.setFont(textFont);
	btnPlay.setString("Play");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			btnPlay.update(event, window);
			btnLoad.update(event, window);
			btnExit.update(event, window);
		}

		if (btnExit.isPressed())
			window.close();


		window.clear();
		window.draw(title);
		window.draw(author);
		window.draw(TBC);
		window.draw(btnExit);
		window.draw(btnLoad);
		window.draw(btnPlay);

		window.display();
	}

	return 0;
}