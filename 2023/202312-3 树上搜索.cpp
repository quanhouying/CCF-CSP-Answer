#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

typedef struct TreeNode {
	long long val;					// 存储节点自身的权重
	long long valAll;				// 存储以此节点为根的树的权重和
	unordered_set<int> children;	// 存储子节点
} TreeNode;
set<int> seg;						// 做查询用

long long dfs(int root, vector<TreeNode>& nodes, vector<bool>& st) {
	seg.insert(root);
	long long t = 0;
	for (auto child : nodes[root].children) {
		if (!st[child])				// 如果节点已经被删除则跳过
			continue;
		t += dfs(child, nodes, st);
	}
	nodes[root].valAll = nodes[root].val + t;
	return nodes[root].valAll;
}// 深度优先搜素，计算每个结点及其子节点的权重和

int query(int root, vector<TreeNode>& nodes, vector<bool>& st) {
	long long t = LONG_LONG_MAX;
	int ans;
	for (auto node : seg) {
		// 计算节点的wi值
		long long w = abs(nodes[root].valAll - 2 * nodes[node].valAll);
		if (t > w) {
			t = w;
			ans = node;
		}
	}
	return ans;
}// 寻找wi最小的节点序号

bool judge(int q, int root, vector<TreeNode>& nodes, vector<bool>& st) {
	if (q == root)
		return true;
	bool ans = false;
	for (auto child : nodes[root].children) {
		ans |= judge(q, child, nodes, st);
		if (ans)
			return ans;
	}
	return false;
}// 判断用户询问名词是否属于该类别

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); //提高cin,cout的速度,但不可以混用scanf()/printf()
	int n, m;
	cin >> n >> m;
	vector<TreeNode> nodes(n + 1);	// 用于存储节点
	vector<bool> st(n + 1, true);	// 用于存储节点的存在情况
	// 构建要查询的树
	for (int i = 1; i <= n;i++) {
		cin >> nodes[i].val;
	}
	for (int i = 1; i < n;i++) {
		int t;
		cin >> t;
		nodes[t].children.insert(i + 1);
	}
	// 查询
	for (int i = 0; i < m;i++) {
		int root = 1, q;
		cin >> q;
		seg.clear();
		// 将所有节点都设为存在
		for (int i = 0; i < st.size();i++)
			st[i] = true;
		dfs(root, nodes, st);
		while (seg.size() > 1) {
			int ans = query(root, nodes, st);
			cout << ans << " ";
			if (judge(q, ans, nodes, st)) {	// 如果属于，将当前节点设为根
				root = ans;
			}
			else {							// 否则将该节点记为删除，其子节点也不会被dfs搜索到
				st[ans] = false;
			}
			seg.clear();
			dfs(root, nodes, st);
		}
		cout << endl;
	}

	return 0;
}