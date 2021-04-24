#include<iostream>
#include<cstring>
using namespace std;
int dp[11][11];

int longestCommonSubsequence(char s1[], char s2[], int n, int m)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }   
        }
    }
    return dp[n][m];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int n = strlen(X);
    int m = strlen(Y);
    cout << longestCommonSubsequence(X, Y, n, m);
}