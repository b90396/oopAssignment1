#pragma once

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class FileHandler
{
private:
	string contentBuffer;
public:
	FileHandler();
	~FileHandler();

	string ReadFromFile(string name);
	void WriteToFile(string name, string content);
};

