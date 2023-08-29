#include<iostream>
using namespace std;

int isPossible(int arr[], int books_num, int std_num, int mid) {

    int std_count = 1;
    int pageSum = 0;

    for(int i=0; i<books_num; i++){
        if((pageSum + arr[i]) <= mid){
            pageSum +=  arr[i];
        }
        else{
            std_count++;
            if(std_count > std_num || arr[i] > mid){
                return false;
            }
            pageSum =  arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int books_num,int std_num){

    int start = 0;
    int sum = 0;

    for(int i=0; i<books_num; i++) {
        sum = sum + arr[i];
    }
    int end =  sum;
    int mid = start + (end-sum)/2;   
    int ans = -1;

    while(start<=end){

        if(isPossible(arr, books_num, std_num, mid)) {
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;

}

int main(){
    
    int arr[5] = {10, 20, 30, 40, 50};
    int books_num = sizeof(arr)/sizeof(int);
    int std_num = 2;
    int minofMaxvalue = allocateBooks(arr, books_num, std_num);

    cout << "minimum of max value : "<< minofMaxvalue;
    return 0;
}