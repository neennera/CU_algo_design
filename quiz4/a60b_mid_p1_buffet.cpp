#include <bits/stdc++.h>
using namespace std;
#define ll long long

int F, W, N;
vector<int> a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> F >> W >> N;
    a.resize(F);
    for (size_t i = 0; i < F; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int nw = 0, id = 0;
    int ans = 0;
    while (id < F)
    {
        ans++;
        nw = a[id] + (2 * W);
        id++;
        while (id < F && a[id] <= nw)
        {
            id++;
        }
    }
    cout << ans;
}