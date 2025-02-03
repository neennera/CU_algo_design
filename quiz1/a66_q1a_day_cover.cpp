#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, ans = 1001;
vector<int> stu[1001];
int ct[1001];
int stu_ct = 0, numday = 0;
void f(int last)
{
    if (numday == N)
    {
        ans = min(ans, stu_ct);
        return;
    }
    if (stu_ct >= ans || last >= M)
        return;
    for (size_t i = last; i < M; i++)
    {
        stu_ct++;
        for (auto x : stu[i])
        {
            if (!ct[x])
                numday++;
            ct[x]++;
        }

        f(i + 1);

        stu_ct--;
        for (auto x : stu[i])
        {
            ct[x]--;
            if (!ct[x])
                numday--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        for (size_t j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            stu[i].push_back(x);
        }
    }
    ans = M;
    f(0);
    cout << ans;
}