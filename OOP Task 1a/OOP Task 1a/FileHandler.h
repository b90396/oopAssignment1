#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler
{
private:
	string contentBuffer;
public:
	FileHandler();
	~FileHandler();

	void WriteToFile(string name, string content);
	string ReadFromFile(string name);
};

