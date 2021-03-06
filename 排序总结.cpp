/*
	void sort(sqlist &r,int n)
	{
		i=1;
		while(i<=n/2)
		{
			min=max=i;
			for(j=i+1;j<=n-i+1;++j)
			{
				if(r[j].key<r[min].key)min=j;
				else if(r[j].key>r[max].key) max=j;
			}
			if(min!=i) r[min]<-->r[i];
			if(max!=n-i+1)
			{
				if(max==i)
					r[min]<-->r[n-i+1];
				else 
					r[max]<-->r[n-i+1];
			}
			++i;
		}
	}

*/

/*
	//快排非递归
	#define n 10
	in split(int a[n],int low,int high)
	{
		int j,k,x;
		k=low;j=high;x=a[k];
		while(k<j)
		{
			while(a[j]>=x&&k<j) j--;
			if(k<j){ a[k]=a[j];k++;}
			while(a[k]<=x&&k<j) k++;
			if(k<j){ a[j]=a[k];j--;}
		}
		a[k]=x;return k;
	}
	void qsort(int a[n])
	{
		int k,low=0,high=n-1;
		int stack[20][2],top=-1;
		top++;stack[top][0]=low;stack[top][1]=high;
		while(top>=0)
		{
			low=stack[top][0];
			high=stack[top][1];
			top--;
			k=split(a,low,high);
			if(low<high)
			{
				top++;
				stack[top][0]=low;
				stack[top][1]=k-1;
				top++;
				stack[top][0]=k+1;
				stack[top][1]=high;
			}
		}
	}
	main()
	{
		int k,a[n]={2,8,3,6,9,5,1,4,0,7};
		qsort(a);
		for(k=0;k<=n;++k)
			printf(" %d",a[k]);
	}

*/

//归并排序递归
/*
	#define maxsize 1000
	#define nn 10
	#include <stdio.h>
	int r[nn+1],r2[nn+1];//r[0]闲置
	int a[10]={17,1,23,77,51,13,39,11,19,15};
	void merge(int r[],int low,int m,int high,int r2[])
	{
		int i,j,k;
		k=i=low;
		j=m+1;
		while(i<=m&&j<=high)
		{
			if(r[i]<=r[j])
			{
				r2[k]=r[i];
				i++;
			}
			else
			{
				r2[k]=r[j];
				j++;
			}
			k++;
		}
		if(i>m)
			while(j<=high)
			{
				r2[k]=r[j];
				j++;
				k++;
			}
		else
			while(i<=m)
			{
				r2[k]=r[i];
				i++;
				k++;
			}
	}
	void mergesort(int r[],int r1[],int low,int high)//r为原数组，r1为新的数组
	{
		int m,r2[nn+1];
		if(low==high)
			r1[low]=r[low];
		else
		{
			m=(low+high)/2;
			mergesort(r,r2,low,m);
			mergesort(r,r2,m+1,high);
			merge(r2,low,m,high,r1);
		}
	}
	main()
	{
		int i;
		for(i=0;i<=9;++i)
			r[i+1]=a[i];
		mergesort(r,r2,1,10);
		for(i=1;i<=10;++i)
			printf(" %d",r2[i]);
		printf("\n");
	}

*/

//设n个数的数列存放在数组a[1..n]中，下列算法将变为一个堆
/*
	void adjust(int a[],int n)
	{
		int i,j,s,x;
		for(i=n/2;i>=1;--i)
		{
			s=i;
			x=a[s];
			for(j=2*s;j<=n;j*=2)
			{
				if(j<n&&a[j]<a[j+1]) j++;
				if(x>a[j]) break;
				a[s]=a[j];
				s=j;
			}
			a[s]=x;
		}
	}
*/

