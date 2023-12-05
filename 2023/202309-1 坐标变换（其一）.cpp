#include <iostream>

using namespace std;

int main()
{
	int n, m, dx, dy, x, y;
	cin >> n >> m;
	dx = dy = 0;
	// 将所有的平移累积起来
	for (int i = 0; i < n;i++) {
		cin >> x >> y;
		dx += x;
		dy += y;
	}
	for (int i = 0; i < m;i++) {
		cin >> x >> y;
		cout << x + dx << ' ' << y + dy << endl;
	}

	return 0;
}
