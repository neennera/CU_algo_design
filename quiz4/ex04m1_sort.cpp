#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
int a[100004];
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        m[x]++;
    }
    // a list "a", and a map "m" of number of each number
    int place = m[1]; // first place that wrong number 1 can be
    int ct = 0;       // wrong placement
    // Check 2 in 1 place ------------
    for (size_t i = 0; i < m[1]; i++)
    {
        // in this range [0, m[1]] should be only 1
        if (a[i] == 2)
        {
            ct++;
            // find number 1 that wrong placement
            while (place < N && a[place] != 1)
                place++;
            swap(a[i], a[place]);
        }
    }
    // Check 3 in 1 place ------------
    for (size_t i = 0; i < m[1]; i++)
    {
        // in this range [0, m[1]] should be only 1
        if (a[i] == 3)
        {
            ct++;
            // find number 1 that wrong placement
            while (place < N && a[place] != 1)
                place++;
            swap(a[i], a[place]);
        }
    }
    // After this 1 is sorted
    // Check 3 in 2 place ------------
    for (size_t i = m[1]; i < m[1] + m[2]; i++)
    {
        if (a[i] == 3)
            ct++;
    }
    cout << ct;
}