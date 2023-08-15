#include<iostream>
#include<cmath>

using namespace std;

int main(){

    double age;
    char gender;
    string name;

    
    cout << "\nplease enter ur Name: "; 
    getline(cin, name);

    cout << "please enter ur age: "; 
    cin >> age;
    cout << "\nplease enter ur Gender M/F: "; 
    cin >> gender;

    cout << "\nYour Name: "<< name << endl << "your age : " << age << endl << "your gender : " << gender << endl; 
    return 0;
}