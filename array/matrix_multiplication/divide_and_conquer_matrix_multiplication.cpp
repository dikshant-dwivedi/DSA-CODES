#include <iostream>
#include <cstdio>
using namespace std;

void Madd(int *A, int *B, int *C, int n, int x)
{
    int m = x == 1 ? n / 2 : n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i * m + j] = A[i * n + j] + B[i * n + j];
}

void multiplyMatrices(int *A, int *B, int *C, int n)
{
    if (n == 2)
    {
        C[0] = A[0] * B[0] + A[1] * B[n];
        C[1] = A[0] * B[1] + A[1] * B[n + 1];
        C[n] = A[n] * B[0] + A[n + 1] * B[n];
        C[n + 1] = A[n] * B[1] + A[n + 1] * B[n + 1];
    }
    else
    {
        int m = n / 2;
        int x[m * m], y[m * m], o[n * n];

        for (int i = 0; i < n * n; i++)
            o[i] = 0;

        int P[m * m], Q[m * m], R[m * m], S[m * m],
            T[m * m], U[m * m], V[m * m], W[m * m];

        Madd(A, o, x, n, 1);
        Madd(B, o, y, n, 1);
        multiplyMatrices(x, y, P, m);

        Madd(A + m, o, x, n, 1);
        Madd(B + n * m, o, y, n, 1);
        multiplyMatrices(x, y, Q, m);

        Madd(A, o, x, n, 1);
        Madd(B + m, o, y, n, 1);
        multiplyMatrices(x, y, R, m);

        Madd(A + m, o, x, n, 1);
        Madd(B + m * (n + 1), o, y, n, 1);
        multiplyMatrices(x, y, S, m);

        Madd(A + n * m, o, x, n, 1);
        Madd(B, o, y, n, 1);
        multiplyMatrices(x, y, T, m);

        Madd(A + m * (n + 1), o, x, n, 1);
        Madd(B + n * m, o, y, n, 1);
        multiplyMatrices(x, y, U, m);

        Madd(A + n * m, o, x, n, 1);
        Madd(B + m, o, y, n, 1);
        multiplyMatrices(x, y, V, m);

        Madd(A + m * (n + 1), o, x, n, 1);
        Madd(B + m * (n + 1), o, y, n, 1);
        multiplyMatrices(x, y, W, m);

        int I[m * m], J[m * m], K[m * m], L[m * m];
        Madd(P, Q, I, m, 0);
        Madd(R, S, J, m, 0);
        Madd(T, U, K, m, 0);
        Madd(V, W, L, m, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                C[i * n + j] = I[i * m + j];
                C[i * n + j + m] = J[i * m + j];
                C[(i + m) * n + j] = K[i * m + j];
                C[(i + m) * n + j + m] = L[i * m + j];
            }
    }
}

int main()
{
    int i1, i2, j1, j2;
    cin >> i1 >> j1 >> i2 >> j2;

    int n1 = (i1 > j1) ? i1 : j1;
    int n2 = (i2 > j2) ? i2 : j2;
    int n = (n1 > n2) ? n1 : n2;
    n += (n % 2 == 0) ? 0 : 1;

    int a[n * n], b[n * n], C[n * n];

    for (int i = 0; i < n * n; i++)
        a[i] = b[i] = C[i] = 0;

    for (int i = 0; i < i1; i++)
        for (int j = 0; j < j1; j++)
            cin >> a[i * n + j];

    for (int i = 0; i < i1; i++)
        for (int j = 0; j < j1; j++)
            cin >> b[i * n + j];

    multiplyMatrices(a, b, C, n);

    for (int i = 0; i < i1; i++)
    {
        for (int j = 0; j < j2; j++)
            cout << C[i * n + j] << " ";
        cout << endl;
    }
}