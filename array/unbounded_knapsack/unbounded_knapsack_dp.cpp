#include <iostream>
#include <cstring>
using namespace std;
int dp[101][101];

int unboundedKnapsack(int wt[], int val[], int W, int n)
{
    for(int i = 0; i <= W; i++)
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[j-1] <= i)
                dp[i][j] = max(val[j-1] + dp[i - wt[j-1]][j], dp[i][j-1]);
            else
                dp[i][j] = dp[i][j-1];
        }
    return dp[W][n];
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    memset(dp, -1, sizeof(dp));
    cout << unboundedKnapsack(wt, val, W, n);
}