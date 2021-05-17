#include<iostream>
#include<cstring>
using namespace std;

int solve(int arr[], int i, int j)
{
    //invalid input condition
    if(i >= j)
        return 0;

    int mn = 32767;
    int temp;
    for(int k = i; k < j; k++)
    {
        temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        mn = min(temp, mn);
    }
    return mn;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << solve(arr, 1, n-1);
}
