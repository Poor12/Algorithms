//优先队列 priority<参数一（堆内元素类型），参数二（存储堆元素类型，默认vector），参数三（less大根堆，greater小根堆，默认less）>
#include <queue>
int main() {
	priority_queue<int> q;
	int a;
	while (cin>>a)//ctrl z结束
	{
		q.push(a);
	}
	while (!q.empty())
	{
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}