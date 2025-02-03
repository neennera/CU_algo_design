#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K, W;
int tower[1000005];
int mons_pos[1000005];
pair<int, int> mons[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K >> W;
    for (size_t i = 0; i < M; i++)
    {
        cin >> mons_pos[i];
    }
    for (size_t i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        mons[i] = {mons_pos[i], x};
    }
    for (size_t i = 0; i < K; i++)
    {
        cin >> tower[i];
    }
    sort(mons, mons + M);
    sort(tower, tower + K);
    int i = 0, j = 0;
    while (i < K && j < M)
    {
        if (mons[j].second == 0)
            continue;
        if (tower[i] + W < mons[j].first)
        {
            i++;
            continue;
        }
        if (tower[i] - W > mons[j].first)
        {
            j++;
            continue;
        }
        // cout << tower[i] << " " << mons[j].first << endl;
        mons[j].second--;
        i++;
        while (mons[j].second == 0 && j < M)
        {
            j++;
        }
    }
    int ans = 0;
    for (int j = 0; j < M; j++)
    {
        ans += mons[j].second;
    }
    cout << ans;
}