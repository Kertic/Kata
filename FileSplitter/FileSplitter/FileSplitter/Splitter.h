#pragma once
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
class Splitter
{
public:
	static int CharToInt(char convert);
	static char IntToChar(int convert);
	static string IntToString(int convert);
	static int FindDigit(int num, int nth);
	static bool Split(string fileLocationName, int fileSegmentSize);
	//args should be char* for each file
	static bool Fuse(string saveLocationName, int fileCount, ...);
	Splitter();
	~Splitter();
};

