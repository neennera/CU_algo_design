#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
const int N = 4e5 + 9;
const int shift = 2e5;
const int K = 51;
int c[N][2];
int dp1[N][2];
int dp2[N][K][2];
int n, w, KK;
int ans = 0;
void solve1()
{
    /// case k = n
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            dp1[i + shift][j] = max(dp1[i + shift - 1][j], dp1[i + shift - w - 1][j ^ 1] + c[i + shift][j]);
        }
    }
    ans = max(dp1[n + shift][0], dp1[n + shift][1]);
}
void solve2()
{
    /// case k
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= KK; k++)
        {
            for (int j = 0; j <= 1; j++)
            {
                dp2[i + shift][k][j] = max(dp2[i + shift - 1][k][j], dp2[i + shift - 1 - w][k - 1][j ^ 1] + c[i + shift][j]);
            }
        }
    }
    for (int i = 1; i <= KK; i++)
    {
        for (int j = 0; j < 2; j++)
            ans = max(ans, dp2[n + shift][i][j]);
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> w >> KK;
    for (int i = 1; i <= n; i++)
        cin >> c[i + shift][0];
    for (int i = 1; i <= n; i++)
        cin >> c[i + shift][1];
    if (KK == n)
        solve1();
    else
        solve2();
    cout << ans << '\n';
    return 0;
}
