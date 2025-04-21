#include <bits/stdc++.h>
using namespace std;

int N, ct = 0;
bool col[13], diag1[25], diag2[25];

bool check_diagonal(int r, int c)
{
    return !col[c] && !diag1[r - c + N] && !diag2[r + c];
}
// diag1 = main diagonal calculate by r-c+N (prevent negative) it has 2*N (24) possible number
// diag2 = anti-diagonal calculate by r+c

void f(int row)
{
    if (row > N)
    {
        ct++;
        return;
    }

    for (int c = 1; c <= N; c++)
    {
        if (check_diagonal(row, c))
        {
            col[c] = diag1[row - c + N] = diag2[row + c] = true;
            f(row + 1);
            col[c] = diag1[row - c + N] = diag2[row + c] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    f(1);
    cout << ct << endl;
    return 0;
}