/*
	#include <stdio.h>
	typedef struct node
	{
		char data;
		struct node *link;
	}node;
	node *select(node *head)
	{
		node *p,*q,*r,*s;
		p=(node*)malloc(sizeof(node));
		p->link=head;
		head=p;
		while(p->link!=null)
		{
			q=p->link;
			r=p;
			while(q->link)
			{
				if(q->link->data<r->link->data)
					r=q;
				q=q->link;
			}
			if(r!=p)
			{
				s=r->link;
				r->link=s->link;
				s->link=p->link;
				p->link=s;
			}
			p=p->link;
			}
		}
		p=head;
		head=head->link;
		free(p);
		return head;
	}


	void selectsort(link l)
	{
		link p,q,minp;int temp;p=l->next;
		while(p)
		{
			minp=p;
			q=p->next;
			while(q)
			{
				if(q->data<minp->data)
					minp=q;
				q=q->next;
			}
			if(minp!=p)
			{
				temp=p->data;
				p->data=minp->data;
				minp->data=temp;
			}
			p=p->link;
		}
	}
*/

//奇偶交换排序
/*
	void oesort(int a[n])
	{
		int flag,i,t;
		do{
			flag=0;
			for(i=1;i<n;++i,++i)
			{
				if(a[i]>a[i+1])
				{
					flag=1;
					t=a[i+1];
					a[i+1]=a[i];
					a[i]=t;
				}
			}
			for(i=2;i<=n;++i,++i)
			{
				if(a[i]>a[i+1])
				{
					flag=1;
					t=a[i+1];
					a[i+1]=a[i];
					a[i]=t;
				}
			}
		}while(flag==1);
	}

*/

//排序算法小结
/*
排序方法	平均时间	最坏情况	辅助空间	稳定性

直接插入	n2			n2			1			稳定
折半插入	n2			n2			1			稳定
二路插入	n2			n2			n			稳定
表插入		n2			n2			1			稳定
冒泡		n2			n2			1			稳定
直接选择	n2			n2			1			不稳定
希尔		n1.3		n1.3		1			不稳定
快速		nlogn		n2			logn		不稳定
堆			nlogn		nlogn		1			不稳定
2路归并		nlogn		nlogn		n			稳定
基数排序	d*（rd+n)	d*(rd+n)	rd			稳定
*/

//冒泡
/*
	int j=1;flag=1;//flag作控制标志
	while(j<n&&flag)
	{
		flag=0;
		for(i=1;i<=n-j;++i)
		{
			if(r[i]>r[i+1])
			{
				flag=1;
				r[i]<-->r[i+1];
			}
		}
		j++;
	}

*/

//双向气泡
/*
	change=1;low=0;high=n-1;
	while(low<high&&change)
	{
		change=0;
		for(i=low;i<high;++i)
		{
			if(a[i]>a[i+1])
			{
				a[i]<-->a[i+1];
				change=1;
			}
		}
		high--;
		for(i=high;i>low;--i)
		{
			if(a[i]<a[i+1])
			{
				a[i]<-->a[i-1];
				change=1;
			}
		}
		low++;
	}


	//链表
	exchange=1;tail=null;
	while(exchange)
	{
		p=head->next;
		exchange=0;
		while(p->next!=tail)
			if(p->data>p->next->data)
			{
				temp=p->next;
				exchange=1;
				p->next=temp->next;
				temp->next->prior=p;
				temp->next=p;
				p->prior->next=temp;
				temp->prior=p->prior;
				p->prior=temp;
			}
		else
			p=p->next;
		tail=p;
		p=tail->prior;
		while()
		{

		}
		head=p;
	}
*/

//插入排序
/*
	for(i=2;i<=n;++I)
	{
		r[0]=r[i];//监视哨
		j=i-1;
		while(r[0].key<r[j].key)
		{
			r[j+1]=r[j];
			j=j-1;
		}
		r[j+1]=r[0];
	}

	p=p->link->link;
	l->link->link=null;
	while(p!=null)
	{
		q=p->link;//q指向p的后继
		s=l;
		while(s->link&&s->link->key<p->key) s=s->link;
		p->link=s->link;s->link=p;
		p=q;
	}
*/

