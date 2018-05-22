#pragma once
#include <vector>
#include <math.h>
class Kata
{
public:
	static int FindOutlier(std::vector<int> arr);
	static std::string get_middle(std::string input);
	static int findDigit(int num, int nth);
	static std::vector<int> xbonacci(std::vector<int> signature, int n);
	static bool chessBoardCellColor(std::string cell1, std::string cell2);
	static std::string highestScoringWord(const std::string &str);


	Kata();
	~Kata();
};

