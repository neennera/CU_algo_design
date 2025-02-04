#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, x;
int cur[2] = {0, 0};
int ans[2] = {INT_MIN, INT_MIN};

// let index 0 is an answer that only use 1 MCS
// index 1 is an answer that has 2 MCS

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--)
    {
        cin >> x;
        cur[1] = max(cur[1] + x, ans[0] + x); // cur 1 is from cur_now, or MCS + x
        ans[1] = max(ans[1], cur[1]);
        cur[0] = max(cur[0] + x, x); // use like normal cur
        ans[0] = max(ans[0], cur[0]);
    }
    cout << max(ans[0], ans[1]);
}
