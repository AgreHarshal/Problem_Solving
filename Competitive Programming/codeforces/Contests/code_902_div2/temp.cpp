#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int n, m, k, t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        if (k >= 4)
        {
            printf("0\n");
            continue;
        }
        if (k == 1)
        {
            printf("1\n");
            continue;
        }
        int cnt2 = (m >= n ? (m - n) / n + n : m);
        if (k == 2)
        {
            printf("%d\n", cnt2);
            continue;
        }
        if (k == 3)
        {
            printf("%d\n", m - cnt2);
            continue;
        }
    }
    return 0;
}