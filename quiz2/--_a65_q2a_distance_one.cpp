#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
int MOD = 100000007;
ll dp[2][5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    dp[0][1] = dp[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        if (i - K >= 1)
        {
            dp[1][i] = (dp[0][i - K] + dp[1][i - K]) % MOD;
        }
        else
        {
            dp[1][i] = 1;
        }
    }
    cout << (dp[0][N] + dp[1][N]) % MOD;
}