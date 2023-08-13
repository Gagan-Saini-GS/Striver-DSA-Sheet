#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &arr)
{
    int n = arr.size();
    int currSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if (currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxSum = maxSubArray(arr);
    cout << maxSum << endl;

    return 0;
}