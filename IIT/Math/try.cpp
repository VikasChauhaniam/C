#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<float> a{1,2,5,6,7};

    for(float& value : a) {
        cout << value<<" ";
    }cout<< endl;
    
    for(float& value : a) {
        value /= 5;
    }
    
    for(float& value : a) {
        cout << value<<" ";
    }
    return 0;
}