#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
int dp[505][505];
int MOD = 1997;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        dp[i][1] = 1; // one group, always 1 way

        // make sure to limit seperate group to i
        for (int j = 2; j <= min(i, K); j++)
        {
            // case 1 : {1} {i-1} : new stone is new group
            // Find how to divide i-1 stone in j-1 group
            // each stone is the same -> no need to *j

            // case 2 : there are already j group, select group to push new stone with

            dp[i][j] = (dp[i - 1][j - 1] + (j * dp[i - 1][j])) % MOD;
        }
    }
    cout << dp[N][K];
}