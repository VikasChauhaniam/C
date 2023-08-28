#include<iostream>
#include <fstream>

fstream fs{ "input.txt" }; 
    string s; 
    getline(fs, s);//first line is skipped 
    int count1=0;

    while (fs >> s) 
    { 
        getline(fs,s);
        count1++;
    } 
    cout<<"no of rows are = "<<count1<<endl;
    int arr[count1][8]; //array declared
    fstream fs2{ "input.txt" }; 
    getline(fs2,s);//skip the line as it is text
    char c;
    for(int i=0;i<count1;i++){
        for(int j=0;j<4;j++){    
            fs2 >> arr[i][j];
        }
    }

    for(int i=0;i<count1;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }