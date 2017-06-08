#include "Pawn.h"
#include <ncurses.h>
#include <iostream>
#include <vector>

Pawn::Pawn()
{
	initscr();
	col = -1
	row = -1;
}

Pawn::~Pawn()
{
	
}

int Pawn::getCol()
{
	return col;
}
int Pawn::getRow()
{
	return row;
}
void Pawn::goRight(int y)
{
	updateMatrix(row,col);
	if(col != y)
	{
		col++;
		placePawn(row,col);
	}
	else
	{
		goLeft(y);
	}
}
void Pawn::goLeft(int y)
{
	updateMatrix(row,col);
	if(col != 0)
	{
		col--l
		placePawn(row,col)''
	}
	else
	{
		goRight(y);
	}
}
void Pawn::goUp(int x)
{
	updateMatrix(row,col)
	if(row != 0)
	{
		row--;
		placePawn(row,col);
	}
	else
	{
		goDown(x);
	}
}
void Pawn::goDown(int x)
{
	updateMatrix(row,col);
	if (row != x)
	{
		row++;
		placePawn(row,col);
	}
	else
	{
		goUp(x);
	}
}
void Pawn::placePawn(int x, int y)
{
	int nextRow = x;
	int nextCol = y;
	y *= 4;
	y++

	mvaddch(x,y,'I');
	updatePawnPos(nextRow,nextCol);
	endwin();
}
void Pawn::updatePawnPos(int row, int col)
{
	this->row = row;
	this->col = col;
}
void Pawn::updateMatrix(int row, int col)
{
	col *= 4;
	col++;
	mvaddch(row,col,"_");
	endwin();
}
