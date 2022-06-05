#include "game_of_life.h"

#define ALIVE "\033[42m \033[00m"
#define DEAD "\033[47m \033[00m"

game_of_life::game_of_life()
{
	this->gen01[0][0] = '-';
}

void game_of_life::generacija01()
{
	srand(time(nullptr));


	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 40; j++)
			gen01[i][j] = rand() % 2;
	};
}

void game_of_life::copy(int gen01[REDAKA][STUPACA], int temp[20][40])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
			temp[i][j] = gen01[i][j];
	}
}

void game_of_life::sljedeca_generacija()
{
	int temp[20][40];
	copy(gen01, temp);
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j <	39; j++)
		{

			int count = 0;
			count = gen01[i - 1][j] +
				gen01[i - 1][j - 1] +
				gen01[i][j - 1] +
				gen01[i + 1][j - 1] +
				gen01[i + 1][j] +
				gen01[i + 1][j + 1] +
				gen01[i][j + 1] +
				gen01[i - 1][j + 1];
			//The cell dies.
			if (count < 2 || count > 3)
				temp[i][j] = 0;
			//The cell stays the same.
			if (count == 2)
				temp[i][j] = gen01[i][j];
			//The cell either stays alive, or is "born".
			if (count == 3)
				temp[i][j] = 1;

		}
	}
	//Copies the completed temp gen01 back to the main gen01.
	copy(temp, gen01);
}

void game_of_life::iscrtaj()
{
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 40; j++)
		{
			if (gen01[i][j] == 1)
				cout << ALIVE;
			else
				cout << DEAD;
		}
		cout << endl;
	}
}