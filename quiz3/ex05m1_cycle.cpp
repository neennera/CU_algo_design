#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, pa;
map<int, list<int>> path;
vector<bool> vis;
bool f(int st)
{
    queue<pair<int, int>> q;
    q.push({st, -1});
    while (!q.empty())
    {
        u = q.front().first;
        pa = q.front().second;
        q.pop();
        vis[u] = 1;
        for (auto v : path[u])
        {
            if (v != pa && vis[v])
                return 1;
            if (vis[v])
                continue;
            q.push({v, u});
        }
    }
    return 0;
}

void solve()
{
    cin >> N >> M;
    path.clear();
    vis.assign(N, false);
    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    bool ck = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (vis[i])
            continue;

        ck = ck | f(i);
        // cout << ">> " << i << " " << ck << "\n";
    }
    cout << (ck ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        solve();
    }
}