#include<iostream>
using namespace std;

int findpivot(int array[], int size){

    cout<< "size is :"<<size<<endl;
    int s = 0;
    int e = size-1;
    int mid = s+(e-s)/2;

    while(s<e){

        if(array[mid]>=array[0]){
            s=mid+1;
        }
        else{
            e = mid;
        }
        
        mid = s+(e-s)/2;
        //cout << "s: "<<s<<" e:"<<e<<" mid:"<<mid<<endl<<endl;
    }
    //cout << "pivot is : " << s<<endl<<endl;
    return s;

}

int binarySearch(int arr[],int s, int e, int key){

    cout << "---"<<arr[s]<<"----"<<arr[e]<<endl;
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;


    while(start<=end){
       if(key==arr[mid]){
           return mid;
       }
       else if(key>arr[mid]){
           start = mid+1;
       }
       else{
           end = mid-1;
        //   cout<<"valur of end is :"<<end<<endl;
       }
       mid = start + (end - start)/2;
      // cout<<"valur of mid is :"<<mid<<endl;
    }
    return -1;

}

int searchSRarray(int arr[], int size, int key){

    int pvt = findpivot(arr, size);
    //cout << "pvt isis : "<<pvt<<endl;
    if(key>=arr[pvt] && key<=arr[size-1]){
       return binarySearch(arr, pvt, size-1, key);
    }
    else{
        //cout<<"binary search on : "<< pvt-1<<endl;
        return binarySearch(arr, 0, pvt-1, key);
    }

}

int main(){
    
    int srArray[7] = {6,9,11,16,1,3,4};

    int key;
    cout << "enter the element you want to search : ";
    cin >> key;

    int found = searchSRarray(srArray, 7, key);

    if(found>=0){
        cout << "Element "<< key << " present at "<< found <<" index"<<endl<<endl;
    }
    else{
        cout << "Element is not present"<< endl<< endl<< endl;
    } 

    return 0;
}