#include <bits/stdc++.h>
using namespace std;
struct boll{
	int a;	// 存储位置 
	int b;	// 存储方向 
	int c;	// 存储顺序 
};
bool cmp(boll p1, boll p2)
{
	return p1.a < p2.a;
}
bool cmpp(boll p1, boll p2)
{
	return p1.c < p2.c;
}
int main()
{
	int n, L, t;
	boll arr[100];
	cin >> n >> L >> t;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i].a;
		arr[i].b = 1;
		arr[i].c = i;
	}
	sort(arr, arr + n,cmp);		//将小球处理为在数轴上从左到右的顺序，方便处理运动过程 
	while (t--)
	{
		//先判断是否有碰撞变向 
		if (arr[0].a == 0 || arr[0].a == arr[1].a)
			arr[0].b *= -1; 
		for (int i = 1;i < n - 1;i++)	// 对于中间部分的小球，只需要判断是否与相邻的碰撞 
			if (arr[i].a == arr[i - 1].a || arr[i].a == arr[i + 1].a)
				arr[i].b *= -1;
		if (arr[n - 1].a == L || arr[n - 1].a == arr[n - 2].a)
			arr[n - 1].b *= -1;
		for (int i = 0;i < n;i++)
			arr[i].a += arr[i].b;
	}
	sort(arr, arr + n,cmpp);	// 将小球处理为原来的顺序，输出结果 
	for (int i = 0;i < n;i++)
		printf("%d ",arr[i].a);
	
	return 0;
}
