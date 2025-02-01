#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;

int count1(string s)
{
    int ct = 0;
    for (auto x : s)
    {
        ct += x == '1';
    }
    return ct;
}

pair<bool, int> check(string s)
{
    if (s.length() == 2)
    {
        return {s == "01" || s == "00" || s == "10" || s == "11", count1(s)};
    }
    int mid = s.length() >> 1;
    string s1 = s.substr(0, mid);
    string s2 = s.substr(mid, s.length());
    pair<bool, int> t = check(s1);
    bool ck1 = t.first;
    int ct1 = t.second;
    t = check(s2);
    bool ck2 = t.first;
    int ct2 = t.second;
    return {ck1 && ck2 && abs(ct1 - ct2) <= 1, ct1 + ct2};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        string s = "";
        for (size_t j = 0; j < (1 << K); j++)
        {
            char c;
            cin >> c;
            s += c;
        }
        bool ans = check(s).first;
        cout
            << (ans ? "yes\n" : "no\n");
    }
}