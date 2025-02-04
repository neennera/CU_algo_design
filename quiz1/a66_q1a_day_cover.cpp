#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, ans;
vector<int> stu[1002];
int ct[1001];
int stu_ct = 0, numday = 0;
void f(int a, int last, int b = 0)
{
    if (numday == N)
    {
        ans = min(ans, stu_ct);
    }
    if (stu_ct >= ans || numday >= N)
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

        f(stu_ct, i + 1, numday);

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
    f(0, 0);
    cout << ans;
}