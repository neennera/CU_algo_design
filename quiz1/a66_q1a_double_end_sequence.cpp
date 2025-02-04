#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, x;
ll pf[300003], ans = LLONG_MIN;
ll a[300003];
map<int, int> m; // number and best start index
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    for (size_t i = 1; i <= N; i++)
    {
        int x = a[i];
        int st = m[x];
        ans = max(max(ans, a[i]), pf[i] - pf[st]);
        if (pf[i] < pf[st] || st == 0)
        {
            m[x] = i - 1;
        }
    }
    cout << ans;
}