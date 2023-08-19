#include<iostream>
using namespace std;
#include<limits.h>


void findintersaction(int arr[],int size1, int brr[],int size2){
    //int ans = 0;

    for(int i=0;i<size1;i++){
        for(int j=0; j<size2;j++){

            if(arr[i] == brr[j]){
                cout << arr[i];
                brr[j] = INT_MIN;
                continue;
            }
            cout <<  " ";
        }
    }

    
}

int main(){

    int arr[100];
    int size1;

    cout << "Enter size of array : ";
    cin >> size1;

    cout << endl<< "Enter  values 0 to more in non decreasing order: ";
    for(int i=0;i<size1;i++){
        //cout <<endl<<i<<" index value is : ";
        cin >> arr[i];
    }

    //------------------------------------------------------------------------------

    int brr[100];
    int size2;

    cout << "Enter size of array : ";
    cin >> size2;

    cout << endl<< "Enter  values 0 to more in non decreasing order: ";
    for(int i=0;i<size2;i++){
        //cout <<endl<<i<<" index value is : ";
        cin >> brr[i];
    }
    

    findintersaction(arr,size1,brr,size2);

    

    return 0;
}