//折半插入
/*
	//初始化 d[1]=r[1];first=1,final=1;
	for(i=2;i<=n;++i)
		if(r[i].key>=d[1].key)//插入后端
		{
			low=1;
			high=final;
			while(low<=high)
			{
				m=(low+high)/2;
				if(r[i].key<d[m].key) high=m-1;
				else low=m+1;
			}
			for(j=final;j>=high+1;j--) d[j+1]=d[j];//移动元素
			d[high+1]=r[i];final++;
		}
		else
		{
			if(first==1)
			{
				first=n;
				d[n]=r[i];
			}
			else
			{
				low=first;high=n;
				while(low<=high)
				{
					m=(low+high)/2;
					if(r[i].key<d[m].key) high=m-1;
					else low=m+1;
				}
				for(j=first;j<=high;++j)
					d[j-1]=d[j];
				d[high]=r[i];first--;
			}
		}
		r[1]=d[first];
		for(i=first%n+1,j=2;i!=first;i=i%n+1,j++)
			r[j]=d[i];

*/

//选择排序
/*
	for(i=1;i<n;++i)
	{
		k=i;
		for(j=i+1;j<=n;++j)
		{
			if(r[j].score>r[k].score) k=j;
			if(i!=k) r[i]<-->r[k];
		}
	}

	//改进
	for(i=1;i<=n/2;++i)
	{
		k=i;
		for(j=i+1;j<=n-i+1;j++)
		{
			if(a[j]>a[k]) k=j;//选第i个最大元素
		}
		if(k!=i) a[i]<-->a[k];
		k=n-i;//k记最小元素下标
		for(j=n-i;j<=i;j--)
			if(a[j]<a[k]) k=j;//选第i个最小元素
		if(k!=i) a[i]<-->a[k];
	}

	//链表
	p=head->next;
	while(p)
	{
		q=p->next;
		r=p;
		while(q!=null)
		{
			if(q->data<r->data) r=q;
			q=q->next;
		}
		if(r!=p)
			r->data<-->p->data;
		p=p->next;
	}

	//交换节点
	pre->link=start->link;start->link->link=p->link;pre=pre->next;
	p->link=start->link->link;start->link=p;


*/

//计数排序
/*
	for(i=0;i<n;++I)
	{
		for(j=0,cnt=0;j<n;++j)
		{
			if(a[j].key<a[i].key) cnt++;
		}
		b[cnt]=a[i];
	}
	//比较次数n^2，选择排序为n(n-1)/2
	for(i=0;i<n;++i) a[i].count=0;
	for(i=0;i<n;++I)
		for(j=i+1;j<n;++j)
			if(a[i].key<a[j].key) a[j].count++;
			else	a[i].count++:

*/

//a[0..n-1]存放1到n的不同的数，从大到小排序
/*
	for(i=0;i<n;++i)
		b[n-a[i]]=a[i];

*/

/*
	void quicksort(a,l,r)
	{
		low=l,high=r;
		x=a[low];
		while(low<high)
		{
			while(low<high&&a[high]>x) high--;
			if(low<high) a[low++]=a[high];
			while(low<high&&a[low]<x) low++;
			if(low<high) a[high--]=a[low];
		}
		a[low]=x;
		quicksort(a,l,low-1);
		quicksort(a,low+1,r);
	}

	//分类
	//要求一趟排序将序列分成三个部分，设三个指针i，j，k。将三种颜色分别用整数1、2、3表示
	int i=1,j=1,k=n,temp;
	while(j<=k)
		if(r[j]==1)
		{
			temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			++I;++J;
		}
		else if(r[j]==2) j++;
		else {
			temp=r[j];
			r[j]=r[k];
			r[k]=temp;
			k--;
		}
*/

/*
	//找到第j位的元素
	i=partition(a,l,n);
	while(i!=j)
		if(i<j) quicksort(a,i+1,n);
		else quicksort(a,l,i-1);
*/

//快排链表形式
/*
	//start为链首指针，end为链表指针，初始调用为null
	if(start==null||start==end) return;//空表或只有一个结点
	start1=end1=start;//右半链表头节点的前驱和尾节点的指针
	if(end1!=end) flag=1;
	p=start->next;
	while(flag)
	{
		if(p->data<start->data)
		{
			end1->next=p->next;//保留后继节点
			if(p==end) flag=0;
			if(start==end1) end0=p;//end0遍历遇到的第一个小于枢轴的节点，将为前半的尾节点
			p->next=start;start=p;//修改左半部链表头节点
			p=end1->next;
		}
		else
		{
			if(p==end) flag=0;
			endl->next=p;end1=p;
			p=p->next;
		}
	}
	linkquicksort(start,end0);
	linkquicksort(start1->next,end1);
*/

