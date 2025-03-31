#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int r, c, w;
    bool operator<(const DATA &d2) const
    {
        return w > d2.w;
    }
};

int N, M;
char c;
bool a[101][101];
int dist[101][101];
priority_queue<DATA> pq;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> c;
            a[i][j] = (c == '.');
        }
    }
    if (a[1][1])
        pq.push({1, 1, 0});
    DATA t;
    int yy[4] = {-1, 0, 0, 1};
    int xx[4] = {0, -1, 1, 0};
    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();
        if (dist[t.r][t.c] <= t.w)
            continue;
        dist[t.r][t.c] = t.w;
        for (int i = 0; i < 4; i++)
        {
            int ny = t.r + yy[i];
            int nx = t.c + xx[i];
            if (nx < 1 || ny < 1 || nx > M || ny > N)
                continue;
            if (dist[ny][nx] > t.w + 1 && a[ny][nx])
            {
                pq.push({ny, nx, t.w + 1});
            }
        }
    }
    cout << (dist[N][M] > 1e9 ? -1 : dist[N][M]);
}
