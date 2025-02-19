#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, x, a[1001][1001], ans = INT_MIN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> x;
            if (i == 0 || j == 0)
            {
                a[i][j] = x;
            }
            else
            {
                a[i][j] = max(a[i - 1][j - 1] + x, x);
            }
            ans = max(ans, a[i][j]);
        }
    }
    cout << ans;
}