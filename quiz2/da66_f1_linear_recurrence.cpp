#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
int dp[1005];
int a[1005], c[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;
    for (size_t i = 1; i <= K; i++)
    {
        cin >> c[i];
    }
    for (size_t i = 0; i < K; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= N; i++)
    {
        if (i < K)
        {
            dp[i] = (a[i]) % 32717;
        }
        else
        {
            for (int j = 1; j <= K; j++)
            {
                dp[i] += (c[j] * dp[i - j]) % 32717;
                dp[i] = (dp[i]) % 32717;
            }
        }
    }
    cout << dp[N];
}