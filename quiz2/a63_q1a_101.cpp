#include <bits/stdc++.h>
using namespace std;
#define ll long long

int MOD = 100000007;
int N;
ll dp[4][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 0; i < 4; ++i)
        dp[i][0] = 1;
    for (size_t i = 3; i <= N; i++)
    {
        int prev = (i - 1) % 2;
        int now = i % 2;

        dp[0][now] = (dp[0][prev] + dp[2][prev]) % MOD; // 00
        dp[1][now] = (dp[0][prev]) % MOD;               // 01
        dp[2][now] = (dp[1][prev] + dp[3][prev]) % MOD; // 10
        dp[3][now] = (dp[1][prev] + dp[3][prev]) % MOD; // 11
    }
    int sum = 0;
    for (int i = 0; i < 4; ++i)
        sum = (sum + dp[i][N % 2]) % MOD;
    cout << sum;
}