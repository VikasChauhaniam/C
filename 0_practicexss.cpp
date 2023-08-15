#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

void fcfs(int numProcess, vector<vector<vector<int>>> a){
    for(auto row: a){
        for(auto cell: row){
            for(auto element: cell) {
                cout << element<<",";
            }
            cout << "+"<<cell.size() << "\t\t";
        }
        cout<<"-"<<row.size()<<endl;
    }

    int i=0;
    while(i!=numProcess){

        vector<int> min_av = a[0][1];
        vector<int> min_id = a[0][0];

        for(int row=1;row<a.size();row++){
            if(a[row][1] < min_av){
                min_av = a[row][1];
                min_id = a[row][0];
            }
            else if(a[row][1] == min_av){
                if(a[row][0] < min_id){
                    min_id = a[row][0];
                    min_av = a[row][1];
                }
            }  
        }
        cout << "min arrival time = " << min_av << endl;
        cout << "min id = " << min_id << endl;
    
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

    

    int newMatrix[numRows-1][7];

    for(int i=1; i<=numRows-1; i++){
            for(int j=0;j<numColumns;j++){
                int intValue = std::stoi(matrix[i][j]);
                newMatrix[i-1][j] = intValue;
                std::cout << newMatrix[i-1][j]<< "\t";
        }
        std::cout << std::endl;
    }

    

    int num_processes = numRows-1;


    vector<vector<vector<int>>> v;

    cout << "v size : " << v.size() << endl;

    for(int i=0;i<num_processes;i++){
        vector<vector<int>> temp1;
        for(int j=0;j<7;j++){
            vector<int> temp2;
            if(j<2){
                temp2.push_back(newMatrix[i][j]);
            }
            else{

                temp2.push_back(newMatrix[i][j]);
                if(j!=6){
                    j++;
                    temp2.push_back(newMatrix[i][j]);
                }
                
            }
                temp1.push_back(temp2);
        }
        v.push_back(temp1);
    }

    // for(auto row: v){
    //     for(auto cell: row){
    //         for(auto element: cell) {
    //             cout << element<<",";
    //         }
    //         cout << "+"<<cell.size() << "\t\t";
    //     }
    //     cout<<"-"<<row.size()<<endl;
    // }

    fcfs(num_processes, v);

      return 0;
}  