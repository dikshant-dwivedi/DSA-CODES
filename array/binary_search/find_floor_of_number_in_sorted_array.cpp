#include <iostream>
using namespace std;

int findFloor(int arr[], int n, int e)
{
    int start = 0, end = n - 1, mid, res = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (e == arr[mid])
            return mid;
        else if (arr[mid] < e)
        {
            start = mid + 1;
            res = mid;
        }
        else
            end = mid - 1;
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