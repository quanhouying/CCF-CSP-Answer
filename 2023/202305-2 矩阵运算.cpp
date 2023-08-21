#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); //提高cin,cout的速度,但不可以混用scanf()/printf()
	int n, d;
	cin >> n >> d;
	vector<vector<ll>> Q(n, vector<ll>(d, 0)), K(n, vector<ll>(d, 0)), V(n, vector<ll>(d, 0));
	vector<vector<ll>> temp(d, vector<ll>(d, 0));// 用于存储中间结果
	// 先读入三个矩阵
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < d;j++) {
			cin >> Q[i][j];
		}
	}// 读入Q
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d;j++) {
			cin >> K[i][j];
		}
	} // 读入K的转置
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < d;j++) {
			cin >> V[i][j];
		}
	}// 读入V
	// 进行计算, 这里要先计算后两个矩阵的乘法以减少运算次数
	for (int i = 0; i < d;i++) {
		for (int j = 0; j < d;j++) {
			ll t = 0;
			for (int k = 0; k < n;k++)
				t += K[k][i] * V[k][j];
			temp[i][j] = t;
		}
	}// 计算K x V的结果, 存储在temp中
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < d;j++) {
			ll t = 0;
			for (int k = 0; k < d;k++)
				t += Q[i][k] * temp[k][j];
			K[i][j] = t;
		}
	}// 计算Q x temp(K x V)的结果, 存储在K中, 提高空间利用率
	for (int i = 0; i < n;i++) {
		int t;
		cin >> t;
		for (int j = 0; j < d;j++)
			K[i][j] *= t;
	}// 与向量W点乘
	// 输出结果
	for (int i = 0; i < n; i++)
	{
		cout << K[i][0];
		for (int j = 1; j < d; j++)
		{
			cout << ' ' << K[i][j];
		}
		cout << endl;
	}

	return 0;
}
/*#include <windows.h>
#include <iostream>
 
using namespace std;
 
#define NAME_LINE   40
 
//定义线程函数传入参数的结构体
typedef struct __THREAD_DATA
{
    int nMaxNum;
    char strThreadName[NAME_LINE];
 
    __THREAD_DATA() : nMaxNum(0)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }
}THREAD_DATA;
 
 
 
//线程函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;
 
    for (int i = 0; i < pThreadData->nMaxNum; ++ i)
    {
		printf("%s --- %d\n",pThreadData->strThreadName, i);
        Sleep(100);
    }
    return 0L;
}
 
int main()
{
    //初始化线程数据
    THREAD_DATA threadData1, threadData2;
    threadData1.nMaxNum = 5;
    strcpy(threadData1.strThreadName, "线程1");
    threadData2.nMaxNum = 10;
    strcpy(threadData2.strThreadName, "线程2");
 
//创建第一个子线程
    HANDLE hThread1 = CreateThread(NULL, 0, ThreadProc, &threadData1, 0, NULL);
    //创建第二个子线程
    HANDLE hThread2 = CreateThread(NULL, 0, ThreadProc, &threadData2, 0, NULL);
    //关闭线程
    CloseHandle(hThread1);
    CloseHandle(hThread2);
 
    //主线程的执行路径
    for (int i = 0; i < 5; ++ i)
    {
		printf("主线程 === %d\n", i);
		Sleep(100);
    }
 
    system("pause");
    return 0;
}*/