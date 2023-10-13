#include<iostream>
using namespace std;

bool isPalindrome(char name[],int length){

    int s = 0;
    int e = length-1;

    while(s<=e){
        if(name[s]!=name[e]){
            return false;
        }
        s++;
        e--;
    }

    return true;  

}

int getLength(char name[]){

	int count = 0;
	for(int i=0; name[i]!= '\0'; i++){
		count++;
	}
	return count;
}

int main(){
    
    char name[20];

    cout<< "Enter name : ";
    cin >> name;

    int x = getLength(name);
    if(isPalindrome(name, x)){
        cout << "PalinDrome";
    }
    else{
        cout << "Not a Palindrome";
    }
    
    
    return 0;
}