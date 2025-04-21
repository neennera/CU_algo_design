#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, ans = INT_MAX;
vector<vector<int>> path;
int color[55]; // defalte color = 0;

int check(int u, int c)
{
    for (auto v : path[u])
    {
        if (color[v] == c)
            return false;
    }
    return true;
}

void f(int u)
{
    // cout << u << "\n";
    // if we can assign all color to all node
    if (u == N)
    {
        int tmp = 0;
        for (size_t i = 0; i < N; i++)
        {
            tmp = max(tmp, color[i]);
        }
        ans = min(ans, tmp);
        return;
    }
    // we'll find color for node u with least color number possible
    for (size_t i = 1; i <= N; i++)
    {
        // this color has more number than ans
        if (i > ans)
            break;
        color[u] = i;
        // check if we can assign
        // if we can, please comeback to try more color too
        if (!check(u, i))
            continue;
        f(u + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    path.resize(N);
    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    f(0);
    cout << ans;
}