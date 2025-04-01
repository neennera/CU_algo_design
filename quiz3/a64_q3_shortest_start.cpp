#include <bits/stdc++.h>
using namespace std;

int N, M, ed, u, v, w, stt, ww;
int dist[5005];
vector<vector<pair<int, int>>> path;
priority_queue<pair<int, int>> pq; // -w,u

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dist, 0x3f, sizeof(dist));
    cin >> N >> M >> stt >> ed;
    path.resize(N);
    for (size_t i = 0; i < stt; i++)
    {
        int st;
        cin >> st;
        dist[st] = 0;
        pq.push({0, st});
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        path[u].push_back({v, w});
    }

    while (!pq.empty())
    {
        w = -1 * pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (dist[u] < w)
            continue;
        // cout << u << "--\n";
        for (int i = 0; i < path[u].size(); i++)
        {
            v = path[u][i].first;
            ww = path[u][i].second;
            if (dist[v] <= w + ww)
                continue;
            dist[v] = w + ww;
            pq.push({-(w + ww), v});
        }
    }
    cout << dist[ed];
}