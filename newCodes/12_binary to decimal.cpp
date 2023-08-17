#include<iostream>
using namespace std;
#include<math.h>

int main(){

    int binaryNum ; 
    cout << "please provide number : ";
    cin >> binaryNum;

    int reminder;
    int count = 0;
    int decimalNum;

    while(binaryNum){
        reminder = binaryNum%10;
        binaryNum = binaryNum/10;

        if(reminder){
            decimalNum = decimalNum + pow(2,count);
        }
        count++;
    }

    cout << endl << "decimal number  : " << decimalNum << endl << endl;

    return 0;
}
