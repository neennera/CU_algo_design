#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, M, x, y;
int A, B, C, D;
vector<int> ansMe(4);

ll f(int n, ll i, ll j)
{
    if (n == 1)
    {
        int id = (2 * i) + j;
        return ansMe[id];
    }
    ll mid = (1LL << (n - 1));
    bool up = (i < mid);
    bool left = (j < mid);
    if (up && left)
        return f(n - 1, i, j);
    if (up && !left)
        return f(n - 1, j - mid, i);
    if (!up && left)
        return -f(n - 1, i - mid, j);
    return -f(n - 1, j - mid, i - mid);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> A >> B >> C >> D;
    ansMe = {A, B, C, D};

    while (M--)
    {
        cin >> y >> x;
        y = y - 1LL;
        x = x - 1LL;
        cout << f(N, y, x) << endl;
    }
}