#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &arr)
{
    // (1 + 2 + 3 +........+ n-1) = (n-1)*(n)/2 = TC O(N*N)
    // Swap TC O(N*N)
    // Each row reverse O(N*N)

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        // This is also right
        // reverse(arr[i].begin(),arr[i].end());
        int j = 0;
        while (j < n / 2)
        {
            swap(arr[i][j], arr[i][n - 1 - j]);
            j++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    rotate(arr);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}