#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, M, x, u, v;
ll pf[1004], sum = 0; // prefix sum on clock wise from city 0 to city i (start index at 1 (company 0 to company 1)) , sum of all length
int company[1004];    // list of company that we will visit

ll path(int u, int v)
{
    // path to go from u -> v
    if (u > v)
        swap(u, v);
    // chose to go clockwise of anti-clockwise
    return min(pf[v] - pf[u], sum - (pf[v] - pf[u]));
}

ll solve(int st, int ed, int u, int v)
{
    ll ans = path(st, ed);                     // basecase
    ans = min(ans, path(st, u) + path(v, ed)); // portal u -> v
    ans = min(ans, path(st, v) + path(u, ed)); // portal v -> u
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> company[i];
    }
    company[N] = company[0]; // back to first company
    for (size_t i = 1; i <= N; i++)
    {
        cin >> x;
        sum += x;
        pf[i] = pf[i - 1] + x;
    }
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        // visit N company each day with portal option
        ll ans = 0;
        for (size_t j = 0; j < N; j++)
        {
            ans += solve(company[j], company[j + 1], u, v);
        }
        cout << ans << "\n";
    }
}