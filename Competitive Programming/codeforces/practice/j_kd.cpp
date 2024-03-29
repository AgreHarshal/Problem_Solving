#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> pts(k); // Allocate space for k points
    for (int i = 0; i < k; i++)
    {
        cin >> pts[i].first >> pts[i].second;
    }

    int r, t;
    cin >> r >> t;

    int cnt = 0;
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= m; y++)
        {
            bool burn = false;
            for (size_t i = 0; i < k; i++)
            { // Use size_t for iterator type
                int fx = pts[i].first;
                int fy = pts[i].second;
                int dx = x - fx;
                int dy = y - fy;

                int dist2 = dx * dx + dy * dy; // Square distance for efficiency

                if (dist2 <= r * r)
                { // Check if inside or on circle
                    burn = true;
                    break;
                }
            }
            if (!burn)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0; // Explicitly return 0 to indicate successful execution
}
