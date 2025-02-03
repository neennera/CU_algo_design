#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, x;
ll cur = -2000, old_c = -2000;
list<ll> l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    l.push_back(0);
    while (N--)
    {
        cin >> x;
        if (cur + x >= x)
        {
            cur += x;
            l.pop_back();
        }
        else
        {
            cur = x;
        }
        l.push_back(cur);
    }
    l.sort();
    cout << ">> " << l.back() << endl;
    ll ans = l.back();
    l.pop_back();
    ans += l.back();
    cout << ans;
}
