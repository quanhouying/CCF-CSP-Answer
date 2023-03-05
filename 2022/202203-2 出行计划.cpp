#include <iostream>
int arr[200000] = {0};              // 存储每个时间点能够去的计划数
int main()
{
    using namespace std;
    int n, m, k;
    cin >> n >> m >> k;
// 对每个计划，算出能够去的最早时间(ti - ci - k + 1)和最晚时间(ti - k + 1)，然后利用前缀和处理一遍
    for (int i = 0; i < n;i++)
    {
        int t, c;
        cin >> t >> c;
        int l, r;
        l = ((t - c - k + 1) > 1) ? (t - c - k + 1) : 1;
        r = ((t - k + 1) > 1) ? (t - k + 1) : 1;
        arr[l]++;
        arr[r]--;
    }
// 处理前缀和
    for (int i = 1; i < 200000;i++)
        arr[i] += arr[i - 1];
    for (int i = 0; i < m;i++)
    {
        int t;
        cin >> t;
        cout << arr[t] << endl;
    }

    return 0;
}