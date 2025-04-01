#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct DATA
{
    int u;
    ll w;
    bool operator<(const DATA &d2) const
    {
        return w > d2.w;
    }
};

int N, M;
char c;
ll a[1001][1001];
ll dist[1001];
priority_queue<DATA> pq;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    // memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> a[i][j];
        }
        dist[i] = INT_MAX;
    }
    pq.push({1, 0});
    dist[1] = 0;
    DATA t;
    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();

        if (dist[t.u] < t.w)
            continue;
        dist[t.u] = t.w;
        for (int j = 1; j <= N; j++)
        {
            if (t.u == j || a[t.u][j] == -1)
                continue;
            if (dist[j] <= t.w + a[t.u][j])
                continue;
            dist[j] = t.w + a[t.u][j];
            pq.push({j, t.w + a[t.u][j]});
        }
    }
    bool ck = 1;
    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INT_MAX)
            continue;
        ans = max(ans, dist[i]);
        ck = 0;
    }
    cout << (ck ? -1 : ans);
}
