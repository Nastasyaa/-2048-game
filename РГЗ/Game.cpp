#include "Game.h"


Game::Game()
{
	getFiles();
	setColors();
	arrayOfColors;
	for (int i = 0; i < 7; i++) // создаем массив соответствия каждому возможному значению в квадрате определенного цвета
	{
		col[i].z = pow(2, i + 1);
		col[i].Col = arrayOfColors[i];
     
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix[i][j] = 0;
}

void Game::Score() { 

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		 for (int t = 0; t < 7; t++)
			
				if (matrix[i][j] == scorespeed[t])
				{
					res += scorespeed[t];
				}
	}
	std::ostringstream ss;
	ss << res;
	scoretxt.setString(ss.str());
}


int Game::UserStep(sf::RenderWindow &window) {
	sf::Color Blue(22, 147, 219);
	int k = 0;

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		for (int j = 0; j < 4; j++)
		{
			k += ChangeValue(matrix[0][j], matrix[1][j], matrix[2][j], matrix[3][j]);
		
		}
}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		for (int j = 0; j < 4; j++)
		{
			k += ChangeValue(matrix[3][j], matrix[2][j], matrix[1][j], matrix[0][j]);
			
		}
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

		for (int i = 0; i < 4; i++) {
			k += ChangeValue(matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
		}
       }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		for (int i = 0; i < 4; i++)
		{
			k += ChangeValue(matrix[i][3], matrix[i][2], matrix[i][1], matrix[i][0]);
		}
	}

	if (k != 0)
		return 1;
	else
		return 0;

}

int Game::GenerateRandom() {

	Matr emptyVal[16];
	int Val[] = { 2, 4 };
	int  count = 0;
	int row2, col2;

	srand(time(0));
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {

			if (matrix[i][j] == 0)
			{
				emptyVal[k].row = i;
				emptyVal[k].col = j;
				count++;
				k++;
			}

			else

				continue;
		}

	if (count == 0) {

		return 0;

	}

	else
	{
		int n;
		n = rand() % count;
		matrix[emptyVal[n].row][emptyVal[n].col] = Val[rand() % 2];
	}
	return 1;
}

int Game::CheckGrid(sf::RenderWindow &window) {

	int count = 0;

	for (int i = 0; i<4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (matrix[i][j] != 0)

				count++;
		}

	if ((count == 16) && (UserStep(window) == 0))
	{
        return 0;
	}
	else
		return 1;

}

