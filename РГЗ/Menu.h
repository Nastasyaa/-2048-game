#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

//using namespace sf;


class Menu
{
	sf::Texture start;
	sf::Font mainfont;
	sf::Text text1, text2, text3, text4;
	sf::Sprite menu1;
	sf::Color Pink, Blue, Yellow, LightPink, LightBlue, LightYellow;
	sf::SoundBuffer buffer;
	sf::Sound sound;

public:
	Menu();
	void getFiles();
	void setTexts();
	void mouseWork(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setColors();
	~Menu();
};

