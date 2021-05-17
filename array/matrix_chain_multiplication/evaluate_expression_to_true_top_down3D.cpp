#include<iostream>
#include<cstring>
using namespace std;
int dp[8][8][2];
int solve(string exp, int i, int j, int toEvalTo)
{
    if(i > j)
        return 0;
    if(i == j)
        if(toEvalTo)
            return exp[i] == 'T';
        else    
            return exp[i] == 'F';
    if(dp[i][j][toEvalTo] != -1)
        return dp[i][j][toEvalTo];

    int ans = 0;
    for(int k = i+1; k < j; k += 2)
    {
        int lt = solve(exp, i, k-1, 1);
        int lf = solve(exp, i, k-1, 0);
        int rt = solve(exp, k+1, j, 1);
        int rf = solve(exp, k+1, j, 0);

        if(exp[k] == '^')
            if(toEvalTo)
                ans += lt * rf + lf * rt;
            else 
                ans += lt * rt + lf * rf;
        else if(exp[k] == '&')
            if(toEvalTo)
                ans += lt * rt;
            else 
                ans += lf * rf + lt * rf + lf * rt;
        else    
            if(toEvalTo)
                ans += lt * rt + lf * rt + lt * rf;
            else    
                ans += lf * rf;
    }
    return dp[i][j][toEvalTo] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string exp = "T|F&T^F";
    int n = exp.length();
    cout << solve(exp, 0, n - 1, 'T');
}