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

	//��������� ����
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
	void getFiles(); //��������� ����������� �����
	void setTexts(); //������������� �������
	void setColors(); //������������� ������� ������
	void drawSquare(); //��������� ���� ��� ����
	void Score(int); //���������� �����
	
	int  UserStep(sf::RenderWindow &window); //���� ������������
	int  GenerateRandom();//��������� ��������� �����
	int  CheckGrid(sf::RenderWindow &window);//�������� ����� �� ������� ��������� ����
	int  ChangeValue(int &value1, int &value2, int &value3, int &value4); //������ ��������
	void GameRes(sf::RenderWindow &window, int); //����� ����������� ����
	~Game();
};

