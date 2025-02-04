#include <bits/stdc++.h>
using namespace std;

int N, K;
list<bool> ans;

void s(int n, int k)
{
    if (n == N)
    {
        if (k == 0)
        {
            for (auto x : ans)
            {
                cout << x;
            }
            cout << endl;
        }

        return;
    }
    ans.push_back(0);
    s(n + 1, k);
    ans.pop_back();
    if (k > 0)
    {
        ans.push_back(1);
        s(n + 1, k - 1);
        ans.pop_back();
    }
}

int main()
{
    cin >> K >> N;
    s(0, K);
}