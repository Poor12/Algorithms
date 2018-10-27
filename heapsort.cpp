//堆排序
#include <queue>
#include <vector>
#include <algorithm>
int main() {
	int a[] = { 1,3,5,7,2,6,9,8,0 };
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0;i < 9;++i) {
		q.push(a[i]);
	}
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
}