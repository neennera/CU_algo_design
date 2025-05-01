#include <bits/stdc++.h>
using namespace std;

int N, M, state = 0, end_state = 0;
bool vis[22][(1 << 19)];
vector<int> ans;
vector<int> path[19];

void f(int state, int ept)
{

    if (state == end_state && ept == 2 * N)
    {
        cout << ans.size() << "\n";
        for (auto x : ans)
        {
            cout << x + 1 << " ";
        }
        exit(0);
    }
    vis[ept][state] = 1;
    for (auto v : path[ept])
    {
        int new_state = state;
        // if v is 1 -> we'll xor bit to swap (0,1)
        // if v is 0 -> no need to swap (empty room is 0)
        if ((new_state >> v) & 1)
            new_state = (new_state) ^ ((1 << v) + (1 << ept));
        if (vis[v][new_state])
            continue;
        ans.push_back(v);
        f(new_state, v);
        ans.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        u--, v--;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    for (int i = 0; i < N; i++)
        state += (1 << i);
    for (int i = N; i < (2 * N); i++)
        end_state += (1 << i);
    f(state, (2 * N));
    cout << -1;
}