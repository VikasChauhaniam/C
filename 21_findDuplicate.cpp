#include<iostream>
using namespace std;


int findDuplicate(int arr[],int size){
    int ans = 0;

    for(int i=0;i<size;i++){
        //cout <<endl<<i<<" index value is : ";
        ans = ans^arr[i];
    }

    for(int i=1;i<size;i++){
        //cout <<endl<<i<<" index value is : ";
        ans = ans^i;
    }
    return  ans;
}

int main(){

    int arr[100];
    int size,sum=0;

    cout << "Enter size of array : ";
    cin >> size;

    cout << endl<< "Enter  values 1 to size-1 and any one value repeat: ";

    for(int i=0;i<size;i++){
        //cout <<endl<<i<<" index value is : ";
        cin >> arr[i];
    }

    int x= findDuplicate(arr,size);

    if(x){
        cout <<endl << "duplicate element is : "<<x <<endl<<endl;
    }
    else{
        cout <<endl << "NO DUPLICATE ELEMNT" << endl<<endl;
    }

    return 0;
}