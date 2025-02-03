#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
int bf[20];
set<int> s[20];
bool used[20];
list<int> a;
void recur(int l)
{
    if (l == N)
    {
        for (auto x : a)
        {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (used[i])
            continue;
        if (bf[i] != 0)
            continue;
        used[i] = 1;
        a.push_back(i);
        for (auto x : s[i])
        {
            bf[x]--;
        }
        recur(l + 1);
        for (auto x : s[i])
        {
            bf[x]++;
        }
        used[i] = 0;
        a.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int a, b;
    for (size_t i = 0; i < K; i++)
    {
        cin >> a >> b;
        bf[b]++;
        s[a].insert(b);
    }
    recur(0);
}