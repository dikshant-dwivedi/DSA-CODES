#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];

int minimumSubsetSumDifference_r(int arr[], int range, int sumCalculated, int n)
{
    if(n == 0)
        return abs(range - 2*sumCalculated);

    return min(minimumSubsetSumDifference_r(arr, range, sumCalculated + arr[n-1], n-1),
               minimumSubsetSumDifference_r(arr, range, sumCalculated, n-1));
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {3, 1, 4, 2, 2, 1};
    //int arr[] = {1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range = 0;
    for(auto i: arr)
        range += i;

    cout << minimumSubsetSumDifference_r(arr, range, 0, n) << endl;

}