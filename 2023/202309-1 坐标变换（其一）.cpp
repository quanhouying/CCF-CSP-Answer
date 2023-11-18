#include <iostream>

using namespace std;

int main()
{
	int n, m, dx, dy;
	cin >> n >> m;
	dx = dy = 0;
	int x, y;
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