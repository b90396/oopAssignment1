#include "FileHandler.h"

FileHandler::FileHandler()
{

}

FileHandler::~FileHandler()
{

}

string FileHandler::ReadFromFile(string name)
{
    contentBuffer = "";
    string line;
    ifstream file(name);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            contentBuffer += line;
        }

        file.close();
    }

    cout << "Unable to read from file." << endl;

    return contentBuffer;
}

void FileHandler::WriteToFile(string name, string content)
{
    ofstream file(name);

    if (file.is_open())
    {
        file << content << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}