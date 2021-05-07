#include<iostream>
using namespace std;

int findElement(int arr[], int n, int e)
{
    int start = 0, end = n-1, mid;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(e == arr[mid])
            return mid;
        if(mid != 0 && e == arr[mid - 1])
            return mid - 1;
        if(mid != n-1 && e == arr[mid + 1])
            return mid + 1; 
        else if(e > arr[mid])
            start = mid + 2;
        else
            end = mid - 2;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int e = 40;
    cout << findElement(arr, n, e);
}