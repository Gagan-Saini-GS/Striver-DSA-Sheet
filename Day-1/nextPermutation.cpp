#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int breakPI = -1; // Break Point Index

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            breakPI = i;
            break;
        }
    }

    // If next permutation is not exist
    if (breakPI == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    int minElem = INT_MAX;
    int minPI = -1;

    for (int i = breakPI; i < n; i++)
    {
        if (arr[i] > arr[breakPI])
        {
            minElem = min(minElem, arr[i]);
            minPI = (minElem == arr[i]) ? i : -1;
        }
    }

    // swap(minElem,arr[breakPI]);
    swap(arr[minPI], arr[breakPI]);
    reverse(arr.begin() + breakPI + 1, arr.end());
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    nextPermutation(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}