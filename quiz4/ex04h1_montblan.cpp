#include <bits/stdc++.h>
using namespace std;

int N, D, x, l = 0, r, mid, d, submit, rec;
int a[100005];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> D;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> x;
        a[i] = x;
        l = max(l, a[i] - a[i - 1]); // assure you can climb at least 1 step per day
    }
    r = x + 1;
    int ans_d = 0;
    while (l < r)
    {
        mid = (l + r) >> 1;
        d = 0;
        rec = 0;
        for (int i = 1; i <= N; i++)
        {
            // we can climb up this step to next one
            if (i != N && rec + mid >= a[i + 1])
                continue;
            rec = a[i]; // find place to spend the night
            d++;
        }
        if (d > D)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
            ans_d = max(ans_d, d);
            // if (d > ans_d)
            // {
            //     ans = mid;
            //     ans_d = d;
            // }
        }
    }
    cout << r << " " << ans_d;
}