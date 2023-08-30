#include<iostream>
using namespace std;

void insertion(int arr[], int size){

    for(int i=1; i<size; i++){

        for(int j=i; j>0; j--){

            if(arr[j]<arr[j-1]){

                swap(arr[j], arr[j-1]);
            }
        }
        
        for(int i=0; i<size; i++){
        cout << arr[i] << " ";
        }cout <<endl;
                
    }
}


int main(){
    
    int arr[10] = {5,7,6,10,2,1,4,9,8,3};
    int size = sizeof(arr)/sizeof(int);

    insertion(arr,size);
    
    return 0;
}