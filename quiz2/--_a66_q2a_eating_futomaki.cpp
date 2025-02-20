#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int a[5005];
int dp[5003][5003];

int f(int i, int j)
{
    if (i >= j || i < 0 || j < 0 || i >= N || j >= N)
        return 0;
    if (dp[i][j])
        return dp[i][j];
    if (i + 1 == j)
    {
        dp[i][j] = max(a[i], a[j]);
        return dp[i][j];
    }

    // checking index out of bound
    dp[i][j] = max({max(a[i], a[j]) + f(i + 1, j - 1),
                    max(a[i], a[i + 1]) + f(i + 2, j),
                    max(a[j], a[j - 1]) + f(i, j - 2)});
    return dp[i][j];
    // dp[i][j] = max({max(a[i], a[j]) + dp[i - 1][j - 1], max(a[i], a[i + 1]) + dp[i + 2][j], max(a[j], a[j - 1]) + dp[i][j - 2]});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    f(0, N - 1);
    cout << dp[0][N - 1];
}