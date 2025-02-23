#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, W, K;
int l[200002], r[200002];
int dp[200002][2][51];
// bonus has K <= 50; so if K == N, we only use dp[200002][2]

int sol1()
{
    for (int i = 1; i <= N; i++)
    {
        if (i - W - 1 <= 0)
        {
            dp[i][0][0] = max(dp[i - 1][0][0], l[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], r[i]);
        }
        else
        {
            dp[i][0][0] = max(dp[i - 1][0][0], dp[i - W - 1][1][0] + l[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - W - 1][0][0] + r[i]);
        }
    }
    return max(dp[N][0][0], dp[N][1][0]);
}

int sol2()
{
    for (int i = 1; i <= N; i++)
    {

        for (int k = 1; k <= K; k++)
        {
            // you use k board from previous , or buy new board in range i-W-1
            dp[i][0][k] = max(dp[i - 1][0][k], dp[max(i - W - 1, 0)][1][k - 1] + l[i]);
            dp[i][1][k] = max(dp[i - 1][1][k], dp[max(i - W - 1, 0)][0][k - 1] + r[i]);
        }
    }
    int ans = 0;
    for (int k = 1; k <= K; k++)
    {
        ans = max({ans, dp[N][0][k], dp[N][1][k]});
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> W >> K;
    for (int i = 1; i <= N; i++)
        cin >> l[i];
    for (int i = 1; i <= N; i++)
        cin >> r[i];
    if (K == N)
        cout << sol1();
    else
        cout << sol2();
    // cout << endl;
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << dp[i][0][0] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << dp[i][1][0] << " ";
    // }
}