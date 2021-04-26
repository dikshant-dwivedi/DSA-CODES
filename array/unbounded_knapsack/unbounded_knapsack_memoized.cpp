#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int unboundedKnapsack(int wt[], int val[], int W, int n)
{
    if (W == 0 || n == 0)
        return 0;

    if(dp[W][n] != -1)
        return dp[W][n];
    else if (wt[n - 1] <= W)
        return dp[W][n] = max(val[n - 1] + unboundedKnapsack(wt, val, W - wt[n - 1], n),
                            unboundedKnapsack(wt, val, W, n - 1));
    else
        return dp[W][n] = unboundedKnapsack(wt, val, W, n - 1);
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