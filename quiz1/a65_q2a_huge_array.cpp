#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, Q, x, c, old_id = 0;
vector<pair<int, int>> a;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> c;
        a.push_back(make_pair(x, c));
    }
    sort(a.begin(), a.end());
    for (size_t i = 0; i < N; i++)
    {
        int x = a[i].first;
        int c = a[i].second;
        v.push_back(make_pair(old_id + c, x));
        old_id += c;
    }
    while (Q--)
    {
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), make_pair(x, -1));
        cout << it->second << endl;
    }
}