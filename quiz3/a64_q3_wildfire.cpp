#include <bits/stdc++.h>
using namespace std;

int N, K, M, sum, x, u, v;
int buti[5005];
vector<list<int>> path(5005);
queue<int> q, fire;
bool vis[5005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        buti[i] = x;
        sum += x;
    }
    for (size_t i = 0; i < K; i++)
    {
        cin >> x;
        fire.push(x);
    }
    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v;
        path[u].push_back(v);
    }
    while (!fire.empty())
    {
        q.push(fire.front());
        fire.pop();
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            if (vis[u])
                continue;
            sum -= buti[u];
            vis[u] = 1;
            // printf("\n>>%d %d\n", u, sum);
            for (auto v : path[u])
            {
                if (vis[v])
                    continue;
                q.push(v);
            }
        }
        // cout << "------- ";
        cout << sum << " ";
    }
}