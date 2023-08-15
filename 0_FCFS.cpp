#include<iostream>
using namespace std;



void fcfs(int nprocess, int nBurst, int arrivalT[],int (*burstT)[4]){

    int realBurstT[nprocess] = {};


    for(int i=0;i<nprocess;i++)
    {
        for(int j=0;j<nBurst;j++)
        {
            realBurstT[i] += burstT[i][j];
        } 
   
    }
    for(int i=0;i<nBurst;i++)
    {
        cout <<"process "<<i<<": arrival time :"<<arrivalT[i]<<": Burst time"<<realBurstT[i]<<endl;
    }

    cout <<"======================================================="<< endl;
    

    int temp;
    for(int i = 0; i<nprocess; i++)
    {
        for(int j = i+1; j<nprocess; j++)   
        {
            if(arrivalT[j] < arrivalT[i]) 
            {
                temp = arrivalT[i];
                arrivalT[i] = arrivalT[j];
                arrivalT[j] = temp;

                temp = realBurstT[i];
                realBurstT[i] = realBurstT[j];
                realBurstT[j] = temp;

                
            }
        }
    }

    for(int i=0;i<nBurst;i++)
    {
        cout <<"process "<<i<<": arrival time :"<<arrivalT[i]<<": Burst time"<<realBurstT[i]<<endl;
    }
}
int main(){

    int numBurst=4,numProcess=4;
    int arrivalT[4] = {2,3,4,3};
    int burstT[4][4] = {{3,2,1,3},
                      {1,1,6,3},
                      {2,5,1,0},
                      {1,2,3,2}};
    cout << burstT << endl;

    
    fcfs(numProcess, numBurst, arrivalT, burstT);

    return 0;
}