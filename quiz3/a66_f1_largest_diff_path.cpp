#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, ans = 0;
int a[2002];
vector<vector<int>> p(2002), rp(2002); // Use vector<int> instead of list<int>
int dp_min[2002], dp_max[2002];        // Separate arrays for dp
bool vis[2002];
bool onck[2002];

void f(int u, int pa)
{
    // cout << u << " " << pa << "\n";
    if (vis[u])
        return;

    int minup = a[u], maxdown = a[u];
    onck[u] = 1;
    for (auto v : p[u])
    {
        if (v != pa && !onck[v])
        {
            f(v, u);
            maxdown = max(maxdown, dp_max[v]);
        }
    }
    for (auto v : rp[u])
    {
        if (v != pa && !onck[v])
        {
            f(v, u);
            minup = min(minup, dp_min[v]);
        }
    }
    dp_min[u] = minup;
    dp_max[u] = maxdown;
    ans = max(ans, maxdown - minup);
    vis[u] = 1;
    onck[u] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        p[u].push_back(v);
        rp[v].push_back(u);
    }

    f(0, -1);
    cout << ans;
}