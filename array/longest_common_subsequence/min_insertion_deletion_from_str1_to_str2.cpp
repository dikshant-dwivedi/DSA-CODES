#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

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
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int min_ins_del_from_str1_to_str2(char s1[], char s2[], int n, int m)
{
    int lcs = longestCommonSubsequence(s1, s2, n, m);
    return m + n - 2*lcs; // (m - lcs + n - lcs)
}

int main()
{
    memset(dp, -1, sizeof(dp));
    char X[] = "heap";
    char Y[] = "pea";
    int n = strlen(X);
    int m = strlen(Y);
    cout << min_ins_del_from_str1_to_str2(X, Y, n, m);
}