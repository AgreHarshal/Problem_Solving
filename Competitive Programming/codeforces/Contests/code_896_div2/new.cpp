/*
author : ayush1501garg
question: A_Fill_in_the_Matrix.cpp
time: 2023-09-11 01:06:43
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (m == 1)
        {
            cout << 0 << endl;
        }
        else if (n >= m - 1)
        {
            cout << m << endl;
        }
        else
        {
            cout << n + 1 << endl;
        }
        for (int i = 0; i < min(n, m - 1); i++)
        {
            for (int j = m - i; j < m; j++)
            {
                cout << j << " ";
            }
            for (int k = 0; k < m - i; k++)
            {
                cout << k << " ";
            }
            cout << endl;
        }
        for (int i = min(n, m - 1); i < n; i++)
        {
            for (int k = 0; k < m; k++)
            {
                cout << k << " ";
            }
            cout << endl;
        }
    }
}