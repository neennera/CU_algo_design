#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K[8], u, v, w, target, best, b[20];
vector<vector<pair<int, int>>> path(21);
bool vis[21];

bool f(int u, int dist)
{
    // printf("%d %d %d\n", target, u, dist);
    if (dist == target)
    {
        // cout << "found true\n";
        return true;
    }
    int best = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (!vis[i])
            best += b[i];
    }

    if (dist > target || dist + best < target)
        return false;
    for (size_t i = 0; i < path[u].size(); i++)
    {

        int v = path[u][i].first;
        int w = path[u][i].second;
        // it a single path -> can't revisit
        if (vis[v])
            continue;
        vis[v] = true;
        if (f(v, dist + w))
        {
            return true;
        }
        vis[v] = false;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (size_t i = 0; i < 8; i++)
    {
        cin >> K[i];
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        path[u].push_back({v, w});
        path[v].push_back({u, w});
        b[u] = max(b[u], w);
        b[v] = max(b[v], w);
    }

    for (size_t i = 0; i < 8; i++)
    {
        target = K[i];
        bool ck = 0;
        for (size_t j = 0; j < N; j++)
        {
            // memset(vis, 0, sizeof(vis));
            for (size_t k = 0; k < N; k++)
            {
                vis[k] = 0;
            }
            vis[j] = true;
            ck = ck | f(j, 0);
            if (ck)
                break;
        }
        cout << (ck ? "YES\n" : "NO\n");
    }
}
