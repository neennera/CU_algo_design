#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n1, n2;
string s1, s2, ans = "";
int dp[1002][1002];

void f(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (s1[i - 1] == s2[j - 1])
    {
        ans = s1[i - 1] + ans;
        f(i - 1, j - 1);
        return;
    }
    if (dp[i - 1][j] >= dp[i][j - 1])
        f(i - 1, j);
    else
        f(i, j - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n1 >> n2;
    cin >> s1 >> s2;
    for (size_t i = 0; i <= n1; i++)
    {
        for (size_t j = 0; j <= n2; j++)
        {
            cin >> dp[i][j];
        }
    }
    f(n1, n2);
    cout << ans;
}
