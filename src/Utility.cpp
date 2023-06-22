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
	Utility::protectsql(query);
	return query;

}


void Utility::protectsql(std::string& query) 
{
  size_t pos = 0;
  while ((pos = query.find('\'', pos)) != std::string::npos) 
  {
      // Escape the apostrophe by doubling it
      query.insert(pos, 1, '\'');
      pos += 2;
  }

  pos = 0;
  while ((pos = query.find(',', pos)) != std::string::npos) 
  {
      // Replace comma with a space
      query.replace(pos, 1, " ");
      pos += 1;
  }
}


void Utility::protectParameter(std::string& parameter)
{
    std::string protectedParameter;
    for (size_t i = 0; i < parameter.length(); i++)
    {
        if (parameter[i] == '\'')
        {
            // Replace single apostrophe with two consecutive apostrophes
            protectedParameter += "''";
        }
        else
        {
            // Copy other characters as-is
            protectedParameter += parameter[i];
        }
    }

    std::cout<< "BEFORE: ";
    std::cout<< parameter <<std::endl;
    std::cout<< "AFTER: ";
    std::cout<< protectedParameter <<std::endl;    
    // Update the original parameter string with the protected version
        // Update the original parameter string with the protected version
    parameter = protectedParameter;
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









