#include <bits/stdc++.h>
using namespace std;

int N;
double ww, x, ans = 0;
vector<double> a(100005);
priority_queue<tuple<double, double, double>> aw;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    // cin >> ww >> N;
    scanf("%lf %d", &ww, &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &x);
        a[i] = x;
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &x);
        double t = a[i] / (x * 1.0);
        aw.push({t, a[i], x});
    }
    if (ww == 0 || N == 0)
    {
        printf("0.0000\n");
        return 0;
    }
    while (ww > 0 && !aw.empty())
    {
        double ratio = get<0>(aw.top());
        double value = get<1>(aw.top());
        double weight = get<2>(aw.top());
        // cout << ratio << " " << value << " " << weight << endl;
        aw.pop();

        if (value <= 0)
            break;
        if (ww - weight >= 0)
        {
            ans += value;
            ww -= weight;
        }
        else
        {
            ans += ratio * ww;
            ww = 0;
        }
    }

    printf("%.4lf", ans);
}