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
vector<vector<int>> a, dist;
priority_queue<DATA> pq;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    a.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M));
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> a[i][j];
            dist[i][j] = INT_MAX;
        }
    }

    DATA t;
    int yy[4] = {-1, 0, 0, 1};
    int xx[4] = {0, -1, 1, 0};

    pq.push({0, 0, 0});
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

            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            // cout << ">>> " << ny << " " << nx << " " << dist[ny][nx] << " " << t.w + a[ny][nx] << "\n";
            if (dist[ny][nx] > t.w + a[ny][nx])
            {

                pq.push({ny, nx, t.w + a[ny][nx]});
            }
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {

            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
