#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, W, st = 0;
ll cur = 0, maxx = LLONG_MIN, x;
deque<pair<int, ll>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> W;
    q.push_back({-1, 0}); // basecase
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        cur += x;
        while (!q.empty() && i - q.front().first > W)
        {
            q.pop_front();
        }
        maxx = max(maxx, cur - q.front().second);
        while (!q.empty() && q.back().second >= cur)
        {
            q.pop_back();
        }
        q.push_back({i, cur});
    }
    cout << maxx;
}