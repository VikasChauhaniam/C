#include<iostream>
using namespace std;

int febNum(int n){
    int num,first=0,second=1;

    if(n==1){
        num = first;
    }
    else if(n==2){
        num = second;
    }
    else{
        
        for(int i=3; i<=n;i++){
            num = first + second;
            first = second;
            second = num;
        }
    }

    return num;

}

int main(){

    int n, num;

    cout << "Provide n :";
    cin >> n;
    

    num= febNum(n);
    

    cout << n<< "th febonnaci number is : " << num << endl<<endl;
    return 0;
}