#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, x;
int dp[10004][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> x;
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][3]);     // 000
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][3]) + x; // 001
        dp[i][2] = dp[i - 1][1];                        // 010
        dp[i][3] = dp[i - 1][2];                        // 100
    }
    cout << max({dp[N][0], dp[N][1], dp[N][2], dp[N][3]});
}