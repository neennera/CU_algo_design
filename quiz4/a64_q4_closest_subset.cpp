#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K, ans, ans_diff = INT_MAX;
bool use[101];
int a[101], pf_back[101];
vector<pair<int, int>> b, w; // best and worst <value, id>
                             // worst will order by less to more
                             // best will order by more to less
void f(int id, int n, int now)
{

    if (n == M)
    {
        if (abs(now - K) < ans_diff)
        {
            ans_diff = abs(now - K);
            ans = now;
        }
        return;
    }
    if (id >= N)
        return;

    if (id + (M - n) > N)
        return;

    // if (now + pf_back[id] < K && (K - now - pf_back[id]) >= ans_diff)
    //     return;

    int best = 0, worst = 0, nb = M - n, idb = 0, nw = M - n, idw = 0;
    while (idb < N && nb)
    {
        if (b[idb].second < id)
        {
            idb++;
            continue;
        }
        best += b[idb].first;
        nb--;
        idb++;
    }
    while (idw < N && nw)
    {
        if (w[idw].second < id)
        {
            idw++;
            continue;
        }
        worst += w[idw].first;
        nw--;
        idw++;
    }
    // printf("id : %3d, now : %5d, worst : %5d, best : %5d\n", id, now, worst, best);
    // best = choose the most possible in left over
    if (now + best < K && K - now - best >= ans_diff)
        return;
    // worst = choose the worst possible in left over
    if (now + worst > K && now + worst - K >= ans_diff)
        return;

    f(id + 1, n + 1, now + a[id]);
    f(id + 1, n, now);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    ans_diff = K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
        b.push_back({a[i], i});
        w.push_back({a[i], i});
    }
    sort(w.begin(), w.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    pf_back[N - 1] = a[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        pf_back[i] = pf_back[i + 1] + a[i];
    }

    f(0, 0, 0);
    cout << ans_diff;
}