#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int a[505];
ll dp[505][505];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    for (int j = 1; j <= N; j++)
    {
        for (int i = j - 1; i > 0; i--)
        {
            dp[i][j] = (a[i] * a[j]) + dp[i + 1][j - 1];
            for (int k = i; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[1][N];
}