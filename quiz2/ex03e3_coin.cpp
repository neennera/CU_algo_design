#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
int dp[10005];
int c[22];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> c[N - i - 1];
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i - c[j] < 0)
                break;
            // cout << i << " " << c[j] << " " << dp[i - c[j]] << "\n";
            dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    // for (size_t i = 1; i <= M; i++)
    // cout << dp[i] << " ";
    cout << dp[M];
}