#include<iostream>
using namespace std;
#include<math.h>
#include <limits.h>

int main(){

   // int INT_MAX = ;
   //int INT_MIN = ;
    int oldN,newN = 0; 
    int signbit = 1;
    cout << "please provide number : ";
    cin >> oldN;

    if(oldN<0){
        signbit = -1;
        oldN = signbit*oldN;
        cout << "negative number" << endl;
    }

    while(oldN){

        if(newN > INT_MAX/10 || newN < INT_MIN/10){
            return 0;
        }
        newN = (oldN%10) + newN*10;
        oldN = oldN/10;
    }

    newN = signbit*newN; 
    cout << "new number : " << newN << endl<<endl;

    return 0;
}