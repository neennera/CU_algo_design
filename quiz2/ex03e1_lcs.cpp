#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s1, s2;
int dp[505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            // normal case, get last maximum longest {s1 - 1, s1} or {s1, s2 -1}
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            // if character match, see {s1 - 1, s2 - 1}
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }
    cout << dp[s1.length()][s2.length()];
}