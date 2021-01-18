#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileHandler
{
private:

public:
	FileHandler();
	~FileHandler();

	void WriteToFile(string name, string content);
	string ReadFromFile(string name);
};

