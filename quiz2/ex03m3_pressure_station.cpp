#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K, a;
int ans = INT_MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    if (K >= N)
        K = N - 1; // at least you need 1 station
    int dp[N + 2];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    // what is the lowest cost when you buy station i ?
    for (int i = 1; i <= N; i++)
    {
        cin >> a;
        // see in range [i - 2K + 1 , i - 1] that is last station to buy
        // since station i - 2K + 1 combine station i still can cover all land

        for (int k = 1; k <= 2 * K + 1; k++)
        {
            // when you are station i that i > K + 1, you have to choose at least one station before you
            if (i - k < 0 || (i - k == 0 && i > K + 1))
                break;
            dp[i] = min(dp[i], dp[i - k] + a);
        }
    }

    // you have to buy at least 1 station in range [N-K, N]
    for (int i = N - K; i <= N; i++)
    {
        if (i == 0)
            continue;
        ans = min(ans, dp[i]);
    }
    cout << ans;
}