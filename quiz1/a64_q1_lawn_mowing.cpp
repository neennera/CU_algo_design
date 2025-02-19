#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
ll pf[500005], x, K, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> x;
        pf[i] = pf[i - 1] + x;
    }
    while (M--)
    {
        cin >> a >> b;
        a++;
        ll l = a, r = N, ans = 0;
        while (l <= r)
        {
            // cout << l << " " << r << " " << ans << "\n";
            ll mid = (l + r) >> 1;
            ll p = (pf[mid] - pf[a - 1]) + ((mid - a + 1) * K);
            if (p <= b)
            {
                ans = max(ans, pf[mid] - pf[a - 1]);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << endl;
        // cout << ">>>> " << ans << endl;
    }
}