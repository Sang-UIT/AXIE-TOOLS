// Axie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "windows.h"
using namespace std;
int num(int a, int b)
{
	return a * 16 + b;
}
void color(int code) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}
void game(int turn, int ecard, int een)
{
	string s;
	while (true)
	{
		color(num(0, 14));
		if (een > 10)
			een = 10;
		if (een < 2)
			een = 2;
		int adde = 0, addc = 0;
		system("cls");
		cout << "TURN: " << turn << endl;
		color(num(0, 11));
		cout << "ENEMY's ENERGY: " << een << endl;
		color(num(0, 12));
		cout << "ENEMY's CARD: " << ecard << endl;
		color(num(0, 8));
		cout << "TYPE HOW MANY ENEMY's ENERGY AND CARD ADDED OR USED \n(Enter if no happend): \n";
		color(num(0, 15));
		cout << "TYPE R TO RESET\n";
		turn++;
		getline(cin, s);
		if (s == "R" || s == "r")
			game(1,6,3);
		//natural added;
		ecard += 3;
		een += 2;
		if (s != "")
		{
			bool k = 1;
			int i = 0;
			//add en
			while (s[i] != ' ' && i < s.length())
			{
				cout << k << " ";
				if (s[i] >= 48 && s[i] <= 57)
				{
					if(k==1)
					adde = adde - (int(s[i]) - 48);
					else
						adde = adde + int(s[i]) - 48;
				}
				
				if (s[i] == '+')
					k = 0;
				else
					k = 1;
				i++;
			}
			i++;
			k = 1;
			while (i < s.length())
			{
				cout << k << " ";
				if (s[i] >= 48 && s[i] <= 57)
				{
					if (k == 1)
						addc = addc - (int(s[i]) - 48);
					else
						addc = addc + int(s[i]) - 48;
				}

				if (s[i] == '+')
					k = 0;
				else
					k = 1;
				i++;
			}
			i++;
			k = 1;
			ecard += addc;
			een += adde;
		}
	}
}
void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
int main()
{
	setFontSize(16);
	int turn = 1, ecard = 6, een = 3;
	game(turn, ecard, een);
    return 0;
}

