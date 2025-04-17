#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, L;
vector<int> a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    a.resize(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int nw = 0, id = 0;
    int ans = 0;
    while (id < N)
    {
        ans++;
        nw = a[id] + L - 1;
        id++;
        while (id < N && a[id] <= nw)
        {
            id++;
        }
    }
    cout << ans;
}