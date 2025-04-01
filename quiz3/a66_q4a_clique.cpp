#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, ans = 0;
int b[51], a[51][51], qs[52];
vector<int> use;
void f(int id, int ct)
{
    if (id > N)
    {
        ans = max(ans, ct);
        return;
    }
    if (ct + qs[id] <= ans)
        return;
    bool ck = 1;
    for (auto x : use)
    {
        if (!a[id][x])
        {
            ck = 0;
            break;
        }
    }
    if (ck)
    {
        use.push_back(id);
        f(id + 1, ct + b[id]);
        use.pop_back();
    }
    f(id + 1, ct);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> b[i];
    }
    for (int i = N; i >= 1; i--)
        qs[i] = qs[i + 1] + b[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> a[i][j];
        }
    }
    f(1, 0);
    cout << ans;
}
