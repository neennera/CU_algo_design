#include <bits/stdc++.h>
using namespace std;

int ct[5005], N, c, mx = 0;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> c;
            if (i >= j || !c)
                continue;
            ct[i]++;
            ct[j]++;
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        m[ct[i]]++;
        mx = max(mx, ct[i]);
    }
    for (int i = 0; i <= mx; i++)
    {
        cout << m[i] << " ";
    }
}