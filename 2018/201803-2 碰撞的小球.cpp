#include <bits/stdc++.h>
using namespace std;
struct boll{
	int a;	// �洢λ�� 
	int b;	// �洢���� 
	int c;	// �洢˳�� 
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
	sort(arr, arr + n,cmp);		//��С����Ϊ�������ϴ����ҵ�˳�򣬷��㴦���˶����� 
	while (t--)
	{
		//���ж��Ƿ�����ײ���� 
		if (arr[0].a == 0 || arr[0].a == arr[1].a)
			arr[0].b *= -1; 
		for (int i = 1;i < n - 1;i++)	// �����м䲿�ֵ�С��ֻ��Ҫ�ж��Ƿ������ڵ���ײ 
			if (arr[i].a == arr[i - 1].a || arr[i].a == arr[i + 1].a)
				arr[i].b *= -1;
		if (arr[n - 1].a == L || arr[n - 1].a == arr[n - 2].a)
			arr[n - 1].b *= -1;
		for (int i = 0;i < n;i++)
			arr[i].a += arr[i].b;
	}
	sort(arr, arr + n,cmpp);	// ��С����Ϊԭ����˳�������� 
	for (int i = 0;i < n;i++)
		printf("%d ",arr[i].a);
	
	return 0;
}
