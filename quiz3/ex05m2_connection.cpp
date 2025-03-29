#include <bits/stdc++.h>
using namespace std;

int N, M, K, u, v, ct, ans = 1;
vector<list<int>> path(100000);
bool vis[100000];
int deg[5];

void solve(int st)
{
    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg)); // a number of node within degree 0 to 4 from st (if multiple, use least one)
    queue<pair<int, int>> q;     // u node, ct distance from st
    vis[st] = 1;
    deg[0] = 1;
    q.push({st, 0});
    while (!q.empty())
    {
        u = q.front().first;
        ct = q.front().second;
        q.pop();
        for (auto v : path[u])
        {
            if (vis[v])
                continue;
            q.push({v, ct + 1});
            deg[ct + 1]++;
            vis[v] = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i <= K; i++)
        sum += deg[i];
    ans = max(ans, sum);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    for (size_t i = 0; i < N; i++)
    {
        solve(i);
    }
    cout << ans;
}
