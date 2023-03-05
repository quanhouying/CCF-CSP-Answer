#include <iostream>
#include <cmath>
double a[1000];        //存储a的值
int main()
{
    using namespace std;
    int n;
    double av, ad = 0, all = 0;
    cin >> n;
// 读入n和各个a的值
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        all += a[i];    // 累加a,方便算平均值
    }
// 计算a的平均值和D(a)
    av = all / n;
    for (int i = 0; i < n;i++)
        ad += (av - a[i]) * (av - a[i]) / n;
    ad = sqrt(ad);
// 计算并输出结果
    for (int i = 0; i < n;i++)
        cout << (a[i] - av) / ad << endl;

    return 0;
}