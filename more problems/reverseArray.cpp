#include<iostream>
using namespace std;
#include<vector>

void reverse(vector<int> &arr){
    int end = arr.size()-1;
    int start = 0;

    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main(){
    
    
    vector<int> arr1{1,2,3,4,5};
    vector<int> arr2{1,2,3,4,5,6};
    
    
    reverse(arr1);
    for(auto i:arr1)
        cout<<i<<" ";

    cout<<endl<<endl;

    reverse(arr2);
    for(auto i:arr2)
        cout<<i<<" ";
    
    cout<<endl<<endl;
    return 0;
}