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

	void WriteToFile(string filename, string content);
	string ReadFromFile(string filename);
	void ClearFile(string filename);
};

