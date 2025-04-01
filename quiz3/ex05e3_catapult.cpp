#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, u, v, ct = 0;
bool vis[1001];
vector<vector<int>> path, rpath;
vector<int> order, ans;

void DFS1(int u)
{
    vis[u] = 1;
    for (auto v : path[u])
    {
        if (!vis[v])
            DFS1(v);
    }
    order.push_back(u);
}

void DFS2(int u)
{
    vis[u] = 1;
    ct++;
    for (auto v : rpath[u])

        if (!vis[v])
            DFS2(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    path.resize(N);
    rpath.resize(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> M;
        for (size_t j = 0; j < M; j++)
        {
            cin >> v;
            path[i].push_back(v);
            rpath[v].push_back(i);
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        if (!vis[i])
            DFS1(i);
    }
    memset(vis, 0, sizeof(vis));
    for (size_t i = 0; i < N; i++)
    {
        int u = order[N - i - 1];
        if (vis[u])
            continue;
        DFS2(u);
        ans.push_back(ct);
        ct = 0;
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
}