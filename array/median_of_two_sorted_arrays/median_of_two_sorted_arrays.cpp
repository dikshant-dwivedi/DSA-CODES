/*
MEDIAN FINDING FOR TWO SORTED ARRAYS
this is an optimized algorithm with complexity O(min(m, n))
m and n are size of the arrays
a complete explanation is already attached in the repository for my reference
also, the original source is
https://www.youtube.com/watch?v=fk5KtV1EP3M&list=PLliXPok7Zonl8JvKc-paNnzTHxa1IqZYS&ab_channel=KeertiPurswani
*/
#include <iostream>
using namespace std;
#define I 32767

int min(int a, int b)
{
    return (a < b) ? a : b;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

float findMedian(int arr1[], int arr2[], int n1, int n2)
{
    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2) / 2 - cut1;

        int l1 = cut1 == 0 ? -I : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? -I : arr2[cut2 - 1];
        int r1 = cut1 == n1 ? I : arr1[cut1];
        int r2 = cut2 == n2 ? I : arr2[cut2];

        if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else if (l2 > r1)
        {
            low = cut1 + 1;
        }
        else
        {
            return ((n1 + n2) % 2 == 0) ? (max(l1, l2) + min(r1, r2)) / 2 : min(r1, r2);
        }
    }
    return -1;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    if (n1 < n2)
        cout << "Median is " << findMedian(arr1, arr2, n1, n2);
    else
        cout << "Median is " << findMedian(arr2, arr1, n2, n1);
}