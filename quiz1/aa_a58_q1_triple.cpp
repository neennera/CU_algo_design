#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
ll a[602];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    while (M--)
    {
        ll q;
        bool ans = false;
        cin >> q;
        for (int i = 0; i < N; i++)
        {
            ll X = q - a[i];
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                if (a[l] + a[r] == X)
                {
                    ans = true;
                    break;
                }
                if (a[l] + a[r] > X)
                    r--;
                else
                    l++;
            }
            if (ans)
                break;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}