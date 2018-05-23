#include "Splitter.h"



Splitter::Splitter()
{
}


Splitter::~Splitter()
{
}
int Splitter::CharToInt(char convert)
{
	return convert - '0';
}
char Splitter::IntToChar(int convert)
{
	return convert + '0';
}
int Splitter::FindDigit(int num, int nth)
{
	if (nth < 1)
		return -1;
	return (int)(abs(num) % (int)(powl(10, nth)) / powl(10, nth - 1));
}
string Splitter::IntToString(int convert)
{
	string returnString;
	int numOfchars =  convert > 0 ? (int)log10((double)convert) + 1 : 1;
	/*if (convert < 10)
		numOfchars = 1;
	else if (convert < 100)
		numOfchars = 2;
	else if (convert < 1000)
		numOfchars = 3;
	else if (convert < 10000)
		numOfchars = 4;
	else
		numOfchars = 5;*/

	for (int i = numOfchars; i > 0; i--) {
		int currentDigit = FindDigit(convert, i);

		returnString.push_back(IntToChar(currentDigit));
	}

	return returnString;
}

bool Splitter::Split(string fileLocationName, int fileSegmentSize)
{
	fstream inFile(fileLocationName, ios::in | ios::binary | ios::ate);
	int originalFileSize = inFile.tellg();
	char* fileMem = new char[originalFileSize];
	inFile.seekg(0, ios::beg);
	inFile.read(fileMem, originalFileSize);
	inFile.close();

	int bufferLocation = 0;
	int currentFileCount = 1;
	while (bufferLocation < originalFileSize) {
		string fileName = fileLocationName;
		fileName.append(IntToString(currentFileCount));
		fstream outFile(fileName, ios::binary | ios::out);

		for (int i = 0; i < fileSegmentSize && bufferLocation < originalFileSize; i++)
		{
			outFile.write(&fileMem[bufferLocation], 1);
			bufferLocation++;
		}
		outFile.close();
		currentFileCount++;
	}

	delete[] fileMem;
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

		fstream file(va_arg(args, char*), ios::binary | ios::in | ios::ate);
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

	fstream outfile(saveLocationName, ios::binary | ios::out);
	outfile.write(builtFileChar, builtFile.size());
	outfile.close();
	delete[] builtFileChar;
	return true;
}