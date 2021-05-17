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
                {
                    i++;
                    j--;
                }
                else
                    return 0;
            }
        }
    return true;
}

int solve(string s, int i, int j)
{
    if(i >= j)
        return 0;
    if(isPalindrome(s, i, j))
        return 0;
    else
    {
        int mn = 32767;
        int temp;
        for(int k = i; k < j; k++)
        {
            temp = solve(s, i, k) + solve(s, k+1, j) + 1;
            mn = min(temp, mn);
        }
        return mn;
    }
}
int main()
{
    string s = "nitinmlnn";
    int n = s.length();
    cout << solve(s, 0, n-1);
}