#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K, ans = 0;
vector<vector<int>> path(1001);
int dist[1001];

void f(int u, int w)
{
    if (w >= dist[u])
        return;
    dist[u] = w;
    for (auto v : path[u])
    {
        if (dist[v] <= w + 1)
            continue;
        f(v, w + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    memset(dist, 0x3f, sizeof(dist));

    f(0, 0);
    for (size_t i = 1; i <= N; i++)
    {
        if (dist[i] == K)
            ans++;
    }
    cout << ans;
}