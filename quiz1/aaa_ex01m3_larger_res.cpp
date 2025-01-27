#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
ll chef[1001], q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> chef[i];
    }
    while (M--)
    {
        cin >> q;
        if (q <= N)
        {
            cout << 0 << endl;
            continue;
        }
        q -= N;
        ll l = 0, r = 10e15, ans = LLONG_MAX;
        while (l <= r)
        {
            ll mid = (l + r) / 2, cus = 0;
            for (size_t i = 0; i < N; i++)
            {
                cus += mid / chef[i];
                if (cus >= q)
                    break;
            }
            if (cus >= q)
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}