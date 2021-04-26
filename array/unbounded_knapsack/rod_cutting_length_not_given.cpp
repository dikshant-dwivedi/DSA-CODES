#include <iostream>
#include <cstring>
using namespace std;
int dp[101][101];

int rodCutting_r(int lengths[], int profits[], int L, int n)
{
    if (L == 0 || n == 0)
        return 0;
    if (lengths[n - 1] <= L)
        return max(profits[n - 1] + rodCutting_r(lengths, profits, L - lengths[n - 1], n),
                   rodCutting_r(lengths, profits, L, n - 1));
    else
        return rodCutting_r(lengths, profits, L, n - 1);
}

int rodCutting_m(int lengths[], int profits[], int L, int n)
{
    if (L == 0 || n == 0)
        return 0;
    if (dp[L][n] != -1)
        return dp[L][n];
    else if (lengths[n - 1] <= L)
        return dp[L][n] = max(profits[n - 1] + rodCutting_m(lengths, profits, L - lengths[n - 1], n),
                              rodCutting_m(lengths, profits, L, n - 1));
    else
        return dp[L][n] = rodCutting_m(lengths, profits, L, n - 1);
}

int rodCutting_dp(int lengths[], int profits[], int L, int n)
{
    for (int i = 0; i <= L; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (lengths[j - 1] <= i)
                dp[i][j] = max(profits[j - 1] + dp[i - lengths[j - 1]][j], dp[i][j - 1]);
            else
                dp[i][j] = dp[i][j - 1];
        }
    return dp[L][n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int profits[] = {2, 5, 7, 8};
    int n = sizeof(profits) / sizeof(profits[0]);
    int lengths[n];

    for(int i = 0; i < n; i++)
        lengths[i] = i + 1;

    int L = 5;
    cout << rodCutting_dp(lengths, profits, L, n);
}