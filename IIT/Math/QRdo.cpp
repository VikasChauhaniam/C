#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void qrDecomposition(vector<vector<double>>& A,
                     vector<vector<double>>& Q,
                     vector<vector<double>>& R){

                        int m = A.size();
                        int n = A[0].size();

                        Q.resize(m, vector<double>(n, 0.0));
                        R.resize(m, vector<double>(n, 0.0));

                        
         
        for(int col=0; col<n; col++){
            vector<double> v(m, 0.0);

            for(int i=0; i<m; i++){
                v[i] = A[i][col];
            }

            for (int i = 0; i < col; ++i) {
                
                double result = 0.0;

                for (int j = 0; j < Q[i].size(); ++j) {
                    result += Q[i][j] * v[j];
                }

                //R[i][col] = result;
            
                for (int j = 0; j < m; ++j) {
                     v[j] -= result * Q[i][j];
                 }
            }

            double length = 0.0;

            for (double value : v) {
                length += value * value;
            }
            
            length = sqrt(length);
    
            for (double& value : v) {
                value /= length;
            }

            for (int i = 0; i < m; ++i) {
                 Q[col][i] = v[i];
            }
        }

        vector<vector<double>> P;
        P.resize(m, vector<double>(n, 0.0));

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<m; j++){
        //         P[i][j] = Q[j][i];
        //     }
        // }

        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                for(int k =0; k<m;k++){
                    R[i][j] += Q[i][k] * A[k][j];
                }                
            }
        }
    


} 


int main(){
    
   
    vector<vector<double>> A{
        {1, 2, 6},
        {0, 0, 7},
        {0, 5, 12}
    };

    // vector<vector<double>> A{
    //     {1, 0, 2},
    //     {0, 2, 0},
    //     {0, -1, 1}
    // };

    cout << "Matrix A:" << endl;
    for (const auto& row : A) {
        for (double value : row) {
            std::cout << value << "\t";
        }
        cout << endl;
    }

    vector<vector<double>> Q, R;

    qrDecomposition(A, Q, R);

    cout << "Matrix Q:" << endl;
    for (const auto& row : Q) {
        for (double value : row) {
            std::cout << value << "\t";
        }
        cout << endl;
    }

    cout << "Matrix R:" << endl;
    for (const auto& row : R) {
        for (double value : row) {
            std::cout << value << "\t";
        }
        cout << endl;
    }
    
    
    return 0;
}