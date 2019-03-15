// Christmass Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;
// typedef for the pointer-to-member

int const height = 30;
char Tree[height][2*height];
int tempPos;
string zyczenia = "Wesolych swiat!";

struct Colore
{
	int blue = 1;
	int red = 4;
	int purple = 5;
	int yellow = 6;
	int green = 10;

};
typedef int Colore::*ptr_attr;
int main()

{
	
	map<int, ptr_attr> colMap;
	colMap[1] = &Colore::blue;
	colMap[2] = &Colore::red;
	colMap[3] = &Colore::purple;
	colMap[4] = &Colore::yellow;
	colMap[5] = &Colore::green;

	Colore color;
	
	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );

	SetConsoleTextAttribute(hOut, color.*colMap[5]);
	srand(time(NULL));

	for (int i = 1; i <= height - 1; i++)
	{
		for (int k = 1; k <= height - i - 1; tempPos = k, k++)
		{
			Tree[i][k] = ' ';
			cout << Tree[i][k];
		}
		
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			if (j == 1 || j == 2 * i - 1 || i == height -1)
			{
				Tree[i][tempPos + j] = '*';
			}
			else
			{
				int randVal = rand() % 20;
				int randCol = rand() % 5+1;

						if (randVal == 1 && (Tree[i][tempPos + j - 1] == ' ' || Tree[i][tempPos + j + 1] == ' '))
						{
							SetConsoleTextAttribute(hOut, color.*colMap[randCol]);
							Tree[i][tempPos + j] = 'O';
						}
						else
						{
							Tree[i][tempPos + j] = ' ';
						}
			}
			cout << Tree[i][tempPos + j];
			SetConsoleTextAttribute(hOut, color.*colMap[5]);
		}
		cout << endl;
	}

	for (int j = 0; j < 2; j++)
	{
		for (int pien = 1; pien <= height - 5; pien++)
		{
			cout << " ";
		}
		cout << "####" << endl;
	}
	cin.get();
}