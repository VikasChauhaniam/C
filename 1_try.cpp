#include<iostream>
#include<vector>
using namespace std;

int main(){


    int arr[][7] = {
        {0,2,1,2,2,1,3},
        {1,3,1,1,3,1,2},
        {2,1,3,1,1,2,2}};



    vector<vector<vector<int>>> v;

    cout << "v size : " << v.size() << endl;

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        vector<vector<int>> temp1;
        for(int j=0;j<sizeof(arr[0])/sizeof(int);j++){
            vector<int> temp2;
            if(j<2){
                temp2.push_back(arr[i][j]);
            }
            else{

                temp2.push_back(arr[i][j]);
                if(j!=6){
                    j++;
                    temp2.push_back(arr[i][j]);
                }
                
            }
                temp1.push_back(temp2);
        }
        v.push_back(temp1);
    }

    for(auto row: v){
        for(auto cell: row){
            for(auto element: cell) {
                cout << element<<",";
            }
            cout << "+"<<cell.size() << "\t\t";
        }
        cout<<"-"<<row.size()<<endl;
    }
    
    return 0;
}