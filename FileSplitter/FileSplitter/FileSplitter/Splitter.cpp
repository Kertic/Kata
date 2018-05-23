#include "Splitter.h"



Splitter::Splitter()
{
}


Splitter::~Splitter()
{
}


bool Splitter::Split(string fileLocationName, int fileSegmentSize)
{
	ifstream inFile(fileLocationName, ios::binary, ios::in);
	int originalFileSize = inFile.tellg();
	char* fileMem = new char[originalFileSize];
	int bufferLocation = 0;

	ifstream outFile(fileLocationName, ios::binary | ios::out);

	return true;
}

bool Splitter::Fuse(string saveLocationName, int fileCount, ...)
{
	va_list args;
	va_start(args, fileCount);
	int filesize = 0;
	vector<char> builtFile;
	for (int i = 0; i < fileCount; i++)
	{

		ifstream file(va_arg(args, char*), std::ios::binary | std::ios::in);
		int size = file.tellg();
		filesize += size;

		char* tempFile = new char[size];
		file.seekg(0, ios::beg);
		file.read(tempFile, size);
		file.close();
		for (int i = 0; i < size; i++)
			builtFile.push_back(tempFile[i]);

		delete[] tempFile;


	}
	va_end(args);
	char* builtFileChar = new char[builtFile.size() * sizeof(char)];
	for (int i = 0; i < filesize; i++)
		builtFileChar[i] = builtFile[i];

	
	delete[] builtFileChar;
	return true;
}