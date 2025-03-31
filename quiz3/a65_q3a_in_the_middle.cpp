#include <bits/stdc++.h>
using namespace std;
int N, M, u, v;
int w;
vector<vector<int>> path;
vector<vector<int>> dist(3);
vector<int> start;

void solve(int idx, int st)
{
    dist[idx].resize(N + 1);
    for (int i = 1; i <= N; i++)
        dist[idx][i] = INT_MAX;
    queue<pair<int, int>> s;
    s.push({st, 0});
    dist[idx][st] = 0;
    while (!s.empty())
    {
        u = s.front().first;
        w = s.front().second;
        s.pop();
        if (dist[idx][u] < w)
            continue;
        for (auto v : path[u])
        {
            if (dist[idx][v] <= w + 1)
                continue;
            dist[idx][v] = w + 1;
            s.push({v, w + 1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    path.resize(N + 1);
    for (size_t i = 0; i < 3; i++)
    {
        cin >> u;
        start.push_back(u);
    }

    for (size_t i = 1; i <= N; i++)
    {
        cin >> M;
        for (size_t j = 0; j < M; j++)
        {
            cin >> v;
            path[i].push_back(v);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        solve(i, start[i]);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
        if (dist[0][i] == INT_MAX || dist[1][i] == INT_MAX || dist[2][i] == INT_MAX)
            continue;
        int mx = max(dist[0][i], max(dist[1][i], dist[2][i]));
        ans = min(ans, mx);
    }
    cout << ans;
}