/*
	堆排序
	void sift(a,i,m)
	{
		s=i;
		x=a[s];
		for(j=2*i;j<=m;j=j*2)
		{
			if(j+1<=m&&a[j+1]>a[j].key) j++;
			if(x<a[j].key) a[s].key=a[j].key;
			else break;
			s=j;
		}
		a[s]=x;
	}

	void heapsort(r,n)
	{
		for(i=n/2;i>0;i--) sift(r,i,n);
		for(i=n;i>1;i--) {r[n]<-->r[1];sift(r,1,i-1);}
	}

	//最小最大堆是一种特定的堆，其最小层和最大层交替出现，根总是在最小层，最小最大堆中的任一节点的关键字总是在以它为根的子树中的所有元素中最小（最大)
	//从插入位置进行调整，调整过程由下到上，首先根据元素个数求出插入元素所在层次，以确定插入层是最大层还是最小层，若插入元素在最大层，则先比较插入元素是否比双亲小，如是先交换，之后将小堆与祖先调堆，直到满足小堆定义或到达根节点；若插入元素不小于双亲，则调大堆，直到满足大堆定义
	void minmaxheapins(rectype r[],int n)
	//假设r[1..n-1]是最小最大堆,插入第n个元素
	{
		j=n;r[0]=r[j];
		h=(log2n)+1;
		if(h%2==0)//偶数层，是最大层
		{
			i=n/2;
			if(r[0].key<r[i].key)//插入
			{
				r[j]=r[i];
				j=i/4;
				while(j>0&&r[j]>r[i])//调小堆
				{
					r[i]=r[j];
					i=j;
					j=i/4;
				}
				r[i]=r[0];
			}
			else
			{
				i=n;j=i/4;
				while(j>0&&r[j]<r[i])
				{
					r[i]=r[j];
					i=j;
					j=i/4;
				}
				r[i]=r[0];
			}
		}
		else
		{
			i=n/2;
			if(r[0].key>r[i].key)
			{
				r[j]=r[i];
				j=i/4;
				while(j>0&&r[j]<r[i])
				{
					r[i]=r[j];
					i=j;
					j=j/4;
				}
				r[i]=r[0];
			}
			else
			{
				i=n;
				j=i/4;
				while(j>0&&r[j]>r[i])
				{
					r[i]=r[j];
					i=j;
					j=j/4;
				}
				r[i]=r[0];
			}
		}
	}

*/

//基数排序，使用链式基数排序
//1.待排序记录以指针相连接，构成一个链表
//2.分配时，按当前关键字位的取值，将记录分配到不同的链队列中，每个队列中记录中记录的关键字位相同。本题是整数序列的基数排序，设置0到9共10个队列
//3.收集时，按当前关键字位取值从小到大将各队列首尾相链接成一个链表
//4.对每个关键字位均重复2，3两步，直至排序结束
/*
	for(i=1;i<n;++i)//n为数的个数
		r[i].next=i+1;//将r[1..n]链成一个静态链表
	r[n].next=-1;p=1;
	for(j=d-1;j>=0;j--)//进行d趟排序，位数
	{
		for(i=0;i<m;++I)//初始化桶，m=10
		{
			b[i].f=-1;
			b[i].e=-1;
		}
		while(p!=-1)
		{
			k=r[p].key[j];//k为桶的序号
			if(b[k].f==-1)//将r[p]链到桶头
				b[k].f=p;
			else
				r[b[k].e].next=p;//将r[p]链到桶尾
			b[k].e=p;//修改桶的尾指针
			p=r[p].next;//扫描下一个记录
		}
		i=0;
		while(b[i].f==-1) i++;
		t=b[i].e;p=b[i].f;//p为收集链表的头指针，t为尾指针
		while(i<m-1)
		{
			i++;
			if(b[i].f!=-1)
			{
				r[t].next=b[i].f;
				t=b[i].e;
			}
		}
		r[t].next=-1;
	}

	//二元序列（a1，b1）（a2，b2），...（an，bn）
	//a1<=a2<=a3<=a4...<=an
	//若ai=aj，必有b1<=bj
	//第一元用快速排序，第二元用直接插入排序

*/