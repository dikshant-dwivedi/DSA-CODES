#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int subsetSum(int arr[], int sum, int n)
{
    for(int i = 0; i <= sum; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = 1;
            else if(j == 0)
                dp[i][j] = 0;
            else
            {
                if(arr[j-1] <= i)
                    dp[i][j] = dp[i - arr[j-1]][j-1] || dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[sum][n];
}

int equalSumPartition(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    if(sum % 2 != 0)
        return 0;
    else
        return subsetSum(arr, sum/2, n);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {1, 5, 11, 5};
    int n = 4;

    if(equalSumPartition(arr, n))
        cout << "yes";
    else
        cout << "no";
}