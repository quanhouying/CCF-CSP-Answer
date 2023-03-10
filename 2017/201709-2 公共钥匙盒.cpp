#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
struct y{
    int t;              // 时间（取或还）
    int id;             // 钥匙号
};
bool cmp(y a,y b)       // 先按时间升序排，时间一样，按钥匙号升序排
{
    if (a.t != b.t)
        return a.t < b.t;
    else
        return a.id < b.id;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);   //提高cin,cout的速度
    int N, K;
    int w, s, c;
    cin >> N >> K;
    for (int i = 0; i <= N;i++)     // 钥匙盒初始化
        arr[i] = i;
    y l[K], r[K];                   // 取钥匙，还钥匙
    for (int i = 0; i < K;i++)
    {
        cin >> w >> s >> c;
        l[i].id = r[i].id = w;      // 要操作的钥匙号
        l[i].t = s;                 // 取钥匙时间
        r[i].t = c + s;             // 还钥匙时间
    }
    sort(l, l + K, cmp);
    sort(r, r + K, cmp);
    int j = 0;
    for (int i = 0; i < K;i++)
    {
        while (r[j].t <= l[i].t)    // 取钥匙前先还钥匙
            for (int i = 1; i <= N;i++)
                if (arr[i] == 0)
                {
                    arr[i] = r[j].id;
                    j++;
                    break;
                }
        for (int j = 1; j <= N;j++) // 取钥匙
            if (arr[j] == l[i].id)
            {
                arr[j] = 0;
                break;
            }
    }
    while (j < K)                   // 还完剩余钥匙
        for (int i = 1; i <= N;i++)
            if (arr[i] == 0)
            {
                arr[i] = r[j].id;
                j++;
                break;
            }
    for (int i = 1; i <= N;i++)     // 输出结果
        cout << arr[i] << ' ';

        return 0;
}