int Game::ChangeValue(int &value1, int &value2, int &value3, int &value4) {

	int arrayOfVal[4] = { value1, value2, value3, value4 };

	for (int in = 1; in < 4; in++)
	{
		if (arrayOfVal[in] == 0)
		{
			continue;
		}

		else
		{
			for (int index = in - 1; index >= 0; index--)
			{
				if (arrayOfVal[index] == 0)
				{
					arrayOfVal[index] = arrayOfVal[index + 1];
					arrayOfVal[index + 1] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int in = 1; in < 4; in ++)
	{

		if ((in != 0) && (arrayOfVal[in - 1] == arrayOfVal[in]))
		{
			arrayOfVal[in - 1] *= 2;
			arrayOfVal[in] = 0;
		}

	}

	for (int in = 1; in < 4; in++)
	{
		if (arrayOfVal[in] == 0)
		{
			continue;
		}

		else
		{
			for (int index = in - 1; index >= 0;index--)
			{
				if (arrayOfVal[index] == 0)
				{
					arrayOfVal[index] = arrayOfVal[index + 1];
					arrayOfVal[index + 1] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}

	if (value1 == arrayOfVal[0] && value2 == arrayOfVal[1] && value3 == arrayOfVal[2] && value4 == arrayOfVal[3]) {
		return 0;
	}
	value1 = arrayOfVal[0];
	value2 = arrayOfVal[1];
	value3 = arrayOfVal[2];
	value4 = arrayOfVal[3];
	return 1;
}

void Game::GameRes(sf::RenderWindow &window) {

	sf::RectangleShape rec3[4][4];

	getFiles();
	setColors();
	setTexts();

	window.clear(sf::Color::Black);

	drawSquare();

	int dx = 0, dy = 0; //смена цвета квадратов 
	int x = 0;
	for (int i = 0; i < 4; i++) {
             dx = 0;
		for (int j = 0; j < 4; j++)
		{
			if (matrix[i][j] != 0)
			{
				for (int t = 0; t < 7; t++)
				{
					if (matrix[i][j] == col[t].z)
						rec3[i][j].setFillColor(col[t].Col);
				}
			}
			else
				rec3[i][j].setTexture(&img1);
			
			rec3[i][j].setSize(sf::Vector2f(85, 85));
			rec3[i][j].setPosition(50 + dx, 130 + dy);
			rec3[i][j].setOutlineColor(sf::Color::Black);
			rec3[i][j].setOutlineThickness(5);
			dx += 85;
            }
		dy += 85;
	}

	dx = 30;
	dy = 10;


	for (int i = 0; i < 4; i++) //смена цифр
	{
		dx = 30;
		for (int j = 0; j < 4; j++)
		{
			if (matrix[i][j] != 0)
			{
				std::ostringstream ss;
				ss << matrix[i][j];
				txt.setString(ss.str());
				if (matrix[i][j] > 64)
					x = 18;
				if ((matrix[i][j] > 8) && (matrix[i][j] <= 64)) {
					x = 5;
				}
				txt.setPosition(50 + dx - x, 130 + dy);
				
				texts[i][j] = txt;
}           	else
			{
				txt.setString("0");
				txt.setPosition(50 + dx, 130 + dy);
				texts[i][j] = txt;
			}
            dx += 85;
			x = 0; 
		}
    dy += 85;
	}
	
		Score();
		
		window.draw(scoretxt);
		window.draw(rec);
		window.draw(score);
		window.draw(restart);
		window.draw(exit);

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				window.draw(rec3[i][j]);
				window.draw(texts[i][j]);
			}
		sound1.play();
		window.display();
	
}

void Game::getFiles() {

	mainfont.loadFromFile("Fonts/Anja_Eliane.ttf");
	img1.loadFromFile("Images/1.jpg");
	buffer1.loadFromFile("Music/Sound2.ogg");
	sound1.setBuffer(buffer1);

}

void Game::setColors() {

	arrayOfColors[0] = Pink = { 227, 52, 110 };
	arrayOfColors[1] = Blue = { 22, 147, 219 };
	arrayOfColors[2] = Yellow = { 219, 154, 55 };
	arrayOfColors[3] = { sf::Color::White };
	arrayOfColors[4] = LightBlue = { 166, 184, 255 };
	arrayOfColors[5] = LightYellow = { 255, 245, 107 };
	arrayOfColors[6] = { sf::Color::Red };
	arrayOfColors[7] = LightPink = { 235, 152, 161 };
	arrayOfColors[8] = { sf::Color::Blue };
	arrayOfColors[9] = { sf::Color::Yellow };
	arrayOfColors[10] = { sf::Color::Black };
	arrayOfColors[11] = { sf::Color::Green };
}

void Game::setTexts() {

	int menuNumb = 0;

	score = { "", mainfont, 30 };
	score.setString("Score:");
	score.setFillColor(Yellow);
	score.setPosition(60, 30);

	best = { "", mainfont, 25 };
	best.setString("The best:");
	best.setFillColor(Pink);
	best.setPosition(300, 30);

	exit = { "", mainfont, 30 };
	exit.setString("Exit");
	exit.setFillColor(sf::Color::Red);
	exit.setPosition(450, 430);

	result = { "", mainfont, 30 };
	result.setString("Result:");
	result.setFillColor(Yellow);
	result.setPosition(60, 30);

	restart = { "", mainfont, 30 };
	restart.setString("Restart");
	restart.setFillColor(Blue);
	restart.setPosition(350, 30);

	scoretxt = { "", mainfont, 30 };
	scoretxt.setFillColor(Yellow);
	scoretxt.setPosition(180, 30);

	txt = { "", mainfont, 30 };

	txt.setFillColor(sf::Color::White);
	txt.setOutlineColor(sf::Color::Black);
	txt.setOutlineThickness(3);
}

void Game::drawSquare() {

	rec.setSize(sf::Vector2f(340, 340));
	rec.setPosition(50, 130);
	rec.setOutlineColor(sf::Color::Red);
	rec.setOutlineThickness(5);
}


Game::~Game()
{
}
