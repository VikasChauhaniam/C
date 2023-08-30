#include<iostream>
using namespace std;

void selection(int arr[], int size){

    //cout << "size is : "<< size << endl << endl << endl;

    for(int i=0; i<size-1; i++){
        int index = -1;
        int min = arr[i];

        for(int j=i+1; j<size; j++){
                    
            if(arr[j]<min){
                min = arr[j];
                index = j;
            }
        }
        //cout << "iteration "<<i<<" min "<< min<<" at index "<< index<<endl<<endl<<endl;
        swap(arr[i], arr[index]);


        for(int i=0; i<size; i++){
        cout << arr[i] << " ";
        }cout <<endl;

        //cout<<endl<<"swap elemet are "<< arr[i] << " and " << arr[index]<< endl;
    }
}

int main(){
    
    int arr[5] = {5,7,6,2,1};
    int size = sizeof(arr)/sizeof(int);

    //cout << "size is : "<< size << endl << endl << endl;

    selection(arr,size);

    //cout << "size is : "<< size << endl << endl << endl;
    
    // for(int i=0; i<size; i++){
    //     cout << arr[i] << " ";
    // }
    
    return 0;
}