#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, x, ans = 0;
int pf[1001][1001];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + (s[j - 1] == '1' ? 1 : 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            int K = min(i, j);
            for (int k = K; k > ans; k--)
            {
                int s = pf[i][j] - pf[i - k][j] - pf[i][j - k] + pf[i - k][j - k];
                if (s == k * k)
                {
                    ans = k;
                    break;
                }
            }
        }
    }
    cout << ans;
}