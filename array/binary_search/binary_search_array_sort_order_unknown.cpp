#include<iostream>
using namespace std;

int binary_search_reverse(int arr[], int n, int e)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (e == arr[mid])
            return mid;
        else if (e < arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int binary_search(int arr[], int n, int e)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (e == arr[mid])
            return mid;
        else if (e > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {56, 22, 12, 6, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(n == 1)
        cout << 0;
    else if(arr[0] < arr[1])
        cout << binary_search(arr, n, 5);
    else
        cout << binary_search_reverse(arr, n, 5);
}