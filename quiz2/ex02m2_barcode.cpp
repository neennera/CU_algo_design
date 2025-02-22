#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K;
int dp[33][66][33];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    dp[1][0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < (2 * M); j++)
        {
            for (int k = 0; k <= K; k++)
            {
                int now = dp[i][j][k];
                if (!now)
                    continue;
                // go on with this color
                if ((j != M - 1) && (j != ((2 * M) - 1)))
                {
                    dp[i + 1][j + 1][k] += now;
                }
                // switch color
                // state store in second dimension [0 , M-1] is 0s, [M, 2M -1] is 1s
                if (k < K)
                {
                    dp[i + 1][(j < M) ? M : 0][k + 1] += now;
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < (2 * M); j++)
    {
        // for (int k = 0; k <= K; k++)
        // {
        //     if (dp[N][j][k])
        //         printf("%d %d %d\n", N, j, k);
        //     ans += dp[N][j][k];
        // }
        ans += dp[N][j][K];
    }
    cout << ans;
}