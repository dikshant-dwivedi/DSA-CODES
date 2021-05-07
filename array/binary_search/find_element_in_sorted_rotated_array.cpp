#include<iostream>
using namespace std;

int countRotation(int arr[], int n)
{
    int start = 0, end = n-1, mid, prev, next;
    while(start <= end)
    {
        if(arr[start] <= arr[end])
            return start;
        mid = start + (end - start)/2;
        next = (mid + 1) % n;
        prev = (mid - 1 + n) % n;
        if(arr[prev] > arr[mid] && arr[next] > arr[mid])
            return mid;
        if(arr[start] > arr[mid])
            end = mid - 1;
        else 
            start = mid + 1;
    }
    return -1;
}

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

int find_element(int arr[], int n, int e)
{
    int i = countRotation(arr, n);
    int arr1[i], arr2[n - i];
    int k = 0;
    for(int j = 0; j < i; j++)
        arr1[j] = arr[k++];
    for(int j = 0; j < n - i; j++)
        arr2[j] = arr[k++];
    int m1 = binary_search(arr1, i, e); 
    int m2 = binary_search(arr2, n-i, e);
    if(m1 == -1 && m2 == -1)
        return -1;
    if(m1 != -1)
        return m1;
    else
        return i + m2;
}

int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << find_element(arr, n, 6);
}