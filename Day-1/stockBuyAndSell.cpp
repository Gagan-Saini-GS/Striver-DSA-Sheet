#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;

    vector<int> mini(n, INT_MAX);
    vector<int> maxi(n, INT_MIN);

    mini[0] = arr[0];
    maxi[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        mini[i] = min(mini[i - 1], arr[i]);

    for (int i = n - 2; i >= 0; i--)
        maxi[i] = max(maxi[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
        ans = max(ans, abs(maxi[i] - mini[i]));

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = maxProfit(arr);
    cout << ans << endl;

    return 0;
}