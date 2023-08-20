#include<iostream>
using namespace std;
#include<limits.h>


void sort012(int arr[],int size1){

    
    int start =0;
    int end = size1-1;

    while(start<end){

        while(arr[start]==0 && start<end){
            start++;
        }
        while(arr[end]==2 && start<end){
            end--;
        }

        if(start < end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
        
}

int main(){

    int arr[100];
    int size1;

    cout << "Enter size of array : ";
    cin >> size1;

    cout << endl<< "Enter  values 0 or 1 or 2: ";
    for(int i=0;i<size1;i++){
        //cout <<endl<<i<<" index value is : ";
        cin >> arr[i];
    }

    
    sort012(arr,size1);

    for(int i=0;i<size1;i++){
        //cout <<endl<<i<<" index value is : ";
        cout << arr[i]<< " ";
    }

    return 0;
}