#include<iostream>
using namespace std;

int main(){

    int col, count;

    cout << "Enter the col value :";
    cin >> col;

    cout << "Enter the last count value :";
    cin >> count;

    int i=1;

    while(i<=count){
        int print_count = 0;

        while(print_count<col && i<=count){
            cout << i << "\t";
            i++;
            print_count++;
        }

        cout << endl;

    }
    return 0;
}