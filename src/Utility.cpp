// #include "../assets/config.h"
#include "Utility.h"
#include <stdio.h>
#include <iostream>
#include <fstream>


std::string Utility::getFileContents(std::string &kk)
{
		std::ifstream ifs(std::__fs::filesystem::path(kk).filename());
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
			(std::istreambuf_iterator<char>() ) );

		return content;
}


bool isNull(std::string &str_input)
{
	if (str_input == "__NULL__")
	{
		return true;
	}
	else
	{
		return false;
	}
}
