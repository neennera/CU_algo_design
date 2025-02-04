#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, M, x;
vector<int> A;
map<int, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        A.push_back(x);
        m[x] = i;
    }
    while (M--)
    {
        vector<int> AA(A);
        int k, id = 0, ct = 0;
        cin >> k;
        while (A[id] != k)
        {
            if (A[id] > k)
                ct++;
            id++;
        }
        cout << ct << endl;
    }
}