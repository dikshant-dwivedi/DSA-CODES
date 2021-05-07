#include<iostream>
using namespace std;

int find_first_occurence(int arr[], int n, int e)
{
    int start = 0, end = n-1, mid, res = -1;
    while(start <= end)
    {
        mid = start +(end - start)/2;
        if(e == arr[mid])
        {
            res = mid;
            end = mid - 1;
        }
        else if(e > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return res;
}

int find_last_occurence(int arr[], int n, int e)
{
    int start = 0, end = n - 1, mid, res = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (e == arr[mid])
        {
            res = mid;
            start = mid + 1;
        }
        else if (e > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, 5, 6, 10, 10, 10, 10, 10, 12, 22, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << find_first_occurence(arr, n, 10) << endl;
    cout << find_last_occurence(arr, n, 10) << endl;
}