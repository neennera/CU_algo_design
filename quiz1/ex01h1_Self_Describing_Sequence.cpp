#include <bits/stdc++.h>
using namespace std;
#define ll long long

int M;
ll x;
map<ll, int> m; // last index : num_in_that_index

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Step 1: Initialize sequence
    m[1] = 1;
    m[3] = 2;
    ll old = 3;

    for (int i = 3; old < 2e9; i++) // Increased limit for safety
    {
        ll width = m.lower_bound(i)->second;
        old += width;
        m[old] = i;
        // cout << i << " " << old << endl;
    }

    // auto it = m.begin();
    // while (it != m.end())
    // {
    //     cout << it->first << " " << it->second << endl;
    //     it++;
    // }

    cin >> M;
    while (M--)
    {
        cin >> x;
        cout << m.lower_bound(x)->second << endl;
    }
}
