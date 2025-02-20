#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, x;
int dp[502][502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            cin >> x;
            if (i == 1 || j == 1)

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + x;

            else
                dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]) + x, dp[i - 1][j - 1] + (2 * x));
        }
    }
    cout << dp[N][M];
}