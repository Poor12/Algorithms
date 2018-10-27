//heap
//二叉堆作为完全二叉树，保存在一维数组heap[0...n-1],其中对于heap[i],父节点heap[(i-1)/2],左子节点heap[2*i+1],右子节点heap[2*i+2],若该节点>(n-1)/2则为叶节点
#define max 1000
#include <vector>
int heap[max];
int len = 0;
void heap_insert(int num) {//插入
	int k = len++;
	heap[k] = num;
	while (k>0)//向上调整
	{
		int t = (k - 1) / 2;
		if (heap[t] > heap[k]) {
			swap(heap[t], heap[k]);
			k = t;
		}
		else
			break;
	}
}
void heap_delete() {//向下调整
	if (len) {
		int ans = heap[0];
		int k = 0;
		heap[k] = heap[len--];
		while ((k*2+1)<=len)//无左儿子时停止
		{
			int t = k * 2 + 1;
			if (t<len&&heap[t]>heap[t + 1]) ++t;
			if (heap[k] > heap[t]) {
				swap(heap[k], heap[t]);
				k = t;
			}
			else
				break;
		}
	}
	else {
		printf("堆空");
	}
}
//数组堆化，从上往下，从最后一个非叶子节点开始迭代到根节点
void heapify(vector<int> &A) {

	int n = A.size();
	if (n == 0) {
		return;
	}
	for (int i = n / 2; i >= 1; i--) {
		int k = i;
		int j = 2 * i;
		while (j <= n) {
			if (j < n && A[j - 1] > A[j]) {
				j++;
			}
			if (A[k - 1] > A[j - 1]) {
				swap(A[k - 1], A[j - 1]);
				k = j;
				j = 2 * k;
			}
			else {
				break;
			}
		}
	}
}