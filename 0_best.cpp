#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int process_id;
    int arrival_time;
};

void FCFS_Scheduling(int num_processes, int arrival_times[], int cpu_burst_times[][3], int io_burst_times[][2]) {
    queue<Process> ready_queue;
    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        while (current_time < arrival_times[i]) {
            cout << "Time " << current_time << ": Idle" << endl;
            current_time++;
        }

        cout << "Time " << current_time << ": Process " << i + 1 << " started" << endl;

        for (int j = 0; j < 3; j++) { // Assuming each process has 3 CPU and I/O bursts
            current_time += cpu_burst_times[i][j];
            cout << "Time " << current_time << ": Process " << i + 1 << " CPU burst " << j + 1 << " completed" << endl;

            if (j < 3) {
                current_time += io_burst_times[i][j];
                cout << "Time " << current_time << ": Process " << i + 1 << " entered I/O burst " << j + 1 << endl;
            }
        }

        cout << "Time " << current_time << ": Process " << i + 1 << " completed" << endl;
    }
}

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

    std::cout << "=====================a:================ " << std::endl;

    int num_processes = numRows-1;
    int numCBurst= 3;
    int numIBurst= 2;
    std::cout << "=====================b:================= " << std::endl;
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
    std::cout << "=====================c:================= " << std::endl;

    for(int i=0; i<num_processes;i++){
        arrival_times[i] = newMatrix[i][1];
    }    

    for(int i=0; i<num_processes;i++){
        std::cout << i << " : " << arrival_times[i]<<std::endl;
    } 

    for(int i=0; i<num_processes;i++){
        for(int j=2,k=0;j<numColumns;j++){
            if((j%2)==0){
                cpu_burst_times[i][k] = newMatrix[i][j];
                std::cout << i<<","<<k << " : " << cpu_burst_times[i][k]<< "||"; 
                k++;
            } 
        } 
        cout << endl;   
    }    
cout << "=============================" << endl;
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
    
    FCFS_Scheduling(num_processes, arrival_times, cpu_burst_times, io_burst_times);
    return 0;
}