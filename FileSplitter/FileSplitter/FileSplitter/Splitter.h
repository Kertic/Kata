#pragma once
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Splitter
{
public:
	static bool Split(string fileLocationName, int fileSegmentSize);
	//args should be char* for each file
	static bool Fuse(string saveLocationName, int fileCount, ...);
	Splitter();
	~Splitter();
};

