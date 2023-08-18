#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "enter a num : ";
    cin >> n;

    int rmdr = 0;
    while(n){
        rmdr = n%2;
        n = n/2;
        
        if(n==1 && rmdr==0){
            cout << "its 2s power number" << endl;
            break;
        }
    }
    cout << "OVER" <<endl<<endl<<endl;
    return 0;
}