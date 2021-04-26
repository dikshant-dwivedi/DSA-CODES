#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int coinChange_r(int coins[], int moneyNeeded, int n)
{
    if(moneyNeeded == 0)
        return 1;
    if(n == 0)
        return 0;

    if(coins[n-1] <= moneyNeeded)
        return coinChange_r(coins, moneyNeeded - coins[n-1], n)
         + coinChange_r(coins, moneyNeeded, n-1);
    else
        return coinChange_r(coins, moneyNeeded, n-1);
}

int coinChange_m(int coins[], int moneyNeeded, int n)
{
    if (moneyNeeded == 0)
        return 1;
    if (n == 0)
        return 0;
    else if(dp[moneyNeeded][n] != -1)
        return dp[moneyNeeded][n];
    else if (coins[n - 1] <= moneyNeeded)
        return dp[moneyNeeded][n] = coinChange_m(coins, moneyNeeded - coins[n - 1], n) + coinChange_m(coins, moneyNeeded, n - 1);
    else
        return dp[moneyNeeded][n] = coinChange_m(coins, moneyNeeded, n - 1);
}

int coinChange_dp(int coins[], int moneyNeeded, int n)
{
    for(int i = 0; i <= moneyNeeded; i++)
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = 1;
            else if(j == 0)
                dp[i][j] = 0;
            else if(coins[j-1] <= i)
                dp[i][j] = dp[i-coins[j-1]][j] + dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    return dp[moneyNeeded][n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int coins[] = {1,2, 3, 5};
    //int coins[] = {1,2, 3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int moneyNeeded = 8;
    cout << coinChange_dp(coins, moneyNeeded, n);
}