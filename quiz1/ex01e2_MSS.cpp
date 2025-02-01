#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, x;
ll cur = 0, maxx = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--)
    {
        cin >> x;
        cur = max(x, cur + x);
        maxx = max(maxx, cur);
    }
    cout << maxx;
}