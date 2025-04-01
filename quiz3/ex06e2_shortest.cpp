#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int u, v, w;
};

int N, M, st, u, v, w;
int dist[105];
vector<DATA> path;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dist, 0x3f, sizeof(dist));
    cin >> N >> M >> st;
    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        path.push_back({u, v, w});
    }
    dist[st] = 0;
    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            u = path[j].u;
            v = path[j].v;
            w = path[j].w;
            if (dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    bool ck = 0;
    for (size_t j = 0; j < M; j++)
    {
        u = path[j].u;
        v = path[j].v;
        w = path[j].w;
        if (dist[v] > dist[u] + w)
        {
            ck = 1;
            break;
        }
    }
    if (ck)
        cout << -1;
    else
    {
        for (size_t i = 0; i < N; i++)
        {
            cout << dist[i] << " ";
        }
    }
}