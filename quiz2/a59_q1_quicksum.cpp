#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K, x;
int pf[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            cin >> x;
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + x;
        }
    }
    while (K--)
    {
        int i1, i2, j1, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1++, i2++, j1++, j2++;
        cout << pf[i2][j2] - pf[i1 - 1][j2] - pf[i2][j1 - 1] + pf[i1 - 1][j1 - 1] << endl;
    }
}