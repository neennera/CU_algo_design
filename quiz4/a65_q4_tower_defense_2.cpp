#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DATA
{
    ll p, h;
    bool operator<(const DATA &o) const
    {
        return p < o.p;
    }
};

ll N, M, K, W, x, sum;
vector<DATA> mon;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K >> W;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x;
        mon.push_back({x, 0});
    }
    for (size_t i = 0; i < M; i++)
    {
        cin >> x;
        mon[i].h = x;
        sum += x;
    }

    sort(mon.begin(), mon.end());
    ll left = K, pos = 0;
    // printf("sum    m.p    m.h   dama   pos   posi  dam\n");
    for (size_t i = 0; i < M; i++)
    {
        ll room_left_to_place = (min(mon[i].p + W, N) - (max(0LL, mon[i].p - W))) + 1;
        if (pos >= max(0LL, mon[i].p - W))
            room_left_to_place = room_left_to_place - (pos - (max(0LL, mon[i].p - W)) + 1);
        room_left_to_place = max(0LL, room_left_to_place);
        ll damage = min({mon[i].h, room_left_to_place, left});                        // damage we can do to monster
        ll possible = min({max({pos, 0LL, mon[i].p - W}) + damage, mon[i].p + W, N}); // check border
        // cout << max({pos, 0, mon[i].p - W}) + damage << " " << mon[i].p + W << " " << N << "\n";
        // printf("%5d %5d %5d %5d %5d %5d %5d\n", sum, mon[i].p, mon[i].h, damage, pos, possible, damage);
        sum -= damage;
        left -= damage;
        pos = possible;
        if (left <= 0 || pos >= N || sum <= 0)
            break;
    }
    cout << sum;
}