#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s1, s2;
bool f(string s1, string s2)
{
    int l = s1.length();
    if (l == 0 || (l == 1 && s1 != s2))
        return false;
    if (s1 == s2)
        return true;
    int mid = l >> 1;
    // string a1 = s1.substr(0, mid);
    // string a2 = s1.substr(0, mid);
    return (f(s1.substr(0, mid), s2.substr(0, mid)) && f(s1.substr(mid, l), s2.substr(mid, l))) ||
           (f(s1.substr(0, mid), s2.substr(mid, l)) && f(s1.substr(mid, l), s2.substr(0, mid)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    cout << (f(s1, s2) ? "YES" : "NO");
}