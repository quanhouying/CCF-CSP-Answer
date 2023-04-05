#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);   //提高cin,cout的速度
    int n, t, time[2000][2] = {0}, count = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> time[i][0] >> time[i][1];
	}
	for (int i = 0;i < n;i++) {
		int l, r;
		cin >> l >> r;
		for (t = 0;t < 2000;t++) {
			if (time[t][0] > r)
				break;
			if (time[t][1] < l)
				continue;
			count += min(time[t][1], r) - max(time[t][0], l);
		}
	}
    cout << count;

    return 0;
}
