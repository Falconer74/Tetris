#include "Field.h"
#include "Defines.h"
#include "Tetromino.h"

Field::Field()
{
	for (int i = 0; i < FIELD_HEIGHT; ++i) {
		for (int j = 0; j < FIELD_WIDTH; ++j) {
			field[i][j] = false;
		}
	}
}

bool Field::isFit(int y, int x, TetrominoShape shape) {
	for (int i = 0; i < shape.size; ++i) {
		for (int j = 0; j < shape.size; ++j) {
			if (y < 0 || x < 0 || x + shape.size > FIELD_WIDTH || y + shape.size > FIELD_HEIGHT
				|| (field[y + i][x + j] && shape.shape[i][j])) 
			{
				return false;
			}
		}
	}

	return true;
}

Field::~Field() {
	for (int i = 0; i < FIELD_HEIGHT; ++i) {
		delete[] field[i];
	}

	delete[] field;
}