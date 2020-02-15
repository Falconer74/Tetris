#include "Tetromino.h"
#include "Defines.h"
#include <string>
#include <fstream>
#include "Field.h"

TetrominoShape::~TetrominoShape() {
	for (int i = 0; i < size; ++i) {
		delete[] shape[i];
	}

	delete[] shape;
}
TetrominoShape::TetrominoShape(){}

int Tetromino::numOfShapes;
TetrominoShape* Tetromino::possibleShapes;

void Tetromino::LoadShapes(std::string filePath = "Tetrominos.dat") {
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

void Tetromino::setDefaultCordinates() {
	y = FIELD_HEIGHT;
	x = FIELD_WIDTH / 2;
}

Tetromino::Tetromino()
{
	LoadShapes();
}

void Tetromino::Init() {
	int currentShapeIndex = rand() % numOfShapes;
	int nextShapeIndex = rand() % numOfShapes;

	currentShape = possibleShapes[currentShapeIndex];
	nextShape = possibleShapes[nextShapeIndex];

	setDefaultCordinates();
}

void Tetromino::SwapShape() {
	currentShape = nextShape;

	int nextShapeIndex = rand() % numOfShapes;
	nextShape = possibleShapes[nextShapeIndex];

	setDefaultCordinates();
}

void Tetromino::Rotate(Field field) {
	TetrominoShape newShape;

	newShape.size = currentShape.size;

	for (int y = 0; y < currentShape.size; ++y) {
		for (int x = 0; x < currentShape.size; ++x) {
			newShape.shape[y][x] = currentShape.shape[x][y];
		}
	}

	if (field.isFit(y, x, newShape)) {
		currentShape = newShape;
	}
}

void Tetromino::ForceDown() {
	y++;
}

TetrominoShape Tetromino::GetShape() {
	if (isInit) {
		throw "Tetromino class is not initialized";
	}

	return currentShape;
}

int Tetromino::getX() {
	return x;
}

int Tetromino::getY() {
	return y;
}