#include<iostream>
#include<cstring>
using namespace std;
int dp[11][11];

int knapsack(int wt[], int val[], int W, int n)
{
    for(int i = 0; i <= W; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[j - 1] <= i)
                dp[i][j] = max(val[j-1] + dp[i - wt[j-1]][j-1], dp[i][j-1]);
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[W][n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n = 3;
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    cout << knapsack(wt, val, W, n);
}
