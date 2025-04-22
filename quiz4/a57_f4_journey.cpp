#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int dist[22][22];
int dp[(1 << 21)][22];
vector<int> pre; // pruning : pre = best happy point it can get when it leave this node

// d, state, u : use tuple is more light weight than struct
// distance is more value than state !
priority_queue<tuple<int, int, int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    // pruning : the best possible happiness it can get visiting best path from each node
    int pre_cost = 0;

    for (int i = 1; i <= N; i++)
    {
        int best = INT_MIN;
        for (int j = 1; j <= N; j++)
        {
            cin >> dist[i][j];
            if (i != j)
                best = max(best, dist[i][j]);
        }
        pre_cost += best;

        for (int j = 0; j < (1 << N); j++)
        {
            dp[j][i] = -1e6; // not INT_MIN since it can underflow, not 0 cause path can be neg
        }
    }

    pq.push({1, 0, 1, 1});
    while (!pq.empty())
    {
        int last = get<0>(pq.top());
        int d = get<1>(pq.top());
        int state = get<2>(pq.top());
        int u = get<3>(pq.top());
        pq.pop();

        // N shouldn't be visit here
        if (u == N && state != (1 << N) - 1)
            continue;
        // cout << ">> " << u << " " << state << " " << d << "\n";
        if (dp[state][u] > d)
            continue;
        dp[state][u] = d;

        // pruning : if d in every best possible way afterthis still not more than ans_now -> stop it
        if (d + pre_cost <= dp[(1 << N) - 1][N])
            continue;

        for (int i = 2; i <= N; i++)
        {
            // already visit this city
            if (state & (1 << (i - 1)))
                continue;
            // check distance with new state
            int new_state = state | (1 << (i - 1));
            if (dp[new_state][i] >= d + dist[u][i])
                continue;
            pq.push({max(last, i), d + dist[u][i], new_state, i});
            dp[new_state][i] = d + dist[u][i];
        }
    }
    cout << dp[(1 << N) - 1][N];
}