#pragma once

class TetrominoShape;

class Field {
private:
	bool** field;
public:
	Field();

	bool isFit(int y, int x, TetrominoShape shape);

	~Field();
};