#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    std::ifstream inputFile("data.txt"); // Open the input file
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> matrix; // 2D vector to store the matrix

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> row; // Vector to hold the values in each row
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            row.push_back(value); // Store values as strings in the row vector
        }
        matrix.push_back(row); // Add the row vector to the matrix
    }

    inputFile.close(); // Close the input file

    // Printing the matrix (optional)
    for (const auto& row : matrix) {
        for (const std::string& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    size_t numRows = matrix.size();
    size_t numColumns = (numRows > 0) ? matrix[0].size() : 0;

    std::cout << "Number of rows: " << numRows << std::endl;
    std::cout << "Number of columns: " << numColumns << std::endl;

    

    int newMatrix[numRows-1][numColumns];

    for(int i=1; i<=numRows-1; i++){
            for(int j=0;j<numColumns;j++){
                int intValue = std::stoi(matrix[i][j]);
                newMatrix[i-1][j] = intValue;
                std::cout << newMatrix[i-1][j]<< "\t";
        }
        std::cout << std::endl;
    }

    

    int num_processes = numRows-1;
    int numCBurst= 3;
    int numIBurst= 2;
    
    int arrival_times[num_processes];
    int cpu_burst_times[num_processes][3]; 
    int io_burst_times[num_processes][2];

    for(int i=0;i<num_processes;i++){
        for(int j=0;j<numCBurst;j++){
            cpu_burst_times[i][j] = 0;
        }
        for(int k=0;k<numIBurst;k++){
            cpu_burst_times[i][k] = 0;
        }
    }
    

    for(int i=0; i<num_processes;i++){
        arrival_times[i] = newMatrix[i][1];
    }    

    cout << "===============ARRIVAL TIME:================= " <<endl;

    for(int i=0; i<num_processes;i++){
        std::cout << i << " : " << arrival_times[i]<<std::endl;
    } 

    cout << "===============CPU TIME:================= " <<endl;
    for(int i=0; i<num_processes;i++){
        for(int j=2,k=0;j<numColumns;j++){
            if((j%2)==0){
                cpu_burst_times[i][k] = newMatrix[i][j];
                cout << i<<","<<k << " : " << cpu_burst_times[i][k]<< "||"; 
                k++;
            } 
        } 
        cout << endl;   
    }    
cout << "===============IO TIME:================= " <<endl;
    for(int i=0; i<num_processes;i++){
        for(int j=2,l=0;j<numColumns;j++){
            if((j%2)!=0){
                io_burst_times[i][l] = newMatrix[i][j];
                 std::cout << i<<","<<l << " : " << io_burst_times[i][l]<< "||"; 
                 l++;
            }
        } 
        cout << endl;   
    } 
    
    
    return 0;
}