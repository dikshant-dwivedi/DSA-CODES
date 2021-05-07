#include<iostream>
using namespace std;

int findFloor(int arr[], int n, int e)
{
    int start = 0, end = n-1, mid, res = -1;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(arr[mid] == e)
            return mid;
        if(arr[mid] > e)
        {
            end = mid - 1;
            res = mid;
        }
        else
            start = mid + 1;
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int e = 5;
    cout << findFloor(arr, n, e);
}