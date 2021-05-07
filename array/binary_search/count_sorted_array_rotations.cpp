/*
how it works:
    the index of minimum element gives number of rotations
how to find min:
    either of the following two conditions will apply -
    1. only the min element has a special property = both its left and right elements are greater than it
    2. array is already sorted, so return the start index
how to know array is already sorted:
    arr[start] <= arr[end]
how to move left or right if middle element in not min:
    move in the direction where the array is unsorted
how to find whether array is unsorted:
    condition - arr[start] > arr[mid] (go left)
                arr[mid] > arr[end] (go right)
*/


#include<iostream>
using namespace std;

int countRotations(int arr[], int n)
{
    int start = 0, end = n-1, mid, prev, next;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(arr[start] <= arr[end])
            return start;
        next = (mid + 1) % n;
        prev = (mid - 1 + n) % n;
        if(arr[prev] > arr[mid] && arr[next] > arr[mid])
            return mid;
        else if(arr[start] > arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countRotations(arr, n);
}