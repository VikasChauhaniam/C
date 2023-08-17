#include<iostream>
using namespace std;
#include<vector>
#include<math.h>

int main(){

    int n;
    

    cout << "provide num : ";
    cin >> n; 
    // vector<int> i;
    // while(n){
    //     i.push_back(n&1);
    //     n = n>>1; 
    // }

    // for (int x =i.size() - 1; x >= 0; x--) {
    //     cout << i[x] << " ";
    // }

    int index = 0;
    int ans = 0;
    while(n){
        int bit = n&1;
        n = n >> 1;

        ans = (bit * pow(10,index)) + ans;
        index++;
    }

    cout << "answer is : " << ans;

}