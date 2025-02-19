#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int dp[46];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    for (size_t i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[N];
}