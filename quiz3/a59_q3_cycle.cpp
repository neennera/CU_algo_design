#include <bits/stdc++.h>
using namespace std;

int N, M, u, v;
vector<int> path[111111];
int vis[111111];
int num[111111];
int f(int u, int pa = -1, int ct = 1)
{
    if (vis[u])
    {
        cout << ct - num[u];
        exit(0);
    }
    num[u] = ct;
    vis[u] = 1;
    for (int i = 0; i < path[u].size(); i++)
    {
        v = path[u][i];
        if (v == pa)
            continue;
        f(v, u, ct + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    memset(num, 0, sizeof(num));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++)
    {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    f(0);
}