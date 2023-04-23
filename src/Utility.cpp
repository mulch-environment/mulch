// #include "../assets/config.h"
#include "Utility.h"
#include <stdio.h>
#include <iostream>
#include <fstream>


std::string Utility::getFileContents(std::string &kk)
{
		std::ifstream ifs(kk);
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
			(std::istreambuf_iterator<char>() ) );

		return content;
}


/* Activate Foreign keys constrain **/
std::string Utility::SetForeignKeysOn()
{
	std::string query;
	query = "PRAGMA FOREIGN_KEYS = ON";
	query += ";";
	return query;

}

void Utility::protectsql(std::string &query)
{
	for (size_t i = 0; i < query.length(); i++)
	{
		if (query[i] == '\'')
		{
			query.replace(i, 1, "''");
            i++;
		}
	}
}

bool Utility::isNull(const std::string &str_input)
{
	return (str_input == "__NULL__");
}

std::string Utility::boolToString(bool input) 
{
   //using ternary operators
   return input ? "true" : "false";
}


int Utility::fromNullToZero(std::string id)
{
	if (isNull(id))
	{
		std::cout << "NOTE: the table id is NULL, return 0" << std::endl;
		return 0;
	}
	else 
	{
		return std::stoi(id);
	}
}

void Utility::zeroToNull(int var) 
{
    if (var == 0) 
    {
      var = NULL;
    }
}








