#include <iostream>
#include <cstring>
using namespace std;
int dp[101][101];

void longestCommonSubsequence(char s1[], char s2[], int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string s = "";
    while (n >= 0 && m >= 0)
    {
        if (s1[n - 1] == s2[m - 1])
        {
            s = s1[n - 1] + s;
            n--;
            m--;
        }
        else
        {
            if (dp[n - 1][m] > dp[n][m - 1])
                n--;
            else
                m--;
        }
    }
    cout << s;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int n = strlen(X);
    int m = strlen(Y);
    longestCommonSubsequence(X, Y, n, m);
}