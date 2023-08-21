#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int noOfSwaps = 0;
    cout << "Enter the dimension of matrix : " <<endl;
    cin >> n;

    double arr[n][n];
    double P[n][n]; // Permutation matrix
    double L[n][n]; // Lower unit matrix
    double U[n][n]; // Upper matrix

    int pie[n]; // for tracking row  swap number

    for (int i = 0; i < n; i++)
    { // initialising with 0 values

        for (int j = 0; j < n; j++)
        {

            P[i][j] = 0;
            L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    cout << "Enter the elements of matrix " << endl;
    for (int row = 0; row < n; row++) // inputting matrix
    {
        for (int column = 0; column < n; column++)
        {
            cin >> arr[row][column];
        }
    }
    for (int i = 0; i < n; i++)
    {
        pie[i] = i;
    }

    int maxIndex = -1;
    for (int k = 0; k < n; k++)
    {
        double max = 0;
        for (int i = k; i < n; i++) // finding max in column
        {
            if (abs(arr[i][k]) >= max)
            {
                max = abs(arr[i][k]);
                maxIndex = i;
            }
        }

        if (max == 0)
        {
            cout << "Singular Matrix ";
            return -1;
        }
        else // swapping rows
        {
            swap(pie[k], pie[maxIndex]);

            for (int i = 0; i < n; i++)
            {
                swap(arr[k][i], arr[maxIndex][i]);
            }
            if(k!=maxIndex)
            noOfSwaps++;
        }

        for (int i = k + 1; i < n; i++)
        {
            arr[i][k] /= arr[k][k];

            for (int j = k + 1; j < n; j++)
            {
                arr[i][j] = arr[i][j] - (arr[i][k] * arr[k][j]);
            }
        }
    }

    for (int t = 0; t < n; t++) // making diagonal entries 1
    {
        L[t][t] = 1;
    }

    for (int row = 0; row < n; row++) // deriving L and U matrix from transformed matrix
    {
        for (int column = 0; column < n; column++)
        {
            if (column >= row)
            {
                U[row][column] = arr[row][column];
            }
            else
            {
                L[row][column] = arr[row][column];
            }
        }
    }

    for (int i = 0; i < n; i++) // putting values in permutation matrix
    {
        P[i][pie[i]] = 1;
    }

    cout << endl;
    cout << " Transformed matrix is " <<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // printing new Transformed matrix
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << " Upper triangular matrix is " <<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // printing Upper triangular matrix
        {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Lower triangular matrix is " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // printing Lower triangular matrix
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Permutation matrix is " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // printing Permutation matrix
        {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
cout<<"determinent of matrix is : "<<endl;
double det=1;
for(int i=0;i<n;i++)
{
    det*=U[i][i];
}
if(noOfSwaps%2==1)
{
    det=det*(-1);
}
cout<<det<<endl;;
}