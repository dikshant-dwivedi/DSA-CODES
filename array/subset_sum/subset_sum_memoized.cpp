#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int subsetSum(int arr[], int sum, int n)
{
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;

    if(dp[sum][n] != 1)
        return dp[sum][n];
    
    if(arr[n-1] <= sum)
        return dp[sum][n] = subsetSum(arr, sum - arr[n-1], n-1) || subsetSum(arr, sum, n-1);
    else
        return dp[sum][n] = subsetSum(arr, sum, n-1);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {2, 3, 7, 8, 10};
    int n = 5, sum = 11;

    if (subsetSum(arr, sum, n))
        cout << "yes";
    else
        cout << "no";
}