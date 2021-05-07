#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

void shortestCommonSupersequence(string s1, string s2, int n, int m)
{
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    
    string s = "";
    while(n > 0 && m > 0)
    {
        if(s1[n-1] == s2[m-1])
        {
            s = s1[n-1] + s;
            n--;
            m--;
        }
        else
        {
            if(dp[n-1][m] > dp[n][m-1])
            {
                s = s1[n-1] + s;
                n--;
            }
            else
            {
                s = s2[m - 1] + s;
                m--;
            }
        }
    }
    for(; n > 0; n--)
        s = s1[n-1] + s;
    for(; m > 0; m--)
        s = s2[m-1] + s;

    cout << s;
}

int main()
{
    //string s1 = "geek";
    string s1 = "abcdaf";
    //string s2 = "eke";
    string s2 = "acbcf";
    int n = s1.length();
    int m = s2.length();
    shortestCommonSupersequence(s1, s2, n, m);
}