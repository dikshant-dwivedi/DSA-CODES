#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int countTotalSubsets(int arr[], int sum, int n)
{
    for(int i = 0; i <= sum; i++)
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = 1;
            else if(j == 0)
                dp[i][j] = 0;
            else
            {
                if(arr[j-1] <= i)
                    dp[i][j] = dp[i - arr[j-1]][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    return dp[sum][n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {2, 3, 7, 8, 10};
    int n = 5, sum = 10;

    cout << countTotalSubsets(arr, sum, n);
}