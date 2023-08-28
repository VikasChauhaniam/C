#include<iostream>
using namespace std;

void reverseArray(int arr[],int size){

    int iter = (size/2)-1;

    for(int i=0;i<=iter;i++){
        // int temp = arr[i];
        // arr[i] = arr[size-1-i];
        // arr[size-1-i] = temp;
        swap(arr[i],arr[size-1-i]);
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

    reverseArray(arr,size);

    for(int i=0;i<size;i++){
        //cout <<endl<<i<<" index value is : ";
        cout << arr[i]<< " ";
    }


    return 0;
}