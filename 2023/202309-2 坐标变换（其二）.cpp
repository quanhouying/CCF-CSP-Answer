#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	// 将伸缩和旋转分开看，就是从i到j的过程中将坐标先伸缩后旋转(先后可以颠倒)
	int n, m, l, r;									// l, r代表题目中的i和j，
	cin >> n >> m;
	double x, y;
	vector<double> k, a;							// 用于存储前缀和的结果
	k.emplace_back(1);								// k代表倍数的累计值
	a.emplace_back(0);								// a代表角度的累计值
	for (int i = 1; i <= n;i++) {
		int t;
		double t_k;
		scanf("%d %lf", &t, &t_k);
		if (t % 2) {
			k.emplace_back(t_k * k[i - 1]);
			a.emplace_back(a[i - 1]);
		}
		else {
			k.emplace_back(k[i - 1]);
			a.emplace_back(t_k + a[i - 1]);
		}
	}
	for (int i = 0; i < m;i++) {
		scanf("%d %d %lf %lf", &l, &r, &x, &y);
		double t_x, t_y, d;
		d = a[r] - a[l - 1];						// 计算旋转的角度
		// 伸缩
		x *= (k[r] / k[l - 1]);
		y *= (k[r] / k[l - 1]);
		// 旋转
		t_x = x * cos(d) - y * sin(d);
		t_y = x * sin(d) + y * cos(d);
		printf("%lf %lf\n",t_x, t_y);
	}

	return 0;
}