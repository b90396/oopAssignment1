#include "FileHandler.h"

FileHandler::FileHandler() {}

FileHandler::~FileHandler() {}

void FileHandler::WriteToFile(string filename, string content)
{
    ofstream file(filename);

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

string FileHandler::ReadFromFile(string filename)
{
    string line, content;
    ifstream file(filename);

    // if file opened successfully..
    if (file.is_open())
    {
        // read from file...
        while (getline(file, line))
        {
            // concatenate file content to string.
            content += line;
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    return content;
}

void FileHandler::ClearFile( string filename )
{
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();
}