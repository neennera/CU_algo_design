#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int u, v, w;
    bool operator<(const DATA &d2) const
    {
        return w > d2.w;
    }
};
int N, pa[1005], u, v, w, pu, pv;
priority_queue<DATA> pq;
int fp(int n)
{
    if (pa[n] == n)
        return n;
    return pa[n] = fp(pa[n]);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i <= N; i++)
        pa[i] = i;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            cin >> w;
            pq.push({i, j, w});
        }
    }
    int ans = 0;
    while (N > 1 && !pq.empty())
    {
        u = pq.top().u;
        v = pq.top().v;
        w = pq.top().w;
        pq.pop();
        pu = fp(u);
        pv = fp(v);
        if (pu == pv)
            continue;
        pa[pu] = pv;
        ans += w;
        N--;
    }
    cout << ans;
}