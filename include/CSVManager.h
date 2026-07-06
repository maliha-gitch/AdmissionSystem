#ifndef CSVMANAGER_H
#define CSVMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CSVManager
{
public:

    // Constructor
    CSVManager();

    // Destructor
    ~CSVManager();

    // Create a CSV file if it doesn't exist
    bool createFile(string fileName);

    // Write a header row to a CSV file
    bool writeHeader(string fileName, vector<string> header);

    // Append a new row to a CSV file
    bool appendRow(string fileName, vector<string> row);

    // Read all rows from a CSV file
    vector<vector<string>> readAll(string fileName);

    // Search for a row by ID (first column)
    vector<string> searchByID(string fileName, string id);

    // Update a row by ID
    bool updateRow(string fileName,
                   string id,
                   vector<string> newRow);

    // Delete a row by ID
    bool deleteRow(string fileName, string id);

    // Check if a file exists
    bool fileExists(string fileName);

    // Count total records (excluding header)
    int totalRecords(string fileName);
};

#endif
