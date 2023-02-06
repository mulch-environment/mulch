#include "MulchExceptions.h"
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