#define WINDOWS_HEIGHT 50
#define WINDOWS_WIDTH 80
#define FIELD_HEIGHT 20
#define FIELD_WIDTH 10

#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <fstream>

struct TetrominoShape {
	int size;
	bool** shape;

	~TetrominoShape() {
		for (int i = 0; i < size; ++i) {
			delete [] shape[i];
		}

		delete[] shape;
	}
};

class Tetromino {
private:
	static int numOfShapes;
	static TetrominoShape* possibleShapes;
	TetrominoShape currentShape;
	TetrominoShape nextShape;
	int currentRotation;
	bool isInit;
	int x, y;

	void LoadShapes(std::string filePath = "Tetrominos.dat") {
		std::ifstream fin(filePath);
		if (!fin.is_open()) {
			throw "Can’t open file " + filePath;
		}

		fin >> numOfShapes;
		possibleShapes = new TetrominoShape[numOfShapes];
		
		for (int i = 0; i < numOfShapes; ++i) {
			TetrominoShape& shape = possibleShapes[i];

			fin >> shape.size;

			for (int y = 0; y < shape.size; ++y) {
				for (int x = 0; x < shape.size; ++x) {
					fin >> shape.shape[y][x];
				}
			}
		}

		fin.close();
	}

	void setDefaultCordinates() {
		y = FIELD_HEIGHT;
		x = FIELD_WIDTH / 2;
	}
public:
	Tetromino()
	{
		LoadShapes();
	}

	void Init() {
		int currentShapeIndex = rand() % numOfShapes;
		int nextShapeIndex = rand() % numOfShapes;

		currentShape = possibleShapes[currentShapeIndex];
		nextShape = possibleShapes[nextShapeIndex];

		setDefaultCordinates();
	}

	void SwapShape() {
		currentShape = nextShape;

		int nextShapeIndex = rand() % numOfShapes;
		nextShape = possibleShapes[nextShapeIndex];

		setDefaultCordinates;
	}

	void Rotate() {
		TetrominoShape newShape;

		newShape.size = currentShape.size;

		for (int y = 0; y < currentShape.size; ++y) {
			for (int x = 0; x < currentShape.size; ++x) {
				newShape.shape[y][x] = currentShape.shape[x][y];
			}
		}

		currentShape = newShape;
	}
};

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

int menu() {
	char input = '\0';
	int item = 0;
	while (input != 'e') {
		std::cout << "Start" << std::endl;
		std::cout << "Leaderboard" << std::endl;
		std::cout << "Exit";
		input = getchar();
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