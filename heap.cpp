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

//heap
/*
	void heap(int a[],int n)
	{
		for(i=n/2;i>=1;--i)
		{
			adjust(a,i,n);
		}
	}
	void adjust(int a[],int i,int n)
	{
		s=i;
		x=a[s];
		for(j=2*i;j<=n;j=j*2)
		{
			if(j+1<=n&&a[j]<a[j+1]) j++;
			if(x>a[j]) break;
			a[s]=a[j];
			s=j;
		}
		a[s]=x;
	}

	void adjust(a,i,n)
	{
		int l=2*i;
		int r=2*i+1;
		smallest=i;
		if(r<=n&&a[l]<a[r])
			smallest=r;
		else if(l<=n)
			smallest=l;
		if(smallest!=i)
		{
			temp=a[smallest];
			a[i]=temp;
			a[smallest]=temp;
			adjust(a,smallest,n);
		}
	}

	struct heapstruct{
		int *elements;
		int size;
		int capacity;
	};
	typedef heapstruct *mapheap;
	maxheap create(int maxsize)
	{
		maxheap h=new headstruct();
		h->elements=new elementtype[maxsize+1];
		h->size=0;
		h->capacity=maxsize;
		h->elements[0]=maxdata;
		return h;
	}
	void insert(maxheap h,int x)
	{
		int i;
		if(isfull(h))
		{
			printf("最大堆已满");
			return;
		}
		i=++h->size;
		for(;h->elements[i/2]<x;i/=2)
		{
			h->elements[i]=h->elements[i/2];
		}
		h->elements[i]=x;
	}
	int deletemax(maxheap h)
	{
		int parent,child;
		int maxitem,temp;
		if(isempty(h))
		{
			printf("空");
			return;
		}
		maxitem=h->elements[1];
		temp=h->elements[h->size--];
		for(parent=1;parent*2<=h->size;parent=child)
		{
			child=parent*2;
			if(child!=h->size&&h->elements[child]<h->elements[child+1])
				child++;
			if(temp>=h->elements[child]) break;
			else
				h->elements[parent]=h->elements[child];
		}
		h->elements[parent]=temp;
		return maxitem;
	}
*/