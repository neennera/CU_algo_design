#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x, n, k;
ll cal(int n)
{
    if (n <= 0)
        return 1;

    if (n % 2 == 0)
    {
        // divide : X^(n/2) * X^(n/2)
        ll temp = cal(n / 2);
        return (temp * temp) % k;
    }
    else
    {
        // divide : (X) * X^(n-1)
        ll temp = cal(n - 1);
        return (temp * x) % k;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> n >> k;

    cout << cal(n);
}