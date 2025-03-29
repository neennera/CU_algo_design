#include <bits/stdc++.h>
using namespace std;

int N, M, u, v;
vector<list<int>> path(100000);
bool vis[100000];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        if (vis[i])
            continue;
        // case 1 : single component
        if (path[i].empty())
        {
            // cout << i << "is single\n";
            ans++;
            continue;
        }
        // case 2 : check graph

        bool notcycle = 1;
        q.push({i, -1});
        int pa;
        while (!q.empty())
        {
            u = q.front().first;
            pa = q.front().second;
            q.pop();
            vis[u] = 1;
            // case > 2 child
            if (path[u].size() > 2)
                notcycle = 0;
            for (auto v : path[u])
            {
                // cout << u << " - " << v << "\n";
                // case cycle
                if (vis[v] && v != pa)
                    notcycle = 0;
                if (vis[v])
                    continue;
                q.push({v, u});
            }
        }
        // cout << i << " not cycle is " << notcycle << "\n";
        ans += notcycle;
    }
    cout << ans;
}
