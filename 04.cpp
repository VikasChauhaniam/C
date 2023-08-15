#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void priority(int numProcess, vector<vector<vector<int>>> a){
    for(auto row: a){
        for(auto cell: row){
            for(auto element: cell) {
                cout << element<<",";
            }
            cout << "+"<<cell.size() << "\t\t"; 
        }
        cout<<"-"<<row.size()<<endl;
    }
    vector<vector<int>> result(numProcess, vector<int>(6,0));
    
    for(int i=0;i<result.size();i++){
         for(int j=0;j<result[i].size();j++){
            if(j<2){
                result[i][j] = a[i][j][0];           
            } 
        }
        
    }
    

    int i=0;
    int clk=0;

    map<vector<int>,int> CT;
    map<vector<int>,int> BT;
   

   // cout<<"*******************************************************"<<endl;

    // for(int i=0;i<=numProcess;i++){
    //     AT[a[i][0]] = a[i][1][0];
    // }

    // for (map<vector<int>,int>::const_iterator it2 = AT.begin(); it2 != AT.end(); ++it2) {
    //     cout << it2->first[0] << "  ||   " << it2->second << std::endl;
    // }
    // cout<<"*******************************************************"<<endl;

    while(i!=numProcess){

        vector<int> min_av = a[0][1];
        vector<int> min_id = a[0][0];
        int min_row = 0;
        vector<int> min_BT = a[0][2];
        
        for(int row=1;row<a.size();row++){
            if(a[row][1] < min_av){
                min_av = a[row][1];
                min_id = a[row][0];
                min_BT = a[0][2];
                min_row = row;
            }
            else if(a[row][1] == min_av){
                if(a[row][0] < min_id){
                    min_id = a[row][0];
                    min_av = a[row][1];
                    min_BT = a[0][2];
                    min_row = row;
                }
            }  
        } 
        cout << "mini arrival : " << min_av[0]<<endl;
        cout << "mini id : " << min_id[0] << endl;
        cout << "row number : " << min_row << endl;
        cout << "min row size : " << a[min_row].size();

        for(int row=0;row<a.size();row++){
            if(a[row][1][0] <= clk && a[row][2][0] < min_BT[0]){
                min_id = a[row][0];
                min_av = a[row][1];
                min_BT = a[row][2];
                min_row = row;
            }
        }
        cout << "---------------XYZ-----------------"<< endl;
        cout << "mini arrival : " << min_av[0]<<endl;
        cout << "mini id : " << min_id[0] << endl;
        cout << "row number : " << min_row << endl;
        cout << "min row size : " << a[min_row].size();

        if(clk<min_av[0]){
            clk=min_av[0];

        }

        if(a[min_row].size() >=3){
            clk=clk+a[min_row][2][0];
            BT[min_id] += a[min_row][2][0];
            a[min_row][1][0] = clk + a[min_row][2][1];

            if(a[min_row][2].size()!=0){
                a[min_row].erase(a[min_row].begin() + 2);
               
            }
            

        }
        if(a[min_row].size()==2){
            i++;
            CT[min_id] = clk;
          //  cout << "completion time of" << min_id[0] << ":"<< clk <<endl;
    
    }
    }

cout << "-----------------------Priority----------------------------------"<<endl;
   
    cout << "P_ID    : ";
    for(int i=0;i<result.size();i++){
         for(int j=0;j<1;j++){
            cout << result[i][j] << "  - ";         
        }
    }cout << endl;

    cout << "Arr_tim : ";
    for(int i=0;i<result.size();i++){
         for(int j=1;j<2;j++){
            cout << result[i][j] << "   -  ";         
        }
    }cout << endl;

    cout << "compl_T : ";
    for(int i=0;i<result.size();i++){
        for(int j=2;j<3;j++){
            for(map<vector<int>,int>::const_iterator it = CT.begin(); it != CT.end(); ++it) {
                if(result[i][0] == it->first[0]){
                    result[i][j] = it->second;
                    result[i][j+1] = result[i][j] - result[i][j-1];
                    cout << result[i][j] << "  -  ";
                } 
            }
            for(map<vector<int>,int>::const_iterator it = BT.begin(); it != BT.end(); ++it) {
                if(result[i][0] == it->first[0]){
                    result[i][j+2] = result[i][j+1] - it->second;
                } 
            }     
        }
    }
    cout << endl;

    cout << "TAT     : ";
    float avg_TAT = 0;
    for(int i=0;i<result.size();i++){
         for(int j=3;j<4;j++){
            cout << result[i][j] << "  -  ";   
            avg_TAT +=  result[i][j]; 
           // cout << result[i][j] << "  -  ";     
        }
    }cout << endl;

    cout << "WT      : ";
    float avg_WT = 0;
    for(int i=0;i<result.size();i++){
         for(int j=4;j<5;j++){
            cout << result[i][j] << "  -  ";    
            avg_WT +=  result[i][j];       
        }
    }cout << endl;

    cout << "==================================="<<endl;
    cout << "avg TAT : " << avg_TAT/numProcess << endl;
    cout << "avg WT : " << avg_WT/numProcess  << endl<< endl<< endl<< endl;

    // for (map<vector<int>,int>::const_iterator it = CT.begin(); it != CT.end(); ++it) {
    //     cout << it->first[0] << "  ||   " << it->second << std::endl;
    // }

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
    // for (const auto& row : matrix) {
    //     for (const std::string& value : row) {
    //         std::cout << value << " ";
    //     }
    //     std::cout << std::endl;
    // }
    size_t numRows = matrix.size();
    size_t numColumns = (numRows > 0) ? matrix[0].size() : 0;

    // std::cout << "Number of rows: " << numRows << std::endl;
    // std::cout << "Number of columns: " << numColumns << std::endl;

    

    int newMatrix[numRows-1][7];

    for(int i=1; i<=numRows-1; i++){
            for(int j=0;j<numColumns;j++){
                int intValue = std::stoi(matrix[i][j]);
                newMatrix[i-1][j] = intValue;
               // std::cout << newMatrix[i-1][j]<< "\t";
        }
        //std::cout << std::endl;
    }

    

    int num_processes = numRows-1;


    vector<vector<vector<int>>> v;

   // cout << "v size : " << v.size() << endl;

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

    

    priority(num_processes, v);

      return 0;
}  