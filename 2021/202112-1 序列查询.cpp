#include <iostream>
int main()
{
    using namespace std;
    int n, N, l, r, f;
    long long sum = 0;              // 防止溢出
    cin >> n >> N;
// A(i)到A(i+1)之间的f(i) = i，数量等于(A(i+1) - A(i))
// i > A(n)后，f(i)就等于n
// 因此不需要使用数组存储每一个A(i)，只需要知道相邻的A(i)和A(i+1)，就可以计算其中的f
    cin >> l;
    for (f = 1; f < n; f++)
    {
        cin >> r;
        sum += (r - l) * f;
        l = r;
    }
    sum += (N - r) * f;
    cout << sum;

    return 0;
}