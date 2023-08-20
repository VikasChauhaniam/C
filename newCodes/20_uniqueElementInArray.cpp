#include<iostream>
using namespace std;


int findUinque(int arr[],int size){
    int ans = 0;

    for(int i=0;i<size;i++){
        //cout <<endl<<i<<" index value is : ";
        ans = ans^arr[i];
    }
    return  ans;
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

    int x= findUinque(arr,size);

    if(x){
        cout <<endl << "unique element is : "<<x <<endl<<endl;
    }
    else{
        cout <<endl << "NO UNIQUE ELEMNT" << endl<<endl;
    }

    return 0;
}