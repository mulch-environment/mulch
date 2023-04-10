#include "MulchExceptions.h"
#include "EnumTables.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

void MulchExceptions::NoFileError(int &c) 
{
	if (c != 0)
	{
		throw std::invalid_argument("ERROR: Couldn't open file! \n");
	}
}

void MulchExceptions::SQLiteErrorIfNeeded(int &c, char *zErrMsg) 
{
	if (c != 0)
	{
		throw std::invalid_argument("mulch exception: " + std::string(zErrMsg));
	}
}

void MulchExceptions::RepTypeIsNone(RepresentationEnum repType) 
{
	if (repType != NoneRepresentation) 
	{
	    throw std::runtime_error("Invalid representation type");
	}
}

void MulchExceptions::DataTypeIsNone(DataEnum datInfo) 
{
	if (datInfo != NoneData) 
	{
	    throw std::runtime_error("Invalid data info");
	}
}

void MulchExceptions::FileNameIsNone(std::string fileName) 
{
	std::cout << fileName << std::endl;
	if (!fileName.empty()) 
	{
	    throw std::runtime_error("Invalid file name");
	}
}






