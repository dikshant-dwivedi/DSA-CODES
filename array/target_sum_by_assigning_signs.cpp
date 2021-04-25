/*
    the problem is same as number_of_subsets_with_given_difference.cpp
    to understand problem statement:
    https://youtu.be/Hw6Ygp3JBYw
*/

#include <iostream>
#include <cstring>
using namespace std;
int dp[101][101];

int countTotalSubset_r(int arr[], int sumRequired, int n)
{
    if (sumRequired == 0)
        return 1;
    if (n == 0)
        return 0;

    if (arr[n - 1] <= sumRequired)
        return countTotalSubset_r(arr, sumRequired - arr[n - 1], n - 1) + countTotalSubset_r(arr, sumRequired, n - 1);
    else
        return countTotalSubset_r(arr, sumRequired, n - 1);
}

int countTotalSubset_m(int arr[], int sumRequired, int n)
{
    if (sumRequired == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[sumRequired][n] != -1)
        return dp[sumRequired][n];
    else if (arr[n - 1] <= sumRequired)
        return dp[sumRequired][n] = countTotalSubset_r(arr, sumRequired - arr[n - 1], n - 1) + countTotalSubset_r(arr, sumRequired, n - 1);
    else
        return dp[sumRequired][n] = countTotalSubset_r(arr, sumRequired, n - 1);
}

int countTotalSubset_dp(int arr[], int sumRequired, int n)
{
    for (int i = 0; i <= sumRequired; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = 1;
            else if (j == 0)
                dp[i][j] = 0;
            else
            {
                if (arr[j - 1] <= i)
                    dp[i][j] = dp[i - arr[j - 1]][j - 1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[sumRequired][n];
}

int countSubsetWithDiff(int arr[], int diff, int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];

    int sumRequired = (diff + range) / 2;
    return countTotalSubset_m(arr, sumRequired, n);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {1, 1, 2, 3};
    int diff = 1;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countSubsetWithDiff(arr, diff, n);
}