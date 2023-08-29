#include<iostream>
using namespace std;

int binarySearch(int arr[],int size, int key){

    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;


    while(start<=end){
       if(key==arr[mid]){
           return mid;
       }
       else if(key>arr[mid]){
           start = mid+1;
       }
       else{
           end = mid-1;
       }
       mid = (start+end)/2;
    }
    return -1;

}

int main(){

    int arr[3] = {1,3,4};
    int key;

    cout << "Enter Search element : ";
    cin >> key;

    int size = sizeof(arr)/sizeof(int);

    int isfound =  binarySearch(arr,size, key);

    if(isfound!=-1){
        cout <<endl<< "element at : " << isfound << " index "<<endl;
    }
    else{
        cout <<endl<< "Element not FOUND";
    }




    return 0;
}