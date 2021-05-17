#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int isPalindrome(string s, int i, int j)
{
    if(i == j)
        return 1;
    else
    {
        while(i <= j)
        {
            if(s[i] == s[j])
                i++, j--;
            else
                return 0;
        }
    }
    return 1;
}

int solve(string s, int i, int j)
{
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(isPalindrome(s, i, j))
        return 0;

    int temp;
    int mn = 32767;
    for(int k = i; k < j; k++)
    {
        temp = solve(s, i, k) + solve(s, k+1, j) + 1;
        mn = min(temp, mn);
    }
    return dp[i][j] = mn;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s = "nitinmlnn";
    int n = s.length();
    cout << solve(s, 0, n - 1);
}