#include<iostream>
using namespace std;

void reverseString(int name[],int length){

    int s=0;
    int e=length-1;

    while(s<=e){
        swap(name[s++],name[e--]);
    }
}

int getLength(char name[]){

	int count = 0;
	for(int i=0; name[i]!= '\0'; i++){
		count++;
	}
	return count;
}
int main(){

	int name[5];
	
	cout<< "ENter name : ";

    for(int i=0;i<=4;i++){
        cin>> name[i];
    }
	
	reverseString(name, 5);

    for(int i=0;i<=4;i++){
        cout <<"name is : " <<i<<" : "<< name[i]<<endl;
    }
    

	return 0;
}
