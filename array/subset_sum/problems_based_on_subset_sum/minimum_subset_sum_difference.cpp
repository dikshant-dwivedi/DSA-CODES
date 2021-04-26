#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

//Recursive
int subsetSumRecursive(int arr[], int sumRequired, int n)
{
    if(sumRequired == 0)
        return 1;
    if(n == 0)
        return 0;

    if(arr[n-1] <= sumRequired)
        return subsetSumRecursive(arr, sumRequired - arr[n-1], n-1)||subsetSumRecursive(arr, sumRequired, n-1);
    else
        return subsetSumRecursive(arr, sumRequired, n-1);
}

//memoized
int subsetSumMemoized(int arr[], int sumRequired, int n)
{
    if (sumRequired == 0)
        return 1;
    if (n == 0)
        return 0;
    
    if(dp[sumRequired][n] != -1)
        return dp[sumRequired][n];
    else if(arr[n - 1] <= sumRequired)
        return dp[sumRequired][n] = subsetSumMemoized(arr, sumRequired - arr[n - 1], n - 1) || subsetSumMemoized(arr, sumRequired, n - 1);
    else
        return dp[sumRequired][n] = subsetSumMemoized(arr, sumRequired, n - 1);
}

//dynamic programming top down
int subsetSumDp(int arr[], int sumRequired, int n)
{
    if (sumRequired == 0)
        return 1;
    if (n == 0)
        return 0;

    for(int i = 0; i <= sumRequired; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else
            {
                if(arr[j - 1] <= i)
                    dp[i][j] = dp[i - arr[j-1]][j-1] || dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[sumRequired][n];
}

int minimumSubsetSumDifference(int arr[], int n)
{
    int range = 0;
    for(int i = 0; i < n; i++)
        range += arr[i];

    int m = (range % 2 == 0) ? range/2 : range/2 + 1;
    int possibleSums[m];
    for(int i = 0; i < m; i++)
        possibleSums[i] = subsetSumRecursive(arr, i, n);

    int mn = 32767;
    for(int i = 0; i < m; i++)
        if(possibleSums[i])
            mn = min(mn, range - 2*i);

    return mn;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minimumSubsetSumDifference(arr, n);
}