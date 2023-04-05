#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); //提高cin,cout的速度,但不可以混用scanf()/printf()
	int n, m, k, field[100001] = {0};
	cin >> n >> m >> k;
	for (int i = 0; i < n;i++) {
		int t, c;
		cin >> t >> c;
		field[t] += c;
	}
	for (int i = 100000; i > 0;i--) {
		if (field[i] == 0)
			continue;
		if (m > field[i]) {
			m -= field[i];
			field[i - 1] += field[i];
			field[i] = 0;
		}
		else {
			cout << i;
			break;
		}
	}

	return 0;
}
