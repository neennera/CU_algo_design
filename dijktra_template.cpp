#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, w, ww, ans;
vector<vector<pair<int, int>>> path(701);
int dist[701];
priority_queue<pair<int, int>> pq; // -w,u
void f()
{
    memset(dist, 0x3f, sizeof(dist));
    pq.push({0, 1});
    while (!pq.empty())
    {
        u = pq.top().second;
        w = -pq.top().first;
        pq.pop();
        if (dist[u] < w)
            continue;
        dist[u] = w;
        for (int i = 0; i < path[u].size(); i++)
        {
            v = path[u][i].first;
            ww = path[u][i].second;
            if (dist[v] <= w + ww)
                continue;
            pq.push({-(w + ww), v});
            dist[v] = w + ww;
        }
    }
    ans = dist[2];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> ans;
    path[1].push_back({2, ans});
    path[2].push_back({1, ans});
    for (size_t i = 2; i < N; i++)
    {
        cin >> M;
        for (size_t j = 0; j < M; j++)
        {
            cin >> v >> w;
            path[i + 1].push_back({v, w});
            path[v].push_back({i + 1, w});
        }
        f();
        cout << ans << " ";
    }
}