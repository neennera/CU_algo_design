#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, M;
int a[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    while (M--)
    {
        int x;
        cin >> x;
        int l = 0, r = N - 1, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] <= x)
            {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}