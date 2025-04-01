#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, w, ww, ans, x, K;
vector<vector<int>> path(100001);
int dist[100001], c[100001];
priority_queue<pair<int, int>> pq; // -w,u

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> x;
        pq.push({0, x});
    }
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
        dist[i] = INT_MAX;
    }
    for (int j = 0; j < M; j++)
    {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    while (!pq.empty())
    {
        u = pq.top().second;
        w = -pq.top().first;
        pq.pop();
        w = w + c[u];
        if (dist[u] < w)
            continue;
        dist[u] = w;
        for (auto v : path[u])
        {
            if (dist[v] <= w + c[v])
                continue;
            pq.push({-w, v});
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] > 1e9)
            continue;
        ans = max(ans, dist[i]);
    }
    cout << ans;
}