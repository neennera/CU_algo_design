#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, u, v, w;
int a[505][505];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(a, 0x3f, sizeof(a));
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        a[i][i] = 0;
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    for (size_t k = 0; k < N; k++)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    int ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (i == j || a[i][j] > 1e9)
                continue;
            ans = max(ans, a[i][j]);
        }
    }
    cout << ans;
}