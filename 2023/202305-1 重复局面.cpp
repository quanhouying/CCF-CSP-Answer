#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 将每个局面连接成一个长度为64个字符的字符串, 以此为哈希表(unordered_map)的key, 将出现的次数作为value

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); //提高cin,cout的速度,但不可以混用scanf()/printf()
	int n;
	unordered_map<string, int> umap;
	cin >> n;
	for (int i = 0; i < n;i++) {
		string s;
		s = "";
		for (int j = 0; j < 8;j++) {
			string t;
			cin >> t;
			s += t;
		}
		cout << umap[s] + 1 << endl;
		umap[s]++;
	}

	return 0;
}