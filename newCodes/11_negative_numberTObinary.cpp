#include<iostream>
using namespace std;
#include<math.h>

int main(){

    int n;
    cout << "provide -ve number : ";
    cin >> n; 

    int newNum = -1*n;

    int index = 0;
    int ans[8] = {0};


    for(int i=7; i>=0; i--){
        
        if(newNum){
            
            int bit = !(newNum&1);

            newNum  = newNum  >> 1;
            ans[i] = bit;
        }
        else{
            ans[i] = 1;
        }
        
    
    }


    cout << "Value is : " ;
    for(int i=0; i <8; i++){
        cout << ans[i] << "  ";
    }

    cout << endl << endl << endl;

    int isone = 0;
    //cout << "1" <<endl;
    for(int i=7; i >=0; i--){

        if(isone == 0){
            if(ans[i]==1){
            ans[i] = 0;
           // cout << "2" <<endl;
            }
            else{
                ans[i] = 1;
                 isone = 1;
            //cout << "3" <<endl;
            }
        }
        
        
        //cout << "index " << i  << " : " << ans[i] <<endl;
        
    }

     cout << "Value is : " ;
    for(int i=0; i <8; i++){
        cout << ans[i] << "  ";
    }

    cout << endl << endl << endl;
}