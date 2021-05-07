#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int lcs(string s1, string s2, int n, int m)
{
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

int longestPalindromicSequence(string s1, int n)
{
    string s2 = "";
    for(auto i: s1)
        s2 = i + s2;
    return lcs(s1, s2, n, n);
}

int minInsertion(string s1, int n)
{
    int lps = longestPalindromicSequence(s1, n);
    return n - lps;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s = "aebcbda";
    int n = s.length();
    cout << minInsertion(s, n);
}