#include "Menu.h"


Menu::Menu() {

	getFiles();
	setColors();
	setTexts();
}

void Menu::getFiles() {

	mainfont.loadFromFile("Fonts/Anja_Eliane.ttf");
	start.loadFromFile("Images/2048.png");
	menu1.setTexture(start);
	menu1.setPosition(100, 125);
}

void Menu::setTexts() {

    text1 = { "", mainfont, 50 };
	text1.setString("Hello! Welcome to ");
	text1.setPosition(50, 35);
	text1.setFillColor(Yellow);

	text2 = { "", mainfont, 30 };
	text2.setString("|  New Game |");
	text2.setPosition(70, 340);
	text2.setFillColor(Pink);
	text2.setStyle(sf::Text::Italic);
	                                                                                                                             
	text3 = { "", mainfont, 30 };
	text3.setString("|  Record  |");
	text3.setPosition(250, 400);
	text3.setFillColor(Blue);
	text3.setStyle(sf::Text::Italic);

	text4 = { "", mainfont, 30 };
	text4.setString("|  Exit  |");
	text4.setPosition(380, 340);
	text4.setFillColor(Yellow);
	text4.setStyle(sf::Text::Italic);

}

void Menu::setColors() {

	Pink = { 227, 52, 110 };
	Blue = { 22, 147, 219 };
	Yellow = { 219, 154, 55 };
	LightPink = { 235, 152, 161 };
	LightBlue = { 166, 184, 255 };
	LightYellow = { 255, 245, 107 };
}

void Menu::mouseWork(sf::RenderWindow &window) {

	
	int menuNumb = 0;
	bool menu=true;
	
	while (menu) {
		if (sf::IntRect(70, 340, 230, 40).contains(sf::Mouse::getPosition(window))) {
			text2.setFillColor(LightPink);
			menuNumb = 1;
		}

		if (sf::IntRect(380, 340, 150, 40).contains(sf::Mouse::getPosition(window))) {
			text4.setFillColor(LightYellow);
			menuNumb = 3;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (menuNumb == 1) { menu = false;/* Game(window, LightPink);*/ }
			if (menuNumb == 3)  window.close();
		}
		draw(window);
	}
}


void Menu::draw(sf::RenderWindow &window) {

	window.draw(menu1);
	window.draw(text1);
	window.draw(text2);
	window.draw(text4);
	window.display();
}



Menu::~Menu()
{
}
