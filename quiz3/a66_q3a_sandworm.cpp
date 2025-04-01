#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int r, c, w;
    bool operator<(const DATA &d2) const
    {
        return w > d2.w;
    }
};

int N, M, K, t;
int ctt = 0, ctd = 0;
bool a[701][701][2];
bool vis[701][701][2];
bool worm[701][701];
int yy[4] = {-1, 0, 0, 1};
int xx[4] = {0, -1, 1, 0};
vector<pair<pair<int, int>, int>> m; // area that worm is get in bottom
int k[100001];

void f(int y, int x, int flr, int id)
{
    if (vis[y][x][flr])
        return;
    vis[y][x][flr] = 1;
    if (flr == 0 && worm[y][x] && !a[y][x][1])
    {
        int idd = 0;
        // send id of worm to them
        for (size_t j = 0; j < K; j++)
        {
            if (m[j].first.first == y && m[j].first.second == x)
            {
                idd = j;
                break;
            }
        }
        f(y, x, 1, idd);
    }
    if (flr == 1)
        k[id]++;
    else
        ctt++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + yy[i];
        int nx = x + xx[i];
        if (ny < 1 || nx < 1 || ny > N || nx > M)
            continue;
        if (!vis[ny][nx][flr] && !a[ny][nx][flr])
            f(ny, nx, flr, id);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> a[i][j][0];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> a[i][j][1];
        }
    }
    int tx, ty;
    for (size_t i = 0; i < K; i++)
    {
        cin >> ty >> tx;
        m.push_back({{ty, tx}, i});
        worm[ty][tx] = 1;
    }
    f(1, 1, 0, -1);

    for (size_t i = 0; i < K; i++)
    {
        ctd = max(ctd, k[i]);
    }

    cout << ctt + ctd;
}
