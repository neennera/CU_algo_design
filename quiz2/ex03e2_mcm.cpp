#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1e9; // Large value for initialization
int N;
int m[102]; // Store matrix dimensions
ll dp[102][102];

ll f(int i, int j)
{
    if (i == j)
        return 0; // No cost if there's only one matrix

    if (dp[i][j] != -1)
        return dp[i][j];

    ll ans = LLONG_MAX;
    for (int k = i; k < j; k++)
    {
        ll cost = f(i, k) + f(k + 1, j) + (ll)m[i - 1] * m[k] * m[j];
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i <= N; i++)
    {
        cin >> m[i]; // Read matrix dimensions
    }

    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1

    cout << f(1, N) << "\n"; // Compute minimum multiplications
}
