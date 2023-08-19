#include<iostream>
using namespace std;

void alterSwap(int arr[],int size){

    
    for(int i=0;i<size-1;i=i+2){
        swap(arr[i],arr[i+1]);
    }
}

int main(){

    int arr[100];
    int size,sum=0;

    cout << "Enter size of array : ";
    cin >> size;

    cout << endl<< "Enter  values : ";

    for(int i=0;i<size;i++){
        //cout <<endl<<i<<" index value is : ";
        cin >> arr[i];
    }

    alterSwap(arr,size);

    for(int i=0;i<size;i++){
        //cout <<endl<<i<<" index value is : ";
        cout << arr[i]<< " ";
    }


    return 0;
}