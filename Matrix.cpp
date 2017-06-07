#include "Matrix.h"
#include <ncurses.h>
#include <iostream>

Matrix::Matrix()
{
	initscr();
}

Matrix::~Matrix()
{

}

void Matrix::DrawMatrix(int h, int w)
{
	int col = 0;
	int row = 0;
	for(int i = 0;i < h;i++)
	{
		for(int j = 0;j < w;j++)
		{
			for(int k = 0; k < 3;k++)
			{
				mvaddch(row, col, '_');
				col++;
			}
			mvaddch(row, col, '|');
			col++;
		}
		row++;
		col = 0;
	}
	getch();
	endwin();	
}
