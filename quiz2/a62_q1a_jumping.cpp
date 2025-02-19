#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, x;
int a[1000006];
int dp[1000006];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if (i > 3)
        {
            dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3])) + a[i];
        }
        else if (i == 3)
        {
            dp[i] = max(dp[i - 1], dp[i - 2]) + a[i];
        }
        else if (i == 2)
        {
            dp[i] = dp[i - 1] + a[i];
        }
        else
        {
            dp[i] = a[i];
        }
    }
    cout << dp[N];
}