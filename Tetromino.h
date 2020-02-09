#pragma once

#include <string>

class Field;

struct TetrominoShape {
	int size;
	bool** shape;

	TetrominoShape();

	~TetrominoShape();
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

	void LoadShapes(std::string filePath);
	void setDefaultCordinates();
public:
	Tetromino();

	void Init();
	void SwapShape();
	void Rotate(Field);
	void ForceDown();
	TetrominoShape GetShape();
	int getX();
	int getY();
};