#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int e)
{
    int start = 0, end = n-1, mid;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(e == arr[mid])
            return mid;
        else if(e < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 5, 6, 12, 22, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << binary_search(arr, n, 5);
}