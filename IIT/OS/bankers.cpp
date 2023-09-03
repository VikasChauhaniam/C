#include<iostream>
using namespace std;
#include<vector>

int main(){
    
    int numberOfProcess,resourceType;

    cout << " enter number of process : ";
    cin >> numberOfProcess;

    cout << endl;

    cout << " enter number of resource types: ";
    cin >> resourceType;

    //-------------------------------------ALLOCATION MATRIX----------------------------------------

    vector< vector<int>> alloc(numberOfProcess, vector<int> (resourceType));

    cout << "provide data for allocation matrix : "<<endl;
    for(int i=0; i<alloc.size(); i++){
        for(int j=0; j<alloc[i].size(); j++){
            cin >> alloc[i][j];
        }
    }

    // cout <<endl<< "MATRIC CONTENT IS"<<endl;
    // for(int i=0; i<alloc.size(); i++){
    //     for(int j=0; j<alloc[i].size(); j++){
    //         cout << alloc[i][j] << " ";
    //     }
    //     cout << endl;
    // }

//-------------------------------------MAX REQUEST MATRIX----------------------------------------

    vector< vector<int>> max(numberOfProcess, vector<int> (resourceType));

    cout << "data for Max resource request matrix"<<endl;
     for(int i=0; i<max.size(); i++){
        for(int j=0; j<max[i].size(); j++){
            cin >> max[i][j];
        }
    }

    //-------------------------------------AAVAILABLE RESOURCES----------------------------------------

    vector<int> available(resourceType);

    cout << "proice available resource for each "<< resourceType << "resource type"<<endl;
    for(int i=0; i<resourceType; i++){
            cin >> available[i];
        }

    //-----------------------------------Requirement Resource matrix---------------------------------    

    vector< vector<int>> Required(numberOfProcess, vector<int> (resourceType));

    cout << "data for Max resource request matrix"<<endl;
     for(int i=0; i<Required.size(); i++){
        for(int j=0; j<Required[i].size(); j++){
            Required[i][j] = max[i][j] - alloc[i][j];
        }
    }

    
    vector<int> flagProcess(numberOfProcess, 0); // initialise flagprocess array with 0 

    vector<int> ans(numberOfProcess);
    int indx = 0;
    int y = 0;

    for(int k=0; k<numberOfProcess; k++){
        for(int i=0; i<numberOfProcess; i++){
            if(flagProcess[i] == 0){

                int flag = 0;

                for(int j=0; j<resourceType; j++){
                    if(Required[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }

                if( flag == 0){
                    ans[indx++] = i;

                    for(int y=0; y<resourceType; y++){
                        available[y] += alloc[i][y];
                    }
                    flagProcess[i] = 1;
                }
            }
        }

    }

    int flag = 1;

    // To check if sequence is safe or not
  for(int i = 0;i<numberOfProcess;i++)
  {
        if(flagProcess[i]==0)
      {
        flag = 0;
        cout << "The given sequence is not safe";
        break;
      }
  }
 
  if(flag==1)
  {
    cout << "Following is the SAFE Sequence" << endl;
      for (int i = 0; i < numberOfProcess - 1; i++)
        cout << " P" << ans[i] << " ->";
      cout << " P" << ans[numberOfProcess - 1] <<endl;
  }

    
    
    return 0;
}