#include <bits/stdc++.h>
using namespace std;

// sort 0 1 2 (DNF sort)
void sort012(vector<int> &arr)
{
    // 100% faster 😁😁 But don't make any sense
    // sort(arr.begin(),arr.end());

    int n = arr.size();
    int zero = 0, one = 0, two = n - 1;

    while (one <= two)
    {
        if (arr[one] == 0)
        {
            swap(arr[zero], arr[one]);
            zero++;
            one++;
        }
        else if (arr[one] == 1)
        {
            one++;
        }
        else
        {
            swap(arr[one], arr[two]);
            two--;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort012(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}