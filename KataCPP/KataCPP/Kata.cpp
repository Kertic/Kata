#include "Kata.h"



Kata::Kata()
{
}


Kata::~Kata()
{
}


int Kata::FindOutlier(std::vector<int> arr) {
	bool isEven = false;
	if (arr[0] % 2 == 0) {//0 is even
		if (arr[1] % 2 == 0) //1 is even
			isEven = true;//two evens means even is the pattern
		else
			if (arr[2] % 2 == 0)//2 is even, so return 1 cause its the outlier
				return arr[1];
			else//2 is odd, so 0 is the outlier
				return arr[0];
	}
	else//0 is odd
	{
		if (arr[1] % 2 == 0)//1 is even
			if (arr[2] % 2 == 0)//2 is even, so return 0 cause its the outlier
				return arr[0];
			else//2 is odd, so 1 is the outlier
				return arr[1];
		//we would mark it as false here, but its false by default

	}



	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if ((arr[i] % 2 == 0) == !isEven)//if its not the same evenness as the pattern declares, then we return it
			return arr[i];
	}
	return -1;
}
std::string Kata::get_middle(std::string input) {
	return (input.size() % 2 == 0) ? std::string(&input[input.size() / 2 - 1], 2) : std::string(&input[input.size() / 2], 1);
}
int Kata::findDigit(int num, int nth){
	if (nth < 1)
		return -1;
	return (int)(abs(num) % (int)(powl(10,nth)) / powl(10,nth-1));

}
std::vector<int> Kata::xbonacci(std::vector<int> signature, int n)
{
	int additionAmount = signature.size();

	for (int i = signature.size(); i < n; i++)//until we reach the size of vector requested by n
	{
		int currentInt = signature[signature.size() - 1];
		for (int j = additionAmount - 1; j > 0; j--)//for each index beforehand that we should add starting from the largest
		{
			currentInt += signature[signature.size() - 1 - j];//from the end, go back j indicies
		}
		signature.push_back(currentInt);
	}

	std::vector<int> returnVec;

	for (int i = 0; i < n; i++)
	{
		returnVec.push_back(signature[i]);
	}
	return returnVec;
}
bool Kata::chessBoardCellColor(std::string cell1, std::string cell2)
{
	//a is odd, b is even, so on so forth. Numbers follow normal evenness.
	//bool cell1aIsEven = (int)cell1[0] % 2 == 0;
	//bool cell1bIsEven = (int)cell1[1] % 2 == 0;
	//
	//bool cell2aIsEven = (int)cell2[0] % 2 == 0;
	//bool cell2bIsEven = (int)cell2[1] % 2 == 0;
	//
	//
	//
	//return (cell1aIsEven == cell1bIsEven) == (cell2aIsEven == cell2bIsEven);

	return (((int)cell1[0] % 2 == 0) == ((int)cell1[1] % 2 == 0)) == (((int)cell2[0] % 2 == 0) == ((int)cell2[1] % 2 == 0));
}
std::string Kata::highestScoringWord(const std::string & str)
{
	std::vector<std::string> words;
	std::string currentWord;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') {
			words.push_back(currentWord);
			currentWord.clear();
		}
		else {
			currentWord.append(&str[i], 1);
		}

	}
	words.push_back(currentWord);
	int highestScore = 0;
	int hsIndex = 0;
	for (int curWord = 0; curWord < words.size(); curWord++)
	{
		int wordScore = 0;
		for (int curLetter = 0; curLetter < words[curWord].size(); curLetter++)
		{
			wordScore += (int)words[curWord][curLetter];
		}
		if (wordScore > highestScore) {
			highestScore = wordScore;
			hsIndex = curWord;
		}
	}

	return std::string(words[hsIndex]);
}

