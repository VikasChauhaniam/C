#include<iostream>
using namespace std;


int countBits(int val, int bits){

    while(val){
        int setBit = val&1;

        if(setBit){
            bits++;
        }

        val = val>>1;
    }
    return bits;
}

int main(){

    int a,b,setBits = 0;

    cout << "Provide a :";
    cin >> a;
    cout << "Provide b :";
    cin >> b;

    setBits = countBits(a, setBits);
    setBits = countBits(b, setBits);

    cout << "total SetBits are : " << setBits << endl<<endl;
    return 0;
}