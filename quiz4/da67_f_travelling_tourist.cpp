#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K, x, u, v, w;
vector<int> ls;
int dist[501][501], ans = INT_MAX;
struct DATA
{
    int u, state, dist;
    bool operator<(const DATA &o2) const
    {
        if (dist == o2.dist)
        {
            int n1 = 0, n2 = 0;
            for (int i = 0; i < K; i++)
            {
                n1 += (state & (1 << i));
                n2 += (o2.state & (1 << i));
            }
            return n1 < n2;
        }
        return dist > o2.dist;
    }
};
void f(int u, int state)
{
    priority_queue<DATA> pq;
    pq.push({u, state, 0});
    while (!pq.empty())
    {
        int u = pq.top().u;
        int state = pq.top().state;
        int d = pq.top().dist;
        pq.pop();
        if (d >= ans)
            continue;
        if (state == (1 << K) - 1)
        {
            ans = min(ans, d);
            continue;
        }
        for (int i = 0; i < K; i++)
        {
            if (state & (1 << i))
                continue;
            pq.push({ls[i], state | (1 << i), d + dist[u][ls[i]]});
        }
    }
}

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
    // first city should be one of target city
    for (int i = 0; i < K; i++)
        f(ls[i], (1 << i));
    cout << ans;
}