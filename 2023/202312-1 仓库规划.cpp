#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> hubs;					// 用于存储仓库位置编码
	for (int i = 0; i < n;i++) {				// 读入仓库位置编码
		int t;
		vector<int> t_hub;
		for (int j = 0; j < m;j++) {
			cin >> t;
			t_hub.emplace_back(t);
		}
		hubs.emplace_back(t_hub);
	}
	// 这里直接暴力遍历比较
	for (int i = 0; i < n;i++) {
		int j;
		for (j = 0; j < n;j++) {
			bool isUp = true;
			for (int k = 0; k < m;k++) {
				if (hubs[i][k] >= hubs[j][k]) {
					isUp = false;
					break;
				}
			}
			if (isUp) {
				cout << j + 1 << endl;
				break;
			}
		}
		if (j == n) {
			cout << 0 << endl;
		}
	}

	return 0;
}