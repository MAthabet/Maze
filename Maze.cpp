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
	tgame();
	return 0;
}

void tgame()
{
	fileToVec();
	printMaze();

	pos player = findPlayer();
	bool win = false;
	char move;
	
	//setCursorPosition(player.x, player.y);
	//std::cout << ' ';

	
	do {
		setCursorPosition(player.x, player.y);
		std::cout << '@';
		move = _getch();
		setCursorPosition(player.x, player.y);
		std::cout << ' ';
		//remove player pos
		if (maze[player.y][player.x] == ' ')
		{
			setCursorPosition(player.x, player.y);
			std::cout << ' ';
		}

		switch (move)
		{
		case 'a':
		case 'A':
			if (maze[player.y][player.x - 1] == ' ') player.x -= 1;
			if (maze[player.y][player.x - 1] == 'x') win = true;
			break;
		case 'd':
		case 'D':
			if (maze[player.y][player.x + 1] == ' ') player.x += 1;
			if (maze[player.y][player.x + 1] == 'x') win = true;
			break;
		case 'w':
		case 'W':
			if (maze[player.y - 1][player.x] == ' ') player.y -= 1;
			if (maze[player.y - 1][player.x] == 'x') win = true;
			break;
		case 's':
		case 'S':
			if (maze[player.y + 1][player.x] == ' ') player.y += 1;
			if (maze[player.y + 1][player.x] == 'x') win = true;
			break;
		default:
			break;
		}
	} while (!win);
	system("cls");
	std::cout << "congratulations!!!\n\a";
	while (!_kbhit());
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
			if (maze[i][j] == '@')
			{
				return {j,i};
			}
		}
	}
	
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
			std::cout << c ;
		}

		std::cout << '\n';
	}
}