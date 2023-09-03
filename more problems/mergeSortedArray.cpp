#include<iostream>
using namespace std;
#include<vector>

vector<int> sortANDmerge(vector<int> arr1, vector<int> arr2){
    vector<int> newArray;


    while(arr1.size() !=0 || arr2.size()!=0){
        if(arr1[i]<arr2[j]){
            newArray.push_back(arr1[i]);

            i++;
        }
        else if(arr1[i]>arr2[j]){
            newArray.push_back(arr2[j]);
            j++;
        }
        else{
            newArray.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return newArray;
}

int main(){
    
    
    vector<int> arr1{13,17,23,24,52};
    vector<int> arr2{1,5,15,21,29,38,62};
    
    
    vector<int> sortedArray = sortANDmerge(arr1, arr2);
    for(auto i:sortedArray)
        cout<<i<<" ";
    
    cout<<endl<<endl;
    return 0;
}