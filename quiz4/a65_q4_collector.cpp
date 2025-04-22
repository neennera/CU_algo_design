#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
int buy[80];
vector<int> book[80];
bool use[1001];

int ans = INT_MAX;
bool ck[1001];
void f(int id, int price)
{
    if (id == K)
    {
        memset(ck, 0, sizeof(ck));
        for (size_t i = 0; i < K; i++)
        {
            if (!use[i])
                continue;
            for (auto b : book[i])
                ck[b] = 1;
            // cout << i << " ";
        }

        bool check = 1;
        for (int i = 1; i <= N; i++)
        {
            if (!ck[i])
            {
                // cout << "no " << i;
                check = 0;
                break;
            }
        }
        if (check)
        {
            ans = min(ans, price);
        }
        // cout << endl;
        return;
    }
    f(id + 1, price);
    use[id] = 1;
    f(id + 1, price + buy[id]);
    use[id] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (size_t i = 0; i < K; i++)
    {
        cin >> buy[i];
        int m;
        cin >> m;
        for (size_t j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            book[i].push_back(x);
        }
    }
    f(0, 0);
    cout << ans;
}