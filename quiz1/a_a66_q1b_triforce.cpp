#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int a[1 << 8][1 << 8];

bool checkZero(int i1, int j1, int i2, int j2)
{
    bool ck = 1;
    for (size_t i = i1; i <= i2; i++)
    {
        for (size_t j = j1; j <= j2; j++)
        {
            ck = ck && (a[i][j] == 0);
        }
    }
    return ck;
}

int findType(int a, int b, int c)
{
    if (a == 0 || b == 0 || c == 0)
        return 0;
    if (a == b)
        return a;
    if (b == c)
        return b;
    if (a == c)
        return a;
    return 0;
}

int tri(int i1, int j1, int i2, int j2)
{
    int h = i2 - i1 + 1;
    int w = j2 - j1 + 1;
    int mid_h = (i1 + i2) / 2;
    int mid_w = (j1 + j2) / 2;

    if (h <= 1 || w <= 1)
        return 0;
    if (h == 2 && w == 2)
    {
        if (a[i2][j2] != 0)
            return 0;
        if (a[i1][j1] == 0 || a[i2][j1] == 0 || a[i1][j2] == 0)
            return 0;
        return findType(a[i1][j1], a[i2][j1], a[i1][j2]);
    }
    // printf("%d %d %d %d\n", h, w, mid_h, mid_w);
    int ck1 = tri(i1, j1, mid_h, mid_w);
    int ck2 = tri(i1, mid_w + 1, mid_h, j2);
    int ck3 = tri(mid_h + 1, j1, i2, mid_w);
    bool ck4 = checkZero(mid_h + 1, mid_w + 1, i2, j2);

    return ck4 ? findType(ck1, ck2, ck3) : 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q = 3;
    while (Q--)
    {
        cin >> N;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                cin >> a[i][j];
            }
        }
        // cout << ">>>>>>>>>>> " << tri(0, 0, N - 1, N - 1) << endl;
        cout << tri(0, 0, N - 1, N - 1) << endl;
    }
}