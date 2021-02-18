/*
Find first and last occurrences of a number in a sorted array using divide and conquer procedure
(binary search)
    functions: 
        findFirst
        findLast
thought process for me is uploaded
*/

#include <iostream>
using namespace std;

int findFirst(int arr[], int l, int h, int x)
{
    if (h >= l)
    {
        int mid = (l + h) / 2;
        if ((x == arr[mid]) && (mid == 0 || arr[mid - 1] < x))
            return mid;
        else if (x <= arr[mid])
            return findFirst(arr, l, mid, x);
        else
            return findFirst(arr, mid + 1, h, x);
    }

    return -1;
}

int findLast(int arr[], int l, int h, int x, int n)
{
    if (h >= l)
    {
        int mid = (l + h) / 2;
        if ((x == arr[mid]) && (mid == n - 1 || arr[mid + 1] > x))
            return mid;
        else if (x < arr[mid])
            return findLast(arr, l, mid, x, n);
        else
            return findLast(arr, mid + 1, h, x, n);
    }

    return -1;
}

int main()
{
    //size of the array
    int n;
    cin >> n;
    int arr[n];

    //get the array input
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //the number who occurrences have to be searched
    int x;
    cin >> x;

    int first = findFirst(arr, 0, n - 1, x);
    int last = findLast(arr, 0, n - 1, x, n);
    cout << "First occurrence = " << first << endl;
    cout << "Last occurrence = " << last;
}