#include <bits/stdc++.h>
using namespace std;
// iterative Approach
int binarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
//Recursive Approach
int binarySearch(vector<int> &arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return binarySearch(arr, target, mid + 1, end);
        }
        else
        {
            return binarySearch(arr, target, start, mid - 1);
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 18};
    int target = 6;
    int result = binarySearch(arr, target, 0, arr.size() - 1);
    cout << result << endl;

    return 0;
}
