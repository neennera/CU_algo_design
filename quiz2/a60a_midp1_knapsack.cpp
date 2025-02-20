#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M;
int v[505], w[505];
int dp[505][505];
stack<int> q;

void f(int i, int j)
{

    if (i == 0 || j == 0)
        return;
    int k = i - 1; // focus on item index k
    // if it select move to i-1, i-w[k]
    if (j >= w[k] && dp[i - 1][j - w[k]] + v[k] == dp[i][j])
    {
        f(i - 1, j - w[k]);
        q.push(k + 1);
        return;
    }

    // If no item was selected, move to previous row
    f(i - 1, j);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        cin >> v[i];
    for (int i = 0; i < M; i++)
        cin >> w[i];
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cin >> dp[i][j];
        }
    }
    f(M, N);
    cout << q.size() << endl;
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
}