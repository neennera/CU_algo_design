#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, a, b, c;
int dp[4004];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++)
    {
        if (i - a == 0 || i - b == 0 || i - c == 0)
            dp[i] = 1;
        if (i - a > 0 && dp[i - a] != 0)
            dp[i] = max(dp[i], dp[i - a] + 1);
        if (i - b > 0 && dp[i - b] != 0)
            dp[i] = max(dp[i], dp[i - b] + 1);
        if (i - c > 0 && dp[i - c] != 0)
            dp[i] = max(dp[i], dp[i - c] + 1);
    }
    cout << dp[n];
}