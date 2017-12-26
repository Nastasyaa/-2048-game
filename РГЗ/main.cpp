#include "Menu.h"
#include "Game.h"
#include <windows.h>


bool StartGame(sf::RenderWindow &window) {
	
	Game game;
	game.GenerateRandom();
	game.GenerateRandom();
	game.GameRes(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{  
			   if (event.type == sf::Event::Closed)
				window.close();
		}
		if (event.type == sf::Event::Resized) {
			window.setSize(sf::Vector2u(600, 500));
			game.GameRes(window);
		}
		int menuNumb = 0;
		if (sf::IntRect(410, 430, 300, 40).contains(sf::Mouse::getPosition(window))) {
			menuNumb = 1;
		}
		if (sf::IntRect(350, 30, 100, 50).contains(sf::Mouse::getPosition(window))) {
			menuNumb = 2;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (menuNumb == 1) {
				window.close();
			    return false;
			}
			if (menuNumb == 2)
				return false;
		}

		if ((game.UserStep(window) == 1)) {
			game.GameRes(window);
			game.GenerateRandom();
			game.GameRes(window);
		}
		int k= game.CheckGrid(window);
		Sleep(100);
	}
	return true;
}


void Start(sf::RenderWindow &window) {

	if (StartGame(window) == false)
		Start(window);
}


int CALLBACK WinMain(HINSTANCE hInsgtance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	sf::RenderWindow window(sf::VideoMode(600, 500), "2048 game");
	Menu MENU;
	MENU.mouseWork(window);
	Start(window);
	}
