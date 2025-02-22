#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
int a[505][505];
ll dp[505][505][3]; // last is X, Y, Z
int MOD = 100000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> a[i][j];
        }
    }
    // we'll look ahead to next column
    for (int j = 1; j < M; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (a[i][j] == 1)
                continue;
            if (j == 1)
            {
                dp[i - 1][j + 1][0] += 1;
                dp[i][j + 1][1] += 1;
                dp[i + 1][j + 1][2] += 1;
                continue;
            }
            // case 1 : last time we use X (j-1)
            dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i][j][0]) % MOD;         // use Y
            dp[i + 1][j + 1][2] = (dp[i + 1][j + 1][2] + dp[i][j][0]) % MOD; // use Z
            // case 2 : last time we use Y (j)
            dp[i - 1][j + 1][0] = (dp[i - 1][j + 1][0] + dp[i][j][1]) % MOD; // use X
            dp[i + 1][j + 1][2] = (dp[i + 1][j + 1][2] + dp[i][j][1]) % MOD; // use Z
            // case 3 : last time we use z (j+1)
            dp[i - 1][j + 1][0] = (dp[i - 1][j + 1][0] + dp[i][j][2]) % MOD; // use X
            dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i][j][2]) % MOD;         // use Y
            // printf("%d %d : %5d %5d %5d\n", i, j, dp[i][j][0], dp[i][j][1], dp[i][j][2]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (a[i][M] == 1)
            continue;
        ans = (ans + dp[i][M][0] + dp[i][M][1] + dp[i][M][2]) % MOD;
    }
    cout << ans;
}