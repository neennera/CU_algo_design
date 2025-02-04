#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, a, b, x;
vector<ll> ans;
map<ll, ll> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--)
    {
        cin >> a >> b;
        m[a]++;
        m[b + 1]--;
    }
    int ct = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (ct == 0 && it->second > 0)
        {
            ans.push_back(it->first);
        }
        else if (ct > 0 && ct + it->second == 0)
        {
            ans.push_back((it->first) - 1);
        }
        ct += it->second;
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
}