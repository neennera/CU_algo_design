#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K, M, w, st, ed;
ll pf[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> w;
        pf[i] = pf[i - 1] + w - M;
    }
    while (K--)
    {
        cin >> st >> w;
        ed = lower_bound(pf, pf + N, w + pf[st - 1]) - pf;
        cout << ed << "\n";
    }
}