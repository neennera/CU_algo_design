#include <bits/stdc++.h>
using namespace std;
#define ll long long

char f(ll l, ll r, ll id, ll k)
{

    ll length = r - l + 1;
    if (k == 0)
    {
        return id == 0 ? 'g' : 'a';
    }
    ll cut = (length - (k + 3)) >> 1;
    // cout << l << " " << r << " " << id << " " << k << " : " << cut << endl;
    if (id < cut || id >= cut + k + 3)
        return f(0, cut - 1, id < cut ? id : id - cut - k - 3, k - 1);
    return id - cut == 0 ? 'g' : 'a';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x, k = 0, l = 3;
    cin >> x;

    while (l < x)
    {
        k++;
        l = (2 * l) + k + 3;
    }
    // cout << l << " " << x << " " << k << "\n";
    cout << f(0, l - 1, x - 1, k);
}