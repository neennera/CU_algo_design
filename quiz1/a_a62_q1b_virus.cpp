#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
bool check(string s)
{
    if (s.length() == 0)
        return false;
    if (s.length() == 2)
    {
        return s == "01";
    }
    int mid = s.length() >> 1;
    string s1 = s.substr(0, mid);
    string s2 = s.substr(mid, s.length());
    string s1bf = s1;
    bool s1b = check(s1);
    reverse(s1.begin(), s1.end());
    bool s1rb = check(s1);
    bool s2b = check(s2);

    // cout << s << " : " << s1bf << "()" << s1 << " + " << s2 << "x" << endl;
    return ((s1b || s1rb) && s2b);
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

        if (K == 1)
        {
            cout << (s == "01" ? "yes\n" : "no\n");
        }
        else
        {
            // cout << s << " : ";
            cout << (check(s) ? "yes\n" : "no\n");
        }
    }
}