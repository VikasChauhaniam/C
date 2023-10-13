#include<iostream>
using namespace std;
#include<math.h>

int main(){
    
    
    int treeHeight;
    cout<<"Enter tree height : ";
    cin>> treeHeight;

    if(treeHeight <0){
        return 0;
    }

    int treeVal = pow(2,(treeHeight+1))-1;
    cout<< treeVal;
    
    int arr[treeVal];

    for(int i=0;i<treeVal;i++){
        cin>>arr[i];

    }

    int sum=0;

    for(int h=0;h<treeHeight;h+=2){
        for(int i=pow(2,treeHeight)-1;i<=(pow(2,treeHeight)-1)*2;i++){
            if(arr[i]>=0){
                sum+=arr[i];
            }
        }
    }
    cout << sum;
    return sum;
}