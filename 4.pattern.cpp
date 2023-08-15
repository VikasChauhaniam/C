#include<iostream>
using namespace std;

int main(){

    int num;

    cout << "Enter the num value :";
    cin >> num;

    int i=1;

    while(i<=num){
        int j = 1;

        while(j<=num){
            cout << num-j+1;        // cout << j;
            j++;
        }
        cout << endl;
         i++;
    }

    return 0;
}