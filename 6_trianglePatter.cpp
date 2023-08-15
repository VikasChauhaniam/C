#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "enter n :";
    cin >> n;

    // for(int i=1;i<=n;i++){
    //     for(int j=1; j<=i;j++){
    //         cout << "*" << "\t";
    //     }
    //     cout << endl;
    // }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i; j++){
    //         cout << i <<"\t";
    //     }
    //     cout << endl;
    // }

    // int k=1;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i; j++,k++){
    //          cout << k <<"\t";
    //      }
    //      cout << endl;
    //  }
    // return 0;
    
    
    // for(int i=1; i<=n; i++){

    //     int k=i;
    //     for(int j=1; j<=i; j++,k++){
    //          cout << k <<"\t";
    //      }
    //      cout << endl;
    //  }

    // for(int i=1; i<=n; i++){

    //     //int k=i;
    //     for(int j=1; j<=i; j++){    //k--
    //          cout << i-j+1 <<"\t";  //k
    //      }
    //      cout << endl;
    //  }

    //char c = 'A';
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << c <<"\t";
    //     }
    //     cout << endl;
    //     c++;
    // }    

    // for(int i=1; i<=n; i++){
    //     char c = 'A';
    //     for(int j=1; j<=n; j++,c++){
    //         cout << c <<"\t";
    //     }
    //     cout << endl;
    // } 

    // char c = 'A';
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++,c++){
    //         cout << c <<"\t";
    //     }
    //     cout << endl;
    // } 

    // char c = 'A';
    // for(int i=1; i<=n; i++){
    //     char x = c+i-1;
    //     for(int j=1; j<=n; j++,x++){
    //         cout << x <<"\t";
    //     }
    //     cout << endl;
    // } 

    // char c = 'A';
    // for(int i=1; i<=n; i++){
    //     char x = c+i-1;
    //     for(int j=1; j<=n; j++,x++){
    //         cout << x <<"\t";
    //     }
    //     cout << endl;
    // } 

    // char c = 'A';
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i; j++,c++){
    //         cout << c <<"\t";
    //     }
    //     cout << endl;
    // } 

    
    // for(int i=1; i<=n; i++){
    //     char c = 'A' +i-1;
    //     for(int j=1; j<=i; j++,c++){
    //         cout << c <<"\t";
    //     }
    //     cout << endl;
    // } 

    // for(int i=1; i<=n; i++){
    //     char c = 'A' +n-i;
    //     for(int j=1; j<=i; j++,c++){
    //         cout << c <<"\t";
    //     }
    //     cout << endl;
    // } 



    // for(int i=1; i<=n; i++){

    //     for(int k=n-i; k>=1; k--){
    //         cout << "4" << "\t";
    //     }
    //     for(int j=1; j<=i; j++){
    //         cout << "*" << "\t";
    //     }
    //     cout << endl;
    // }

    // for(int i=1; i<=n; i++){

    //     for(int k=1; k<=i-1; k++){
    //         cout << "" << "\t";
    //     }
    //     for(int j=i; j<=n; j++){
    //         cout << "*" << "\t";
    //     }
    //     cout << endl;
    // }


    // for(int i=1; i<=n; i++){

    //     for(int k=1; k<=i-1; k++){
    //         cout << "" << "\t";
    //     }
    //     for(int j=i; j<=n; j++){
    //         cout << i << "\t";
    //     }
    //     cout << endl;
    // }

    // for(int i=1; i<=n; i++){

    //     for(int k=1; k<=n-i; k++){
    //         cout << "" << "\t";
    //     }
    //     for(int j=1; j<=i; j++){
    //         cout << i << "\t";
    //     }
    //     cout << endl;
    // }

    // for(int i=1; i<=n; i++){

    //     for(int k=1; k<=i-1; k++){
    //         cout << "" << "\t";
    //     }
    //     for(int j=i; j<=n; j++){
    //         cout << j << "\t";
    //     }
    //     cout << endl;
    // }

    // int x = 1;
    // for(int i=1; i<=n; i++){

    //     for(int k=1; k<=n-i; k++){
    //         cout << "" << "\t";
    //     }
    //     for(int j=1; j<=i; j++,x++){
    //         cout << x << "\t";
    //     }
    //     cout << endl;
    // }

    // for(int i=1; i<=n; i++){

    //     for(int k=1; k<=n-i; k++){
    //         cout << "" << "\t";
    //     }
    //     for(int j=1; j<=i; j++,x++){
    //         cout << x << "\t";
    //     }
    //     cout << endl;
    // }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n-i;j++){
    //         cout << "" << "\t";
    //     }

    //     for(int k=1; k<=i; k++){
    //         cout << k << "\t";
    //     }

    //     for(int l=1; l<=i-1; l++){
    //         cout << i-l << "\t";
    //     }
    //     cout << endl;
    // }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1;j++){
            cout << j << "\t";
        }

        for(int k=1; k<=(i-1)*2; k++){
            cout << "*" << "\t";
        }

        for(int l=1; l<=n-i+1; l++){
            cout << n-i-l+2 << "\t";
        }
        cout << endl;
    }

    return 0;
}