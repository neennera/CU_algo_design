#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct DATA
{
    ll u, v;
    unsigned long long w;
    bool operator<(const DATA &d2) const
    {
        return (w) < (d2.w);
    }
};
int N, pa[2002], u, v, pu, pv;
unsigned long long a[2002];
unsigned long long ans = 0, w;
priority_queue<DATA> pq;
int fp(int n)
{
    if (pa[n] == n)
        return n;
    return pa[n] = fp(pa[n]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        pa[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            pq.push({i, j, a[i] ^ a[j]});
        }
    }
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
        N--;
        ans += w;
    }
    cout << ans;
}