#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Tree{
	int x;
	int y;
}trees[1000];								// 存储树的位置
bool cmp(Tree & t1, Tree &t2)
{
	if (t1.x != t2.x)
		return t1.x < t2.x;
	else
		return t1.y < t2.y;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); //提高cin,cout的速度
	int n, L, S;
	int total, num, ans;
	total = num = ans = 0;
	int map[51][51];						// 存储藏宝图
	cin >> n >> L >> S;
	int dif = L - S;
	for (int i = 0; i < n;i++)				// 读入树的坐标
		cin >> trees[i].x >> trees[i].y;
	sort(trees, trees + n, cmp);
	for (int i = S; i >= 0;i--)				// 读入藏宝图
		for (int j = 0; j <= S;j++)
		{
			cin >> map[i][j];
			if (map[i][j])
				total++;
		}
	for (int i = 0; i < n;i++)				// 判断树是否可以与藏宝图左下角匹配
	{
		bool t = true;
		if (trees[i].x > dif || trees[i].y > dif)
			continue;
		for (int j = 0; j <= S;j++)
		{
			for (int k = 0; k <= S;k++)
			{
				if (map[j][k])
				{
					for (int m = i; m < n;m++)
					{
						if (trees[m].x - trees[i].x == j && trees[m].y - trees[i].y == k)
							break;
						if (m == n - 1)		// 没有找到对应位置的树，该点为假
							t = false;
					}
				}
				else
				{
					for (int m = i; m < n;m++)
					{
						if (trees[m].x - trees[i].x == j && trees[m].y - trees[i].y == k)
						{
							t = false;		// 找到了不该存在的树，该点为假
							break;
						}
					}
				}
				if (t == false)				// 假点，直接跳出
					break;
			}
			if (t == false)					// 假点，直接跳出
				break;
		}
		if (t)
			ans++;
	}
	cout << ans;

	return 0;
}
