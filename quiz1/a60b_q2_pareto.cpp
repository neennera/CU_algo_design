#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;

pair<int, int> p[100002];
pair<int, int> pareto(int l, int r, int minx)
{
    if (l == r)
    {
        if (p[l].second > minx)
            return {1, p[l].second};
        else
            return {0, minx};
    }
    int mid = (l + r) / 2;
    auto r1 = pareto(mid + 1, r, minx);
    auto r2 = pareto(l, mid, r1.second);
    return {r1.first + r2.first, r2.second};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + N);
    pair<int, int> ans = pareto(0, N - 1, INT_MIN);
    cout << ans.first;
}