#include<iostream>
#include<cstring>
#define I 32766
using namespace std;
int dp[101][101];

int minimumCoinNumber_r(int coins[], int moneyNeeded, int n)
{
    if(moneyNeeded == 0)
        return 0;
    else if(n == 0)
        return I;
    else if(n == 1)
        return (moneyNeeded % coins[n - 1] == 0) ? moneyNeeded / coins[n - 1] : I;
    else if(coins[n-1] <= moneyNeeded)
        return min(1 + minimumCoinNumber_r(coins, moneyNeeded - coins[n-1], n),
                minimumCoinNumber_r(coins, moneyNeeded, n-1));
    else 
        return minimumCoinNumber_r(coins, moneyNeeded, n-1);
}

int minimumCoinNumber_m(int coins[], int moneyNeeded, int n)
{
    if (moneyNeeded == 0)
        return 0;
    else if (n == 0)
        return I;
    else if (n == 1)
        return (moneyNeeded % coins[n - 1] == 0) ? moneyNeeded / coins[n - 1] : I;
    else if (coins[n - 1] <= moneyNeeded)
        return min(1 + minimumCoinNumber_r(coins, moneyNeeded - coins[n - 1], n),
                   minimumCoinNumber_r(coins, moneyNeeded, n - 1));
    else
        return minimumCoinNumber_r(coins, moneyNeeded, n - 1);
}

int main()
{
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins) / sizeof(coins[0]);
    int moneyNeeded = 11;
    cout << "Minimum coins required is "
         << minimumCoinNumber_r(coins, moneyNeeded, n);
}