#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int sequencePatternMatching(string s1, string s2, int n, int m)
{
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    if(dp[n][m] == s1.length())
        return 1;
    else 
        return 0;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s1 = "axy";
    string s2 = "axdcpy";
    int n = s1.length();
    int m = s2.length();
    if(sequencePatternMatching(s1, s2, n, m))
        cout << "true";
    else
        cout << "false";
}