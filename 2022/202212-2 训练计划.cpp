#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); //提高cin,cout的速度,但不可以混用scanf()/printf()
	int n, m;
	bool b = true;
	cin >> n >> m;
	int t[m + 1][2], ans[m + 1][2];
	t[0][0] = t[0][1] = ans[0][0] = ans[0][1] = 0;
	for (int i = 1; i <= m;i++) {
		cin >> t[i][0];
	}
	for (int i = 1; i <= m;i++) {
		cin >> t[i][1];
	}
	for (int i = 1; i <= m;i++) {
		if (t[i][0])
			ans[i][0] = t[t[i][0]][1] + ans[t[i][0]][0];
		else
			ans[i][0] = 1;
	}
	for (int i = m; i > 0;i--) {
		ans[i][1] = n - t[i][1] + 1;
		for (int j = m; j > i;j--)
			if (t[j][0] == i && (ans[i][1] + t[i][1] - 1) > ans[j][1]) {
				ans[i][1] = ans[j][1] - t[i][1];
			}
		if (ans[i][1] < 0) {
			b = false;
			break;
		}
	}
	for (int i = 1; i <= m;i++) {
		cout << ans[i][0] << ' ';
	}
	if (b) {
		cout << '\n';
		for (int i = 1; i <= m;i++) {
			cout << ans[i][1] << ' ';
		}
	}

	return 0;
}
