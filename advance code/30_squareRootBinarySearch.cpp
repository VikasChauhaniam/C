#include<iostream>
using namespace std;
#include<math.h>

int binarySearch(int arr[],int size, int key){

    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    int ans =-1;


    while(start<=end){

       long long int square = pow(arr[mid],2);

       if(key==square){
           return mid;
       }  
       else if(square>key){

           end = mid-1;
       }
       else{
           ans = mid;
           start = mid+1;
       }
       mid = (start+end)/2;
    }
    return ans;

}

double morePrecision(int n, int val, int precision){

    double factor=1;
    double ans = (double)val;

    for(int i=1; i <= precision; i++){
        factor = factor/10;

        for(float j=ans; j*j<n; j=j+factor){
               ans =j;         
        }
    }
    return ans;
}

int main(){
    
    
     int root;

    cout << "Enter Search element : ";
    cin >> root;

    int arr[root] = {0};

    for(int i=0;i<root;i++){
        arr[i] = i;
    }
    
    int intUnderRoot =  binarySearch(arr,root, root);

    cout << "underoot of "<<root<<" is "<<intUnderRoot<< endl<<endl;

    int precision;
    cout << "how much digit precision u want : ";
    cin >> precision;

    double value = morePrecision(root, intUnderRoot, precision);

    cout << "underoot of "<<root<<" is "<<value<< endl<<endl;
        
    return 0;
}