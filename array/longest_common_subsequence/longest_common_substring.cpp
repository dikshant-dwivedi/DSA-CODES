/*
This recursive solution doesnt follow direct knapsack pattern and that's why it cannot be directly
converted to top-down dp or memoized solution.
this pattern is different because of the extra count variable. the count variable changes if the consequent
values arent taken, while at the same prev count variable is needed too.
secondly for base condition, assumption isnt that the "if both or either of the strings are empty, so what will
be the length of longest common substring (obviously zero)", instead it is "if while iterating the strings if
we reach the end of both or either of the strings, so then what will
be the length of longest common substring (it will simplu be the count accumulated till now)"
*/
#include <iostream>
#include <cstring>
using namespace std;

int longestCommonSubstring(char s1[], char s2[], int n, int m, int count)
{
    if(n == 0 || m == 0)
        return count;

    /*
    this works too, just the optimized version is written
    if(s1[n-1] == s2[m-1])
        return max(longestCommonSubstring(s1, s2, n-1, m-1, count+1),
                    max(longestCommonSubstring(s1, s2, n, m-1, 0),
                    longestCommonSubstring(s1, s2, n-1, m, 0)));
    else
        return max(count, max(longestCommonSubstring(s1, s2, n, m - 1, 0),
                   longestCommonSubstring(s1, s2, n - 1, m, 0)));*/

    if(s1[n-1] == s2[m-1])
        count = longestCommonSubstring(s1, s2, n - 1, m - 1, count + 1);
    return max(count, max(longestCommonSubstring(s1, s2, n, m - 1, 0),
                   longestCommonSubstring(s1, s2, n - 1, m, 0)));
}

int main()
{
    char X[] = "ABCDEF";
    char Y[] = "EFMNABCD";
    int n = strlen(X);
    int m = strlen(Y);
    cout << longestCommonSubstring(X, Y, n, m, 0)<<endl;
}