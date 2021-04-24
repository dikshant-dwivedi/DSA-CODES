#include<iostream>
using namespace std;

int subsetSum(int arr[], int sum, int n)
{
    if (sum == 0)  // this condition should be before the other one
        return 1;
    if(n == 0)
        return 0;

    if(arr[n-1] <= sum)
        return subsetSum(arr, sum - arr[n-1], n-1) || subsetSum(arr, sum, n-1);
    else
        return subsetSum(arr, sum, n - 1);
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = 5, sum = 12;

    if(subsetSum(arr, sum, n))
        cout << "yes";
    else
        cout << "no";
}