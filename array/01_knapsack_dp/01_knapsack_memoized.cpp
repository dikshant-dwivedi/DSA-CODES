#include<iostream>
#include<cstring>
using namespace std;
int dp[11][11];

int knapsack(int wt[], int val[], int W, int n)
{
    if(n == 0 || W == 0)
        return 0;
    else if(dp[W][n] == -1)
        return dp[W][n];
    else
    {
        if(wt[n-1] <= W)
            return dp[W][n] = max(val[n-1] + knapsack(wt, val, W - wt[n-1], n - 1),
             knapsack(wt, val, W, n-1));
        else
            return dp[W][n] = knapsack(wt, val, W, n-1);
    }
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