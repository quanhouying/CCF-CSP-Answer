#include <iostream>
int main()
{
    using namespace std;
    int n, w, score;
    long long y = 0;    // 使用longlong防止溢出并初始化
    cin >> n;
    // 读入并处理每一组w和score
    for (int i = 0; i < n;i++)
    {
        cin >> w >> score;
        y += w * score;
    }
    if (y < 0)          // 实现ReLU函数
        y = 0;
    cout << y;

    return 0;
}