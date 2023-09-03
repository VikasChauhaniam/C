#include<iostream>
using namespace std;

void bubble(int arr[], int size){

    for(int i=0; i<size; i++){
        int isSwap = false;
        for(int j=0; j<size-1; j++){
            
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
                
        }
        if(!isSwap)
            return;

        for(int i=0; i<size; i++){
        cout << arr[i] << " ";
        }cout <<endl;

    }
}

int main(){
    
    int arr[5] = {5,7,6,2,1};
    int size = sizeof(arr)/sizeof(int);

    bubble(arr,size);
    
    return 0;
}