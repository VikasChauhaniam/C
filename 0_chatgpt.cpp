#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    std::ifstream inputFile("table_data.txt"); // Change the filename accordingly

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> tableData;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> row;
        std::istringstream iss(line);
        std::string cell;

        while (std::getline(iss, cell, '\t')) {
            row.push_back(cell);
        }

        tableData.push_back(row);
    }

    inputFile.close();

    // Determine the dimensions of the matrix
    size_t numRows = tableData.size();
    size_t numCols = 0;
    if (numRows > 0) {
        numCols = tableData[0].size();
    }

    // Dynamically allocate a matrix
    std::string** matrix = new std::string*[numRows];
    for (size_t i = 0; i < numRows; ++i) {
        matrix[i] = new std::string[numCols];
        for (size_t j = 0; j < numCols; ++j) {
            matrix[i][j] = tableData[i][j];
        }
    }

    // Access matrix elements using matrix[row][column]
    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numCols; ++j) {
            std::cout << "(" << i << j << ")" << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    const int arraySize = matrix[0][0].size();
    
    cout << "xyz : " << arraySize <<endl;

    

    return 0;
}
