/*
STRASSEN MATRIX MULTIPLICATION
2D array is declared as a 1D array. Basically a flattened 2D array.
informationa about columns is not recognized by the compiler and 
hence we have to do it on our own.
for a 2D array A[i][j], the equivalent for a 1D array declaration will
be A[i*n + j], where n is the number of columns.

if in any case I want to do implement using proper 2D matrices, then
I can do something like this

void convert2D(int **A, int *index[], int m)
{
    for(int i = 0; i < m; i++)
        index[i] = (int *)A + i*m;
}

void f4(int **A, int m)
{
    int *index[m];
    convert2D(A, index, m);
        
    cout << index[1][1];
}

int main()
{
    int A[][4] = {{3, 6, 9}, {45, 87, 44}, {55, 987, 122}, {88, 44, 100}};
    f4((int **)A, 4);
    return 0;
}

FUNCTIONS:
    addMatrix
    subMatrix
        both the above function perform matrix addition and subtraction tasks
        for int x = 1 , a portion of matrix of size n * n is being filled with
        the result of operation between two matrices of size n/2 * n/2
        while for x = 0, a matrix of size n/2 * n/2 is being filled with the
        result of operation between two matrices of size of n/2 * n/2
    strassen
        recursion function for performing matrix multiplication
*/

#include <iostream>
using namespace std;

void addMatrix(int *A, int *B, int *C, int n, int x)
{
    int m = (x == 1) ? n/2 : n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i * m + j] = A[i * n + j] + B[i * n + j];
}

void subMatrix(int *A, int *B, int *C, int n, int x)
{
    int m = (x == 1) ? n / 2 : n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i * m + j] = A[i * n + j] - B[i * n + j];
}

void strassen(int *A, int *B, int *C, int n)
{
    if (n == 2)
    {
        int P = (A[0] + A[n + 1]) * (B[0] + B[n + 1]);
        int Q = (A[n] + A[n + 1]) * B[0];
        int R = A[0] * (B[1] - B[n + 1]);
        int S = (A[n + 1]) * (B[n] - B[0]);
        int T = (A[0] + A[1]) * (B[n + 1]);
        int U = (A[n] - A[0]) * (B[0] + B[1]);
        int V = (A[1] - A[n + 1]) * (B[n] + B[n + 1]);

        C[0] = P + S - T + V;
        C[1] = R + T;
        C[n] = Q + S;
        C[n + 1] = P + R - Q + U;
    }
    else
    {
        int m = n / 2;
        int x[m * m], y[m * m], o[n * n];

        for (int i = 0; i < n * n; i++)
            o[i] = 0;

        int P[m * m], Q[m * m], R[m * m], S[m * m],
            T[m * m], U[m * m], V[m * m];

        addMatrix(A, A + m * (n + 1), x, n, 1);
        addMatrix(B, B + m * (n + 1), y, n, 1);
        strassen(x, y, P, m);

        addMatrix(A + n * m, A + m * (n + 1), x, n, 1);
        addMatrix(B, o, y, n, 1);
        strassen(x, y, Q, m);

        addMatrix(A, o, x, n, 1);
        subMatrix(B + m, B + m * (n + 1), y, n, 1);
        strassen(x, y, R, m);

        addMatrix(A + m * (n + 1), o, x, n, 1);
        subMatrix(B + n * m, B, y, n, 1);
        strassen(x, y, S, m);

        addMatrix(A, A + n * m, x, n, 1);
        addMatrix(B + m * (n + 1), o, y, n, 1);
        strassen(x, y, T, m);

        subMatrix(A + n * m, A, x, n, 1);
        addMatrix(B, B + m, y, n, 1);
        strassen(x, y, U, m);

        subMatrix(A + m, A + m * (n + 1), x, n, 1);
        addMatrix(B + n * m, B + m * (n + 1), y, n, 1);
        strassen(x, y, V, m);

        int W[m * m], X[m * m], Y[m * m], Z[m * m];
        subMatrix(V, T, x, m, 0);
        addMatrix(S, x, y, m, 0);
        addMatrix(P, y, W, m, 0);
        addMatrix(R, T, X, m, 0);
        addMatrix(Q, S, Y, m, 0);
        subMatrix(U, Q, x, m, 0);
        addMatrix(R, x, y, m, 0);
        addMatrix(P, y, Z, m, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                C[i * n + j] = W[i * m + j];
                C[i * n + j + m] = X[i * m + j];
                C[(i + m) * n + j] = Y[i * m + j];
                C[(i + m) * n + j + m] = Z[i * m + j];
            }
    }
}

int main()
{
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;

    int n1 = (i1 > j1) ? i1 : j1;
    int n2 = (i2 > j2) ? i2 : j2;
    int n = (n1 > n2) ? n1 : n2;
    n += (n % 2 == 0) ? 0 : 1;

    //2D arrays flattened as 1D arrays
    int A[n * n], B[n * n], C[n * n];

    for (int i = 0; i < n * n; i++)
        A[i] = B[i] = 0;

    for (int i = 0; i < i1; i++)
        for (int j = 0; j < j1; j++)
            cin >> A[i * n + j];

    for (int i = 0; i < i2; i++)
        for (int j = 0; j < j2; j++)
            cin >> B[i * n + j];

    strassen(A, B, C, n);

    for (int i = 0; i < i1; i++)
    {
        for (int j = 0; j < j2; j++)
            cout << C[i * n + j] << " ";
        cout << endl;
    }
}