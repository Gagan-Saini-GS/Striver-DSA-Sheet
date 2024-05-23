#include <bits/stdc++.h>
using namespace std;

bool comp(const vector<int> &first, const vector<int> &second)
{
    if (first[0] == second[0])
        return first[1] < second[1];

    return first[0] < second[0];
}

vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);

    vector<vector<int>> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        vector<int> temp = ans.back();

        if (arr[i][0] <= temp[1])
            ans.back()[1] = max(temp[1], arr[i][1]);
        else
            ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> arr[i][j];
    }

    vector<vector<int>> ans = merge(arr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }

    return 0;
}