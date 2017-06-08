#include "Matrix.h"
#include "Pawn.h"
#include <stdlib.h>
#include <random>
#include <chrono>
#include <mutex>
#include <thread>

std::vector<Pawn> v;
std::mutex mx1;
std::mutex mx2;

void draw(std::vector<int> *x, std::vector<int> *y,int collumns, int rows)
{
	while(true)
	{
		int deleteLast = v.size()-1;
		std::vector<int> x = *x;
		std::vector<int> y = *y;
		mx2.lock();
	}
}