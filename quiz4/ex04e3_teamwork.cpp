#include <bits/stdc++.h>
using namespace std;

int N, M;
double ans;
int a[100005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> a[i];
    }
    // we will select short job to be done first -> gain more quick finish bonus
    sort(a, a + M);
    // sum = each student finish task time
    // ans = all time all task done
    double sum = 0, ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        sum = 0;
        // disstribute task by seperate shortest task to each one
        // so it will start at i then jump N
        for (size_t j = i; j < M; j += N)
        {
            sum += a[j];
            ans += sum; // record time to finish this task
        }
    }
    printf("%.3f", ans / double(M));
}