#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &arr)
{
    int n = arr.size();
    int sum = (n * (n + 1)) / 2;
    int sqSum = (n * (n + 1) * (2 * n + 1)) / 6;
    int sumArr = 0, sqArrSum = 0;

    for (int i = 0; i < n; i++)
    {
        sumArr += arr[i];
        sqArrSum += arr[i] * arr[i];
    }

    int diff = sum - sumArr; // x-y;
    int sqDiff = sqSum - sqArrSum;

    int add = sqDiff / diff; // x+y;

    cout << add << " " << diff << endl;

    int missing = (add + diff) / 2;
    int repeating = missing - diff;

    cout << repeating << " " << missing << endl;
    return {min(repeating, missing), max(repeating, missing)};
    // x-y = sum - sumArr; --1
    // x2-y2 = sqSum - sqArrSum;
    // (x-y)(x+y) = sqSum - sqArrSum;
    // x+y = (sqSum-sqArrSum)/(sum-sumArr); --2
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = repeatedNumber(arr);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
