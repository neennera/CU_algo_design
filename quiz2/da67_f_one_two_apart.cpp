#include <bits/stdc++.h>
using namespace std;
#define ll long long

int MOD = 100000007;
int N;
ll dp[7][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N == 1)
    {
        printf("3");
        return 0;
    }
    if (N == 2)
    {
        printf("7");
        return 0;
    }
    for (int i = 0; i < 7; ++i)
        dp[i][0] = 1;
    for (size_t i = 3; i <= N; i++)
    {
        int prev = (i - 1) % 2;
        int now = i % 2;

        dp[0][now] = (dp[0][prev] + dp[2][prev] + dp[5][prev]) % MOD; // 00
        dp[1][now] = (dp[0][prev] + dp[2][prev]) % MOD;               // 01
        dp[2][now] = (dp[1][prev] + dp[3][prev]) % MOD;               // 10
        dp[3][now] = (dp[1][prev] + dp[3][prev]) % MOD;               // 11
        dp[4][now] = (dp[0][prev] + dp[5][prev]) % MOD;               // 02
        dp[5][now] = (dp[4][prev] + dp[6][prev]) % MOD;               // 20
        dp[6][now] = (dp[4][prev] + dp[6][prev]) % MOD;               // 22
    }
    int sum = 0;
    for (int i = 0; i < 7; ++i)
        sum = (sum + dp[i][N % 2]) % MOD;
    cout << sum;
}