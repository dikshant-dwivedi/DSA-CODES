#include<iostream>
#include<cstring>
using namespace std;
int dp[11][11];

int longestCommonSubsequence(char s1[], char s2[], int n, int m)
{
    if(n == 0 || m == 0)
        return 0;
    else if (dp[n][m] != -1)
        return dp[n][m];
    else
    {
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1 + longestCommonSubsequence(s1, s2, n-1, m-1);
        else
            return dp[n][m] = max(longestCommonSubsequence(s1, s2, n-1, m),
            longestCommonSubsequence(s1, s2, n, m-1));
    }
    
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