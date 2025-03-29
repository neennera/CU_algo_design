#include <bits/stdc++.h>
using namespace std;

int N, M, K, u, v, ct, ans = 0, i, j, ans_ct = 0;
bool vis[1001][1001];
int m[1001][1001];
int dist[1001][1001];
// walk row and column, 2 ways
pair<pair<int, int>, pair<int, int>> walk[7] = {
    {{0, 0}, {0, 0}},
    {{0, -1}, {0, 1}},
    {{-1, 0}, {1, 0}},
    {{-1, 0}, {0, 1}},
    {{1, 0}, {0, 1}},
    {{1, 0}, {0, -1}},
    {{-1, 0}, {0, -1}},
};

bool ck(int x, int y, int nx, int ny, bool met)
{
    if (nx < 1 || ny < 1 || ny > N || nx > M)
        return false;
    int now = m[y][x];
    int go = m[ny][nx];

    if (met == 0)
    {
        if ((now == 1 && (go == 3 || go == 4 || go == 1)) || (now == 2 && (go == 2 || go == 4 || go == 5)) ||
            (now == 3 && (go == 2 || go == 4 || go == 5)) || (now == 4 && (go == 2 || go == 3 || go == 6)) ||
            (now == 5 && (go == 2 || go == 3 || go == 6)) || (now == 6 && (go == 2 || go == 4 || go == 5)))
            return true;
        return false;
    }
    if ((now == 1 && (go == 1 || go == 5 || go == 6)) || (now == 2 && (go == 2 || go == 3 || go == 6)) ||
        (now == 3 && (go == 1 || go == 5 || go == 6)) || (now == 4 && (go == 1 || go == 5 || go == 6)) ||
        (now == 5 && (go == 1 || go == 3 || go == 4)) || (now == 6 && (go == 1 || go == 3 || go == 4)))
        return true;
    return false;
}
int pi, pj;
void solve(int si, int sj)
{
    stack<tuple<int, int, int, int, int>> q; // i,j, ct, pi, pj
    q.push({si, sj, 0, -1, -1});
    while (!q.empty())
    {
        tuple<int, int, int, int, int> tmp = q.top();
        q.pop();
        i = get<0>(tmp);
        j = get<1>(tmp);
        ct = get<2>(tmp);
        pi = get<3>(tmp);
        pj = get<4>(tmp);

        if (vis[i][j])
        {
            printf("%d %d , %d %d\n", i, j, pi, pj);
            ans = max(ans, ct - dist[i][j]);
            ans_ct++;
            continue;
        }
        dist[i][j] = ct;
        vis[i][j] = 1;
        pair<pair<int, int>, pair<int, int>> ww = walk[m[i][j]];

        int nx, ny;
        ny = i + ww.first.first;
        nx = j + ww.first.second;
        if ((nx != pj && ny != pi) && ck(j, i, nx, ny, 0))
        {
            q.push({ny, nx, ct + 1, i, j});
        }
        ny = i + ww.second.first;
        nx = j + ww.second.second;
        if ((nx != pj && ny != pi) && ck(j, i, nx, ny, 1))
        {
            q.push({ny, nx, ct + 1, i, j});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            cin >> m[i][j];
        }
    }
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            if (!vis[i][j])
                solve(i, j);
        }
    }
    cout << ans_ct << " " << ans;
}
