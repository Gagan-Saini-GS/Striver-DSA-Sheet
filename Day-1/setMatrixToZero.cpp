#include <bits/stdc++.h>
using namespace std;

// Bruth Force

// void setToZero(vector<vector<int>>& arr,int row,int col,int n,int m){
//     for(int i=0;i<n;i++){
//         arr[i][col] = 0;
//     }
//     for(int j=0;j<m;j++){
//         arr[row][j] = 0;
//     }
// }

// void setZeros(vector<vector<int>> &arr)
// {
//     int n = arr.size();
//     int m = arr[0].size();
//     vector<vector<int>> temp = arr;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (temp[i][j] == 0)
//             {
//                 setToZero(arr, i, j, n, m);
//             }
//         }
//     }
// }

// Better
// void setZeros(vector<vector<int>> &arr)
// {
// int n = arr.size(), m = arr[0].size();
// vector<int> row(n,0);
// vector<int> col(m,0);

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         if(arr[i][j] == 0){
//             row[i] = 1;
//             col[j] = 1;
//         }
//     }
// }

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         if(row[i] || col[j]){
//             arr[i][j] = 0;
//         }
//     }
// }
// }

// Best
void setZeroes(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    int topLeft = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;

                if (j != 0)
                    arr[0][j] = 0;
                else
                    topLeft = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][0] == 0 || arr[0][j] == 0)
                arr[i][j] = 0;
        }
    }

    for (int j = 1; j < m; j++)
    {
        if (arr[0][0] == 0 || arr[0][j] == 0)
            arr[0][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (topLeft == 0 || arr[i][0] == 0)
            arr[i][0] = 0;
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

    setZeroes(arr);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }

    return 0;
}