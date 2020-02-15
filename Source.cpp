#include <iostream>
#include <windows.h>
#include <ctime>
#include "Field.h"
#include "Tetromino.h"
#include "Defines.h"

void init();
int menu();
void gameLoop();

int main() {
	init();

	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 0:
			gameLoop();
			std::cout << "0";
			break;
		case 1:
			std::cout << "1";
			break;
		case 2:
			std::cout << "2";
			break;
		default:
			std::cout << "Error unknown operation";
			break;
		}
	}
}

void init() {
	srand(time(0));

	auto wndHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	//HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD crd = { WINDOWS_WIDTH, WINDOWS_HEIGHT };
	//SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	//SetConsoleWindowInfo(out_handle, true, &src);
	//SetConsoleScreenBufferSize(out_handle, crd);

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(wndHandle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(wndHandle, &structCursorInfo);
}

#define MENU_HORIZONTAL_CENTER_OFSET 4
#define MENU_VERTICAL_OFFSET 10
int menu() {
	static const auto wndHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords;

	char input = '\0';
	int item = 0;
	while (input != 'e') {
		coords.X = WINDOWS_WIDTH / 2 + MENU_HORIZONTAL_CENTER_OFSET;
		coords.Y = WINDOWS_HEIGHT / 2 + MENU_VERTICAL_OFFSET;
		SetConsoleCursorPosition(wndHandle, coords);
		std::cout << "Start" << std::endl;
		coords.X = WINDOWS_WIDTH / 2 + MENU_HORIZONTAL_CENTER_OFSET;
		coords.Y = WINDOWS_HEIGHT / 2 + MENU_VERTICAL_OFFSET + 1;
		SetConsoleCursorPosition(wndHandle, coords);
		std::cout << "Leaderboard" << std::endl;
		coords.X = WINDOWS_WIDTH / 2 + MENU_HORIZONTAL_CENTER_OFSET;
		coords.Y = WINDOWS_HEIGHT / 2 + MENU_VERTICAL_OFFSET + 2;
		SetConsoleCursorPosition(wndHandle, coords);
		std::cout << "Exit";
		if (input == 's') {
			item = item + 1 % 3;
		}
	}

	return item;
}

void gameLoop() {
	bool isLose = false;
	while (!isLose) {

	}
}