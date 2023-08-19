#include<iostream>
using namespace std;


int sumFxn(int arr[], int size, int sum){
    

    for(int i=0;i<size;i++){
        sum += arr[i];
    }

    return sum;

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

    sum = sumFxn(arr,size,sum);

    cout <<endl<< "sum of array : " << sum<< endl<<endl<<endl;

    return 0;
}