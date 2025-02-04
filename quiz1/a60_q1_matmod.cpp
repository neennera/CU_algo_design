#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tiii tuple<int, int, int, int>

int N, K, A, B, C, D;
tiii mul(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2)
{
    return {
        a1 * a2 + b1 * c2,
        a1 * b2 + b1 * d2,
        c1 * a2 + d1 * c2,
        c1 * b2 + d1 * d2,
    };
}
tiii mod(int a, int b, int c, int d)
{
    return {a % K, b % K, c % K, d % K};
}

tiii matmod(int N)
{
    if (N == 1)
    {
        tiii x = mod(A, B, C, D);
        return x;
    }
    if (N % 2 == 0)
    {
        tiii a = matmod(N / 2);
        int a1, b1, c1, d1;
        tie(a1, b1, c1, d1) = a;
        tiii aa = mul(a1, b1, c1, d1, a1, b1, c1, d1);
        tie(a1, b1, c1, d1) = aa;
        tiii aaa = mod(a1, b1, c1, d1);
        return aaa;
    }
    else
    {
        tiii a = matmod(N - 1);
        int a1, b1, c1, d1;
        tie(a1, b1, c1, d1) = a;
        tiii aa = mul(a1, b1, c1, d1, A % K, B % K, C % K, D % K);
        tie(a1, b1, c1, d1) = aa;
        tiii aaa = mod(a1, b1, c1, d1);
        return aaa;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cin >> A >> B >> C >> D;
    tiii a = matmod(N);
    int a1, b1, c1, d1;
    tie(a1, b1, c1, d1) = a;
    cout << a1 << " " << b1 << " " << c1 << " " << d1;
}