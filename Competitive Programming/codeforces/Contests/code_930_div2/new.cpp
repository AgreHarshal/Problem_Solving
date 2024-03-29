/*
author : ayush1501garg
question: C_Bitwise_Operation_Wizard.cpp
time: 2024-02-29 21:54:02
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int reverseBits(int num)
{
    // Find the number of bits in the given number
    int numBits;
    for (int i = 32; i >= 0; i--)
    {
        if (num & (1ll << i))
        {
            numBits = i;
            break;
        }
    }
    int result = 0;
    for (int i = 0; i < numBits; ++i)
    {
        if ((num & (1 << i)) == 0)
        {
            result |= 1 << (i);
        }
    }

    return result;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int hi = n - 1;
        int lo = reverseBits(hi);
        cout << hi << "  " << lo << endl;
        int mnIndex = 0;
        for (int i = 1; i < n; i++)
        {
            cout << "? " << mnIndex << " " << mnIndex << " " << i << " " << i << endl;
            cout << flush;
            char cmp;
            cin >> cmp;
            if (cmp == '<')
            {
                mnIndex = i;
            }
        }
        int zeroIndex = mnIndex;
        int nIndex = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "? " << zeroIndex << " " << i << " " << zeroIndex << " " << nIndex << endl;
            cout << flush;
            char cmp;
            cin >> cmp;
            if (cmp == '<')
            {
                nIndex = i;
            }
        }
        int yIndex = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "? " << nIndex << " " << i << " " << nIndex << " " << yIndex << endl;
            cout << flush;
            char cmp;
            cin >> cmp;
            if (cmp == '<')
            {
                yIndex = i;
            }
        }

        cout << "! " << nIndex << " " << yIndex << endl;
    }
}