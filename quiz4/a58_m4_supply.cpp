#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, K;
vector<tuple<int, bool, int>> a;     // day , [plant,store], id
priority_queue<pair<int, int>> p, s; // day, id of plant and store

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    int d, e, l;
    for (size_t i = 0; i < K; i++)
    {

        cin >> d >> e >> l;
        a.push_back({d, e, l});
    }
    sort(a.begin(), a.end());
    for (size_t i = 0; i < K; i++)
    {
        d = get<0>(a[i]);
        e = get<1>(a[i]);
        l = get<2>(a[i]);
        if (!e)
        {
            if (s.empty())
            {
                // if no req, store in plant stock
                cout << 0 << "\n";
                p.push({-d, l});
            }
            else
            {
                // if there request, give earliest
                cout << s.top().second << "\n";
                s.pop();
            }
        }
        else
        {
            if (p.empty())
            {
                // if no plant, this store wait
                cout << 0 << "\n";
                s.push({-d, l});
            }
            else
            {
                // if there plant, give earliest
                cout << p.top().second << "\n";
                p.pop();
            }
        }
    }
}