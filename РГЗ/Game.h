#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>


//using namespace std;


struct Matr {

	int row;
	int col;

};

struct Colorist {

	int z;
	sf::Color Col;
};


class Game
{
	int matrix[4][4];

	//интерфейс игры
	sf::Color Pink, Blue, Yellow, LightPink, LightBlue, LightYellow;
	sf::Color arrayOfColors[12] = { sf::Color::Red, Pink, Blue, Yellow, LightPink, LightBlue, LightYellow, sf::Color::Green,sf::Color::Yellow, sf::Color::Blue, sf::Color::Black, sf::Color::White };
	int scorespeed[12] = { 4,6,8,10,12,15,20,25,30,35,40,45 };
	int res = 0;
	Colorist col[12];
	sf::RectangleShape rec, rec3[4][4];
	sf::Font mainfont;
	sf::Texture img1;
	sf::Text score, best, result, exit, scoretxt, restart;
	sf::Text txt, texts[4][4];
	sf::SoundBuffer buffer1;
	sf::Sound sound1;

public:

	Game();
	void getFiles(); //загружаем необходимые файлы
	void setTexts(); //устанавливаем надписи
	void setColors(); //устанавливаем палитру цветов
	void drawSquare(); //рисование поля для игры
	void Score(int); //количество очков
	
	int  UserStep(sf::RenderWindow &window); //ходы пользователя
	int  GenerateRandom();//генерация случайных чисел
	int  CheckGrid(sf::RenderWindow &window);//проверка сетки на остатки свободных мест
	int  ChangeValue(int &value1, int &value2, int &value3, int &value4); //измена значений
	void GameRes(sf::RenderWindow &window, int); //вывод полученного поля
	~Game();
};

