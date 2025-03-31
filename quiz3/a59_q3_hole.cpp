#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int r, c, w, ct;
    bool operator<(const DATA &d2) const
    {
        // if (ct == d2.ct)
        //     return w > d2.w;
        return ct > d2.ct;
    }
};

int N, M;
char c;
bool a[1001][1001];
int dist[1001][1001];
priority_queue<DATA> pq;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int y, x;
    cin >> N >> y >> x;
    pq.push({y, x, 0, 0});
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= N; i++)
    {
        cin >> y >> x;
        a[y][x] = 1;
    }

    int ans = INT_MAX;
    DATA t;
    int yy[4] = {-1, 0, 0, 1};
    int xx[4] = {0, -1, 1, 0};
    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();
        if (dist[t.r][t.c] <= t.ct || t.ct >= ans)
            continue;
        // dist[t.r][t.c][0] = t.w;
        dist[t.r][t.c] = t.ct;
        for (int i = 0; i < 4; i++)
        {
            int ny = t.r + yy[i];
            int nx = t.c + xx[i];
            if (nx < 1 || ny < 1 || nx > 1000 || ny > 1000)
            {
                // cout << "OUT " << ny << " " << nx << "\n";
                ans = min(ans, t.ct + a[t.r][t.c]);
                continue;
            }
            if (dist[ny][nx] > t.ct + a[t.r][t.c])
            {
                pq.push({ny, nx, t.w + 1, t.ct + a[t.r][t.c]});
            }
        }
    }
    cout << ans;
}
