#include <iostream>
int main()
{
    using namespace std;
    int n, k, t, xl, yd, xr, yu;
    int time, max, jing, dou;
// 用max表示最大连续在危险区的坐标数，以此判断情况
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    for (int i = 0; i < n;i++)          // n行输入
    {
        max = time = 0;
        for (int j = 0; j < t;j++)      // t对坐标
        {
            int x, y;
            cin >> x >> y;
// 判断坐标是否属于风险区
            if ((x >= xl) && (x <= xr) && (y >= yd) && (y <= yu))
                time++;
            else
                time = 0;
            if (time > max)
                    max = time;
        }
        if (max >= k)
            dou++;
        if(max)
            jing++;
    }
    cout << jing << endl
         << dou;

    return 0;
}