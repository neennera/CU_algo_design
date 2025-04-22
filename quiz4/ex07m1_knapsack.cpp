#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DATA
{
    double v, w, ratio;
    bool operator<(const DATA &o) const
    {
        return ratio > o.ratio;
    }
};

double W, ans = 0;
int N;
vector<DATA> a;

// predict best option to get if we select only best ratio item since index id to has cap full
// predict use O(N) each time
double predict(int id, double cap)
{
    double pd = 0;
    while (id < N && cap > 0)
    {
        double ww = min(cap, a[id].w);
        double vv = (ww == a[id].w ? a[id].v : (a[id].ratio * ww));
        cap -= ww;
        pd += vv;
        id++;
    }
    return pd;
}

void search(int id, double cap, double price)
{
    // basecase
    if (id == N || cap == 0)
    {
        ans = max(ans, price);
        return;
    }

    // prunning
    // check the best sceenario we can get in O(N)
    // use this it will better that just use prefix_sum_left[id] (which can cause more upper_bound)
    double pd = predict(id, cap);
    if (price + pd + 1 <= ans)
        return;

    double ww = a[id].w; // we can only take it all
    if (cap >= ww)
        search(id + 1, cap - ww, price + a[id].v); // use i
    search(id + 1, cap, price);                    // not use i
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> W >> N;
    a.resize(N);
    for (size_t i = 0; i < N; i++)
        cin >> a[i].v;
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i].w;
        a[i].ratio = a[i].v / a[i].w;
    }
    sort(a.begin(), a.end());
    search(0, W, 0);
    printf("%.4f", ans + 1e-6);
}
