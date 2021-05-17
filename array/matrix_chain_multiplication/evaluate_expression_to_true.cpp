#include<iostream>
using namespace std;

int solve(string exp, int i, int j, char toEvalTo)
{
    if(i > j)
        return 0;
    if(i == j)
    {
        if(toEvalTo == 'T')
            return exp[i] == 'T'; //return 1 for exp[i] = T and 0 for F
        else
            return exp[i] == 'F'; //return 1 for exp[i] = F and 0 for T
    }

    int ans = 0;
    for(int k = i + 1; k < j; k+= 2)
    {
        int lt = solve(exp, i, k-1, 'T');
        int lf = solve(exp, i, k-1, 'F');
        int rt = solve(exp, k+1, j, 'T');
        int rf = solve(exp, k+1, j, 'F');

        if(exp[k] == '^')
            if(toEvalTo == 'T')
                ans += lt * rf + lf * rt;
            else
                ans += lt * rt + lf * rf;
        else if(exp[k] == '|')
            if(toEvalTo == 'T')
                ans += lt * rt + lf * rt + lt * rf;
            else
                ans += lf * rf;
        else
            if(toEvalTo == 'T')
                ans += lt * rt;
            else 
                ans += lf * rf + lt * rf + rt * lf;
    }
    return ans;
}

int main()
{
    string exp = "T|F&T^F";
    int n = exp.length();
    cout << solve(exp, 0, n-1, 'T'); 
}