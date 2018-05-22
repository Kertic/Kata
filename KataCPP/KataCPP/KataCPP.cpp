// KataCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Kata.h"
#define FIBAMT 100

int main()
{
	//Kata::FindOutlier({});
	Kata::FindOutlier({ 2, 3, 4 });
	Kata::FindOutlier({ 1,2,3 });
	Kata::FindOutlier({ 4,1,3,5,9 });
	Kata::FindOutlier({2,6,8,10,3});

	std::string test1 = Kata::get_middle("middle");

	int test2 = Kata::findDigit(1234567890,4);
	std::vector<int> test4 = { 0,1 };
	std::vector<int> test3 = Kata::xbonacci(test4, 10);

	Kata::chessBoardCellColor("A1", "B2");
	Kata::highestScoringWord("what time are we climbing up the volcano");
	Kata katerino; 
	unsigned long long int fibs[FIBAMT];
	for (unsigned long long int i = 0; i < FIBAMT; i++)
	{
		fibs[i] = katerino.Fib(i);
	}

	return 0;
}

