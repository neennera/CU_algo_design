#include <bits/stdc++.h>
using namespace std;
#define ll long long
int p, k, A, B;
vector<int> avg;
ll f(ll l, ll r)
{
    ll mid = (l + r) >> 1, ans;
    auto lo = lower_bound(avg.begin(), avg.end(), l);
    auto up = lower_bound(avg.begin(), avg.end(), r + 1);
    if (up == avg.begin() || lo == avg.end())
    {
        return A;
    }
    up--;
    int m = (up - lo) + 1;
    if (m == 0)
        ans = A;
    else
        ans = B * m * (r - l + 1);
    if (l == r)
        return ans;
    return min(ans, f(l, mid) + f(mid + 1, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p >> k >> A >> B;
    for (size_t i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        avg.push_back(x);
    }
    sort(avg.begin(), avg.end());

    cout << f(1, (1 << p));
}