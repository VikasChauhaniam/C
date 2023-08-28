#include <bits/stdc++.h>

using namespace std;

int main()
{
    string myText;

    ifstream MyReadFile("filename.txt");
    
    vector<vector<string>> p;

    while (getline (MyReadFile, myText)) {
        string s;
        stringstream ss(myText);
        vector<string> v;
        while (getline(ss, s, ' ')) {
            v.push_back(s);
        }
        
        p.push_back(v);
    }
    
    MyReadFile.close();
 
    for(auto process: p){
        for(auto x: process) cout<< x << " ";
        cout << endl;
    }
    return 0;
}