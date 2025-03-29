#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, x, M;
vector<vector<int>> ibf(1001);
int bf[1001];
queue<int> q, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> M;
        for (size_t j = 0; j < M; j++)
        {
            cin >> x;
            bf[i]++;
            ibf[x].push_back(i);
        }
        if (bf[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        ans.push(x);
        for (auto v : ibf[x])
        {
            bf[v]--;
            if (bf[v] == 0)
                q.push(v);
        }
    }
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
}