#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ans(n);

    if (n <= m)
    {

        for (int i = 0; i < n; i++)
        {
            ans[i] = i + 1;
        }
    }

    else
    {

        int k = n / m;

        // int r=n%m;

        int j = 0;

        for (int i = 0; i < n; i++)
        {

            ans[i] = j + 1;

            j++;

            j %= m;
        }
    }

    for (int i = 0; i < n; i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;
}