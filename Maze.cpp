#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

struct pos
{
	int x;
	int y;
};

pos findPlayer();
void tgame();
void setCursorPosition(int x, int y);
void fileToVec();
void printMaze();

std::vector<std::vector<char> > maze;



int main()
{
	fileToVec();
	tgame();
	return 0;
}

void findPlayer(){}

void tgame()
{
	pos player = findPlayer();
	pos goal = findGoal();
	bool win = false;
	char move;
	
	printMaze();
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

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

// player is '@'
pos findPlayer()
{
	int i, j;
	for (i = 0; i < maze.size() ;i++) {
		for (j = 0; j < maze[i].size() ;j++) {
			if (maze[i][j] =='@') break;
		}
	}
	return { i,j };
}

void fileToVec()
{
	std::string line;
	std::ifstream infile("input.txt");

	while (std::getline(infile, line)) {
		std::vector<char> row;

		for (char& c : line) {
			if (c != ',') {
				row.push_back(c);
			}
		}

		maze.push_back(row);
	}

}

void printMaze() {
	for (std::vector<char>& row : maze) {
		for (char& c : row) {
			std::cout << c << ' ';
		}

		std::cout << '\n';
	}
}