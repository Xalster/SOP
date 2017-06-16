#include "Matrix.h"
#include "Pawn.h"
#include <stdlib.h>
#include <random>
#include <chrono>
#include <mutex>
#include <thread>
#include <ncurses.h>

std::vector<Pawn> v;
std::mutex mx1;
std::mutex mx2;

void draw(int columns, int rows)
{
	while(true)
	{
		mx2.lock();
        int indexLast = v.size()-1;
        v[indexLast].placePawn(v[indexLast].getRow(),v[indexLast].getCol());
        for (int i = 0;i < v.size()-1; i++) {
            int choice = rand() % 4;
            if (choice == 0) {
                v[i].goDown(rows-1);
            }
            if (choice == 1) {
                v[i].goLeft(columns-1);
            }
            if (choice == 2) {
                v[i].goRight(columns-1);
            }
            if (choice == 3) {
                v[i].goUp(rows-1);
            }
        }
		mx2.unlock();
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        endwin();
	}
}

void randomCoord(std::vector<int> *px, std::vector<int> *py,int columns, int rows)
{
    while(true)
    {
        std::vector<int> &x = *px;
        std::vector<int> &y = *py;

        int nr = rand() % (columns-1);
        mx1.lock();
        x.push_back(nr);

        nr = rand() % (rows-1);
        y.push_back(nr);
        mx1.unlock();
    }
}

void addPawn(std::vector<int> *px, std::vector<int> *py)
{
    while(true)
    {
        std::vector<int> &x = *px;
        std::vector<int> &y = *py;
        bool nextPawn = true;

        Pawn pawn = Pawn();

        mx2.lock();
        for (int i = 0;i < v.size(); i++)
        {
            if(v[i].getRow() == x[0] && v[i].getCol() == y[0])
            {
                nextPawn = false;
            }
            else
            {
                nextPawn = true;
            }
        }
        mx2.unlock();

        if(nextPawn)
        {
            mx2.lock();
            pawn.updatePawnPos(x[0], y[0]);
            v.push_back(pawn);
            mx2.unlock();
            mx1.lock();
            x.erase(x.begin());
            y.erase(y.begin());
            mx1.unlock();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::vector<int> X;
    std::vector<int> Y;

    srand(time(NULL));
    int nr = rand() % 10 + 5;

    int columns = nr;
    int rows = nr;

    Matrix matrix;
    matrix.DrawMatrix(rows,columns);

    std::thread queueT(randomCoord, &X, &Y,columns, rows);
    std::thread pawnsT(addPawn, &X, &Y);
    std::thread drawT(draw,columns, rows);

    queueT.join();
    pawnsT.join();
    drawT.join();

    return 0;

}