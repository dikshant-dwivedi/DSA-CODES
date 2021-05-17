#include<iostream>
#include<cstring>
using namespace std;
int dp[6][6];//if the arr size is s, then dp dimensions are: dp[s+1][s+1];

int solve(int arr[], int i, int j)
{
    if(i >= j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int mn = 32767;
    int temp;
    for(int k = i; k < j; k++)
    {
        temp = solve(arr, i, k) + solve(arr,k+1, j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, 1, n - 1);
}