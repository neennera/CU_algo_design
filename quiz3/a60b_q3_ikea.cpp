#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, M, Q, a, b;
vector<vector<int>> topo(1001);
int ct[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> a >> b;
        topo[a].push_back(b);
        ct[b]++;
    }
    for (size_t q = 0; q < 5; q++)
    {
        int ctt[N + 1];
        for (size_t i = 1; i <= N; i++)
        {
            ctt[i] = ct[i];
        }

        bool ck = 1;
        for (size_t i = 0; i < N; i++)
        {
            cin >> a;
            if (!ck)
                continue;
            if (ctt[a] > 0)
            {
                ck = 0;
                continue;
            }
            for (auto b : topo[a])
                ctt[b]--;
        }
        cout << (ck ? "SUCCESS" : "FAIL") << endl;
    }
}