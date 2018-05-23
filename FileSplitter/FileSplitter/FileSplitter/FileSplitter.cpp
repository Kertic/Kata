// FileSplitter.cpp : Defines the entry point for the console application.
//

#include "Splitter.h"
#include "stdafx.h"
#include <vld.h>


int main()
{

	Splitter::Split("C:\\Users\\Brennan\\Documents\\PROJECT\\Kata\\FileSplitter\\FileSplitter\\FileSplitter\\Split Test\\SP.jpeg", 4000000);
	//Splitter::Split("ST.txt", 1);
	Splitter::Fuse("Split Test\\FUSE.jpeg", 6, 
		"Split Test\\SP.jpeg1", "Split Test\\SP.jpeg2", "Split Test\\SP.jpeg3", 
		"Split Test\\SP.jpeg4", "Split Test\\SP.jpeg5", "Split Test\\SP.jpeg6");

    return 0;
}

