#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K, x, u, v, w;
vector<int> ls;
vector<vector<int>> path(501);
int dist[501][501];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, 0x3f, sizeof(dist));
    cin >> N >> M >> K;
    for (size_t i = 0; i < K; i++)
    {
        cin >> x;
        ls.push_back(x);
    }
    for (size_t i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }
    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        path[u].push_back(v);
        path[v].push_back(u);
        dist[u][v] = dist[v][u] = w;
    }

    for (size_t k = 1; k <= N; k++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            for (size_t j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = INT_MAX;
    ll ct = (1 << K) - 1;
    priority_queue<pair<int, int>> pq;

    cout << ans;
}