#include <bits/stdc++.h>
using namespace std;
#define ll long long

int A, B;
int me[1 << 8][1 << 8];

void f(int a, int b, int i1, int j1, int i2, int j2)
{
    if (a == 0)
    {
        me[i1][j1] = b;
        return;
    }
    int mid_i = (i1 + i2) >> 1;
    int mid_j = (j1 + j2) >> 1;
    f(a - 1, b, i1, j1, mid_i, mid_j);
    f(a - 1, b - 1, i1, mid_j + 1, mid_i, j2);
    f(a - 1, b + 1, mid_i + 1, j1, i2, mid_j);
    f(a - 1, b, mid_i + 1, mid_j + 1, i2, j2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    f(A, B, 0, 0, (1 << A) - 1, (1 << A) - 1);
    for (size_t i = 0; i < (1 << A); i++)
    {
        for (size_t j = 0; j < (1 << A); j++)
        {
            cout << me[i][j] << " ";
        }
        cout << endl;
    }
}