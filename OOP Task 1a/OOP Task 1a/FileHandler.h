#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileHandler
{
	FileHandler();
	~FileHandler();

	void WriteToFile(string name, string content);
	string ReadFromFile(string name);
};

