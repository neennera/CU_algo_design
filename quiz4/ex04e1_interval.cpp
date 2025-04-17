#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int s, w;
    bool operator<(const DATA &d2) const
    {
        return w > d2.w;
    }
};
int N;
queue<int> q;
priority_queue<DATA> pq;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int x;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        q.push(x);
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        pq.push({q.front(), x});
        q.pop();
    }
    int t = 0, ans = 0;
    while (!pq.empty())
    {
        ans++;
        t = pq.top().w;
        pq.pop();
        while (!pq.empty() && pq.top().s < t)
            pq.pop();
    }
    cout << ans;
}