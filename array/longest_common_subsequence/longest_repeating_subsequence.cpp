#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int longestRepeatingSubsequence(string s1, int n)
{
    string s2 = s1;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else 
            {
                if(s1[i-1] == s2[j-1] && i != j)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    string s = "AABEBCDD";
    int n = s.length();
    cout << longestRepeatingSubsequence(s, n);
}