#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, a, now, prv;
int dp[11][10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // I don't know why, but to create area 0 if only be 0 price in (0,0)
    // maybe it can be case that want 1, but there 1, 2, 3 -> 1, (2-2), (3-3)
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        now = i + 1;
        prv = i;
        cin >> a;
        for (int m = M; m > 0; m--)
        {
            for (int k = 1; k <= 100; k++)
            {
                if (m - (k * k) < 0)
                    break;
                dp[now][m] = min(dp[now][m], (dp[prv][m - (k * k)] + ((a - k) * (a - k))));
            }
        }
    }
    cout << (dp[N][M] >= 1e9 ? -1 : dp[N][M]);
}