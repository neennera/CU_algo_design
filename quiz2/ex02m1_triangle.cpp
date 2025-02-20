#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int a[1003][1003];
int dp[1003][1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dp[N][i]);
    }
    cout << ans;
}