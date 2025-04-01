#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, Q, x;
float R[500][500];
float dist[500][500];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;
    while (Q--)
    {
        cin >> N;
        memset(dist, 0, sizeof(dist));
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                cin >> dist[i][j];
            }
        }
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {

                for (size_t k = 0; k < N; k++)
                {
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
                }
            }
        }
        bool ck = 0;
        for (size_t i = 0; i < N; i++)
        {
            if (dist[i][i] > 1)
                ck = 1;
        }
        cout << (ck ? "YES" : "NO") << endl;
    }
}