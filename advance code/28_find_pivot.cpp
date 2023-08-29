#include<iostream>
using namespace std;


int findpivot(int array[], int size){

    int s = 0;
    int e = size-1;
    int mid = s+(e-s)/2;

    while(s<e){

        if(array[mid]>=array[s]){
            s=mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;

}

int main(){
    
    
    int srArray[5] = {4,6,1,2,3};  //srArray is sorted rotated array

    int pvt = findpivot(srArray, 5);

    cout << "pivot element : " << pvt << endl<<endl<<endl;
    
    return 0;
}