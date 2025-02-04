#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, a[200002], x;
ll cur_mn = 0, minn = INT_MAX;
ll cur_mx = 0, maxx = INT_MIN;
ll sum = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        sum += x;
        cur_mn = min(cur_mn + x, x);
        cur_mx = max(cur_mx + x, x);
        maxx = max(cur_mx, maxx);
        minn = min(cur_mn, minn);
    }
    cout << max(maxx, (sum == minn ? maxx : sum - minn));
}