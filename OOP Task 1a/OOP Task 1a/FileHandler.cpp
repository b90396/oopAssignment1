#include "FileHandler.h"



FileHandler::FileHandler() : contentBuffer(" ") {}

FileHandler::~FileHandler() {}

// useful for writing a chunk of content to a file.
void FileHandler::WriteToFile(string fileName, string content)
{
	// open file.
	ofstream file(fileName);

	if (file.is_open())
	{
		// write line to file, then close file.
		file << content << endl;
		file.close();
	}
	else
	{
		// something went wrong.
		cout << "Could not open file.\n";
	}
}

string FileHandler::ReadFromFile(string fileName)
{
	// reset buffer.
	contentBuffer = "";

	string line;
	ifstream file(fileName);

	// open file.
	if (file.is_open())
	{
		// while there is a line to be read...
		while (getline(file, line))
		{
			// concatenate current line of file into buffer. 
			contentBuffer += line + "\n";
		}

		// close file.
		file.close();
	}
	else
	{
		// something went wrong.
		cout << "Unable to open file.\n";
	}

	return contentBuffer;
}