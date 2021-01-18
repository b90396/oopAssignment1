#include "FileHandler.h"

FileHandler::FileHandler() {}

FileHandler::~FileHandler() {}

void FileHandler::WriteToFile(string name, string content)
{
    ofstream file(name, ios_base::app | ios_base::out);

    // if file opened successfully...
    if (file.is_open())
    {
        // write content to file.
        file << content << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file.\n";
    }
}

string FileHandler::ReadFromFile(string name)
{
    string line, content;
    ifstream file(name);

    // if file opened successfully..
    if (file.is_open())
    {
        // read from file...
        while (getline(file, line))
        {
            // concatenate file content to string.
            content += line + " ";
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    return content;
}