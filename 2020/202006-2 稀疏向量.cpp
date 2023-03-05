#include <iostream>

int main()
{
    using namespace std;
    int n, a, b, x = 0;
    long long ans = 0;
    cin >> n >> a >> b;
    int u[500000][2];               // 第一个稀疏向量的非零值
    for (int i = 0; i < a;i++)
    {
        cin >> u[i][0] >> u[i][1];
    }
    for (int i = 0; i < b;i++)      // 读取并处理第二个稀疏向量
    {
        int ind, val;
        cin >> ind >> val;
        while (ind > u[x][0] && x < a)
            x++;
        if (ind == u[x][0])
            ans += val * u[x][1];
    }
    cout << ans;

    return 0;
}