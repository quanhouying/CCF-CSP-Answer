#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); //提高cin,cout的速度,但不可以混用scanf()/printf()
	int n, a, b, x1, y1, x2, y2, count = 0;
	cin >> n >> a >> b;
	// 对于每块田地, 只需要根据其坐标判断四个角的坐标是否在顿顿的田里就好
	for (int i = 0; i < n;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 >= a || y1 >= b || x2 <= 0 || y2 <= 0)
			continue;
		int l, r, u, d;
		l = max(x1, 0);
		r = min(x2, a);
		u = min(y2, b);
		d = max(y1, 0);
		count += (r - l) * (u - d);
	}
	cout << count;

	return 0;
}
