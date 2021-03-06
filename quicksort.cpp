//quicksort O(nlog2n) 最坏O(n^2) 最大递归层数log2(n+1) 不稳定
//（1）确定递归结束条件
//（2）从数组中选择一个基准项
//（3）创建两个子数组，小于基准项的放入第一个子数组，大于基准项的放入第二个子数组
//（4）分别对子数组递归调用
int p[10];
void qsort(int low, int high) {//st 0 ed n-1
	int j,k,x;
	k=low;j=high;x=a[k];
	while(k<j)
	{
		while(a[j]>=x&&k<j) j--;
		if(k<j){ a[k]=a[j];k++;}
		while(a[k]<=x&&k<j) k++;
		if(k<j){ a[j]=a[k];j--;}
	}
	a[k]=x;
	qsort(low, k-1);
	qsort(k+1,high);
}

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