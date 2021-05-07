#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int longestCommonSuff(char s1[], char s2[], int n, int m)
{
    int result = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(dp[i][j], result);
            }
            else
                dp[i][j] = 0;
        }
    }
    return result;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    char X[] = "ABCDEF";
    //char Y[] = "ABXEF";
    char Y[] = "EFMNABCD";
    int n = strlen(X);
    int m = strlen(Y);
    cout << longestCommonSuff(X, Y, n, m) << endl;
    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
}