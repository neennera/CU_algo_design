#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int dp[2][3]; // 00 01 10
int MOD = 100000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    dp[0][0] = 3;
    dp[0][1] = dp[0][2] = 2;
    cin >> N;
    for (int i = 3; i <= N; i++)
    {
        int prev = (i - 1) % 2;
        int now = i % 2;
        dp[now][0] = (dp[prev][0] + dp[prev][1] + dp[prev][2]) % MOD;
        dp[now][1] = (dp[prev][0] + dp[prev][2]) % MOD;
        dp[now][2] = (dp[prev][0] + dp[prev][1]) % MOD;
    }

    cout << (dp[N % 2][0] + dp[N % 2][1] + dp[N % 2][2]) % MOD;
}