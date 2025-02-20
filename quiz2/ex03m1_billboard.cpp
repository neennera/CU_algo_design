#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, x;
int dp[2][10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> x;
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
        if (i - 2 >= 0)
            dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]) + x;
    }
    cout << max(dp[0][N], dp[1][N]);
}