#include "../include/CSVManager.h"

#include <sstream>
#include <cstdio>

using namespace std;

//==============================
// Constructor
//==============================

CSVManager::CSVManager()
{

}

//==============================
// Destructor
//==============================

CSVManager::~CSVManager()
{

}

//==============================
// Check if file exists
//==============================

bool CSVManager::fileExists(string fileName)
{
    ifstream file(fileName);

    bool exists = file.good();

    file.close();

    return exists;
}

//==============================
// Create File
//==============================

bool CSVManager::createFile(string fileName)
{
    if(fileExists(fileName))
    {
        return true;
    }

    ofstream file(fileName);

    if(!file)
    {
        return false;
    }

    file.close();

    return true;
}

//==============================
// Write Header
//==============================

bool CSVManager::writeHeader(string fileName,
                             vector<string> header)
{
    ofstream file(fileName);

    if(!file)
    {
        return false;
    }

    for(size_t i=0;i<header.size();i++)
    {
        file << header[i];

        if(i != header.size()-1)
            file << ",";
    }

    file << endl;

    file.close();

    return true;
}

//==============================
// Append Row
//==============================

bool CSVManager::appendRow(string fileName,
                           vector<string> row)
{
    ofstream file(fileName, ios::app);

    if(!file)
    {
        return false;
    }

    for(size_t i=0;i<row.size();i++)
    {
        file << row[i];

        if(i != row.size()-1)
            file << ",";
    }

    file << endl;

    file.close();

    return true;
}

//==============================
// Read All Records
//==============================

vector<vector<string>> CSVManager::readAll(string fileName)
{
    vector<vector<string>> data;

    ifstream file(fileName);

    if(!file)
    {
        return data;
    }

    string line;

    while(getline(file,line))
    {
        vector<string> row;

        string cell;

        stringstream ss(line);

        while(getline(ss,cell,','))
        {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();

    return data;
}

//==============================
// Search By ID
//==============================

vector<string> CSVManager::searchByID(string fileName,
                                      string id)
{
    ifstream file(fileName);

    string line;

    while(getline(file,line))
    {
        vector<string> row;

        string cell;

        stringstream ss(line);

        while(getline(ss,cell,','))
        {
            row.push_back(cell);
        }

        if(!row.empty() && row[0] == id)
        {
            file.close();
            return row;
        }
    }

    file.close();

    return {};
}

//==============================
// Update Row
//==============================

bool CSVManager::updateRow(string fileName,
                           string id,
                           vector<string> newRow)
{
    vector<vector<string>> data = readAll(fileName);

    bool found = false;

    for(size_t i=0;i<data.size();i++)
    {
        if(!data[i].empty() && data[i][0] == id)
        {
            data[i] = newRow;
            found = true;
            break;
        }
    }

    if(!found)
    {
        return false;
    }

    ofstream file(fileName);

    if(!file)
    {
        return false;
    }

    for(size_t i=0;i<data.size();i++)
    {
        for(size_t j=0;j<data[i].size();j++)
        {
            file << data[i][j];

            if(j != data[i].size()-1)
                file << ",";
        }

        file << endl;
    }

    file.close();

    return true;
}

//==============================
// Delete Row
//==============================

bool CSVManager::deleteRow(string fileName,
                           string id)
{
    vector<vector<string>> data = readAll(fileName);

    ofstream file(fileName);

    if(!file)
    {
        return false;
    }

    bool deleted = false;

    for(size_t i=0;i<data.size();i++)
    {
        if(!data[i].empty() && data[i][0] == id)
        {
            deleted = true;
            continue;
        }

        for(size_t j=0;j<data[i].size();j++)
        {
            file << data[i][j];

            if(j != data[i].size()-1)
                file << ",";
        }

        file << endl;
    }

    file.close();

    return deleted;
}

//==============================
// Total Records
//==============================

int CSVManager::totalRecords(string fileName)
{
    ifstream file(fileName);

    if(!file)
    {
        return 0;
    }

    string line;

    int count = -1;

    while(getline(file,line))
    {
        count++;
    }

    file.close();

    if(count < 0)
        count = 0;

    return count;
}
