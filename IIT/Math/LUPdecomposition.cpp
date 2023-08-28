#include<bits/stdc++.h>
using namespace std;

void LUP(vector<vector<double>> A, vector<vector<double>> &L, vector<vector<double>> &U, vector<double> &P){
  if(A.size() == 1) {
    L[0][0] = 1;
    U[0][0] = A[0][0];
    if(!U[0][0]){
      cout << "Singular Matrix" <<endl;
      exit(0);
    }
    return;
  };

  double max = 0, maxIndex = -1;
  vector<double> Q(A.size());
  for(int i=0; i<A.size(); i++) Q[i] = i;

  for(int i=0; i<A.size(); i++){
    if(abs(A[i][0]) > max){
      max = abs(A[i][0]);
      maxIndex = i;
    }
  }

  if(maxIndex == -1){
    cout << "Singular Matrix" <<endl;
    exit(0);
  }

  swap(Q[0], Q[maxIndex]);
  swap(A[0], A[maxIndex]);

  double A11 = A[0][0];

  double m = A.size()-1;

  vector<double> P1(m);
  vector<vector<double>> A1(m, vector<double>(m)), L1(m, vector<double>(m)), U1(m, vector<double>(m));
  for(int i=0; i < m; i++) P1[i] = i;

  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      A1[i][j] = A[i+1][j+1] - (A[i+1][0] * A[0][j+1] / A11);
    }
  }

  LUP(A1, L1, U1, P1);

  L[0][0] = 1;
  for(int i = 1; i < L.size(); i++) L[i][0] = (A[P1[i-1]+1][0]) / A11;

  for(int i = 0; i < L1.size(); i++){
    for(int j = 0; j< L1[i].size(); j++){
      L[i+1][j+1] = L1[i][j];
    }
  }

  U[0][0] = A11;
  for(int i = 1; i < U[0].size(); i++) U[0][i] = A[0][i];
  for(int i = 0; i < U1.size(); i++){
    for(int j = 0; j< U1[i].size(); j++){
      U[i+1][j+1] = U1[i][j];
    }
  }

  for(auto &val: P1) val++;

  P1.insert(P1.begin(), 0);

  for(int i = 0; i < P.size(); i++) P[i] = Q[P1[i]];

  return;
}

int main(){
  cout << "Enter the dimension of the square matrix: ";
  double n; cin >> n;
  vector<vector<double>> A(n, vector<double>(n));

  vector<vector<double>> L(n, vector<double>(n)), U(n, vector<double>(n));
  vector<double> P(n);

  for(int i=0; i < n; i++) P[i] = i;

  cout << "Enter the matrix" << endl;

  for(auto &row: A){
    for(auto &cell: row) cin >> cell;
  }

  LUP(A, L, U, P);

  cout << endl << "A matrix: " << endl;
  for(auto row: A){
    for(auto cell: row) cout << cell << " ";
    cout << endl;
  }

  cout << endl << "P matrix: " << endl;
  for(int i= 0; i<A.size(); i++){
    for(int j=0; j<A.size(); j++){
      if(P[i] == j) cout << 1 << " ";
      else cout << 0 << " ";
    }
    cout << endl;
  }

  cout << endl << "L matrix: " << endl
;
  for(auto row: L){
    for(auto cell: row) cout << cell << " ";
    cout << endl;
  }

  cout << endl << "U matrix: " << endl;
  for(auto row: U){
    for(auto cell: row) cout << cell << " ";
    cout << endl;
  }
}