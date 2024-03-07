#include <iostream>
using namespace std;

int main()
{
	int k, q;
	long long n, ans, t;					// ans用于暂存结果, t用于暂存素因子的ti次方
	cin >> q;
	while (q) {
		cin >> n >> k;
		int time = 0;						// 记录素因子的次数
		ans = t = 1;
		if (n % 2 == 0) {					// 首先将唯一的偶数素数处理
			while (n % 2 == 0) {			// 暴力计算
				n /= 2;
				t *= 2;
				time++;
			}
			if (time >= k)					// 判断是否满足条件
				ans *= t;
		}
		for (int i = 3; i <= n;i += 2) {	// 处理所有的奇数素数, 方法同上
			t = 1;
			time = 0;
			while (n % i == 0) {
				n /= i;
				t *= i;
				time++;
			}
			if (time >= k)
				ans *= t;
		}
		cout << ans << endl;				// 输出结果
		q--;
	}
	

	return 0;
}