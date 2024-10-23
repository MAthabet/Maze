#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
void tgame()
{
	bool win = false;
	struct Pos {
		int x;
		int y;
	}pos = { 5,5 };
	Pos t = { 100,20 };
	char mov;
	char scr[29][120];
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			scr[i][j] = ' ';
			if (j == 0 || j == 119) scr[i][j] = '\|';
			if (i == 0 || i == 28) scr[i][j] = '-';
		}
	}
	scr[t.y][t.x] = 'x';
	system("cls");
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			std::cout << scr[i][j];
		}
		std::cout << std::endl;
	}
	do {
		setCursorPosition(pos.x, pos.y);
		std::cout << "@";
		mov = _getch();
		if (scr[pos.y][pos.x] == ' ')
		{
			setCursorPosition(pos.x, pos.y);
			std::cout << ' ';
		}
		switch (mov)
		{
		case 'a':
			if (scr[pos.y][pos.x - 1] == ' ') pos.x -= 1;
			if (scr[pos.y][pos.x - 1] == 'x') win = true;
			break;
		case 'd':
			if (scr[pos.y][pos.x + 1] == ' ') pos.x += 1;
			if (scr[pos.y][pos.x + 1] == 'x') win = true;
			break;
		case 'w':
			if (scr[pos.y - 1][pos.x] == ' ') pos.y -= 1;
			if (scr[pos.y - 1][pos.x] == 'x') win = true;
			break;
		case 's':
			if (scr[pos.y + 1][pos.x] == ' ') pos.y += 1;
			if (scr[pos.y + 1][pos.x] == 'x') win = true;
			break;
		default:
			break;
		}
	} while (!win);
	system("cls");
	std::cout << "congratulations!!!\n\a";
}
int main()
{
	const int MAX_SIZE = 20*63;
    int arr[MAX_SIZE];
    int i = 0;

    // Open the file for reading
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Read integers from the file and store them into the array
    while (file >> arr[i] && i < MAX_SIZE) {
        i++;
    }

    // Close the file
    file.close();

    // Print the array to verify the contents
    std::cout << "Array contents: ";
    for (int j = 0; j < i; j++) {
        std::cout << arr[j] << " ";
    }
    std::cout << std::endl;
}
