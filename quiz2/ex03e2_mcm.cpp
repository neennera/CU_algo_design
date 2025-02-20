#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int m[102][2];
ll dp[102][102][2];
ll f(int i, int j, int c)
{
    if (dp[i][j][c])
        return dp[i][j][c];
    if (i == j)
    {
        return dp[i][j][c] = m[i][c];
    }
    ll ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, f(i, k, 0) + f(k + 1, j, 1));
    }
    return dp[i][j][c] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c;
    cin >> N;
    cin >> r >> c;
    m[1][1] = r;
    m[1][0] = c;
    for (int i = 2; i <= N; i++)
    {
        r = c;
        cin >> c;
        m[i][1] = r;
        m[i][0] = c;
    }
    cout << f(1, N, 0);
}
