#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;

ll f(int n, int mx, int sum)
{
    if (sum > N)
        return 0;
    if (sum == N || n == N)
        return 1;
    int ct = 0;
    for (int i = mx; i <= N; i++)
    {
        ct += f(n + 1, i, sum + i);
    }
    return ct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << f(0, 1, 0);
}