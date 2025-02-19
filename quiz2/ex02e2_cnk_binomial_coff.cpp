#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
int dp[33][33];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (size_t i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 0; j <= K; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    cout << dp[N][K];
}