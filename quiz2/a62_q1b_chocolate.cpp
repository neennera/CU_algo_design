#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
ll dp[1005];
int c[11];
int MOD = 1000003;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[0] = 1;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i - c[j] < 0)
                break;

            dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
        }
    }
    cout << dp[N];
}