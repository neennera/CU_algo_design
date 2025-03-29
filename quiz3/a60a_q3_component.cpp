#include <bits/stdc++.h>
using namespace std;

int N, M, u, v;
vector<list<int>> path;
bool vis[100005];
void f(int st)
{
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (auto v : path[u])
        {
            if (vis[v])
                continue;
            q.push(v);
            vis[v] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    path.resize(N + 1);
    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    int ct = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (vis[i])
            continue;
        ct++;
        f(i);
    }
    cout << ct;
}