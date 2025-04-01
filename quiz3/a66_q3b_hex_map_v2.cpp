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
int a1, b1, a2, b2;
int a[301][301];
int dist[301][301];
pair<int, int> walk[2][6] = {
    {{0, -1}, {0, 1}, {-1, 0}, {-1, 1}, {1, 0}, {1, 1}},
    {{0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {1, -1}, {1, 0}}};
priority_queue<DATA> pq;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    cin >> a1 >> b1 >> a2 >> b2;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(dist, 0x3f, sizeof(dist));
    pq.push({a1, b1, a[a1][b1]});
    DATA t;
    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();
        if (dist[t.r][t.c] < t.w)
            continue;
        dist[t.r][t.c] = t.w;
        for (int i = 0; i < 6; i++)
        {
            int ny = t.r + walk[(t.r + 1) % 2][i].first;
            int nx = t.c + walk[(t.r + 1) % 2][i].second;
            if (nx < 1 || ny < 1 || nx > M || ny > N)
                continue;
            if (dist[ny][nx] > t.w + a[ny][nx])
            {
                pq.push({ny, nx, t.w + a[ny][nx]});
                dist[ny][nx] = t.w + a[ny][nx];
            }
        }
    }

    cout << (dist[a2][b2] > 1e9 ? -1 : dist[a2][b2]);
}
