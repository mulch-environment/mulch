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

std::string Utility::boolToString(bool input) 
{
   //using ternary operators
   return input ? "true" : "false";
}

















