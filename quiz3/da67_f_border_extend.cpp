#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int i, j, w;
    bool operator<(const DATA &d2) const
    {
        return w > d2.w;
    }
};

int N, M, K;
int xx[4] = {0, -1, 1, 0};
int yy[4] = {-1, 0, 0, 1};
int m[1001][1001];
int dist[1001][1001];
// bool vis[1001][1001];
priority_queue<DATA> pq;
int main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dist, 0x3f, sizeof(dist));
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> m[i][j];
            if (m[i][j])
                pq.push({i, j, 0});
        }
    }
    // cout << "------\n";
    int i, j, w;
    while (!pq.empty())
    {

        i = pq.top().i;
        j = pq.top().j;
        w = pq.top().w;
        // printf("%d %d %d\n", i, j, w);
        pq.pop();
        if (dist[i][j] <= w)
            continue;
        dist[i][j] = w;
        if (m[i][j] == 0)
            m[i][j] = 2;
        if (w >= K)
            continue;
        for (int ii = 0; ii < 4; ii++)
        {
            int nx = j + xx[ii];
            int ny = i + yy[ii];
            if (nx < 1 || ny < 1 || nx > M || ny > N)
                continue;
            if (dist[ny][nx] <= w + 1)
                continue;
            pq.push({ny, nx, w + 1});
        }
    }
    // cout << "---------\n";
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}