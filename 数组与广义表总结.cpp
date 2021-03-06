//数组与广义表总结
//search(a,n,k)在数组a的前n个元素中找出第k个小的值
#define maxn 100
int a[maxn], n, k;
int search_c(int a[], int n, int k)
{
	int low, high, i, j, m, t;
	k--;low = 0;high = n - 1;
	do {
		i = low;
		j = high;
		t = a[low];
		do {
			while (i < j&&t < a[j])
				j--;
			if (i < j) a[i++] = a[j];
			while (i < j&&t >= a[i])
				i++;
			if (i < j) a[j--] = a[i];
		} while (i < j);
		a[i] = t;
		if (i == k) return a[i];
		if (i < k) low = i + 1;
		else high = i - 1;
	} while (i != k);
}

//广义表逆置
/*
逆置广义表的递归模型：
若ls为空，f(ls)=null;
若ls为原子,且tail（ls）为空，f(ls)=ls
若ls->tag=0,且ls->val.ptr.tp!=null,f(ls)=append(f(tail(ls)),head(ls))
若ls->tag=1,f(ls)=append(f(tail(ls)),f(head(ls)))
*/
typedef struct glistnode
{
	int tag;//0表示广义表，1表示原子
	struct glistnode* next;
	union {
		char data;
		struct {
			struct glistnode *hp, *tp;
		}ptr;
	}val;
}*glist,gnode;
glist reverse(glist p)
{
	glist q, h, t, s;
	if (p == NULL)
		q = NULL;
	else
	{
		if (p->tag == 0) {
			q = (glist)malloc(sizeof(gnode));
			q->tag = 0;
			q->val.data = p->val.data;
		}
		else
		{
			h = reverse(p->val.ptr.hp);//处理表头
			if (p->val.ptr.tp) {//产生表尾的逆置广义表
				t = reverse(p->val.ptr.tp);
				s = t;
				while (s->val.ptr.tp!=NULL)
				{
					s = s->val.ptr.tp;
				}
				s->val.ptr.tp = (glist)malloc(sizeof(gnode));
				s = s->val.ptr.tp;
				s->tag = 1;
				s->val.ptr.tp = NULL;
				s->val.ptr.hp = h;
				s->val.ptr.tp = t;
			}
			else
			{
				q = (glist)malloc(sizeof(gnode));
				q->tag = 1;
				q->val.ptr.tp = NULL;
				q->val.ptr.hp = h;
			}
		}
	}
	return q;
}

//将数列1...n*n，依次按蛇形方式存放在二维数组a[1...n,1...n]中
//蛇形方式即是按副对角线平行的各对角线，从左下到右上，再从右上到左下，存放n*n个整数
//对角线共2*n-1条，在副对角线上方的对角线，用k表示第k条，数组中元素x和y方向坐标之和为k+1，副对角线下方第k条对角线与第2*n-k条对角线对称，其元素下标等于其对称元素的相应坐标各加(k-n)
/*
#define nmax 10
int main() {
	int i, j, n, k, p, q, m;
	int a[nmax][nmax];
	scanf("%d", &n);
	m = 1;
	for (k = 1;k<=2*n-1;k++)//k表示对角线数
	{
		if (k < n) q = k;//q表示各条对角线上的元素数
		else q = 2 * n - k;
		for (p = 1;p <= q;p++)
		{
			if (k % 2 != 0)//k为偶数从右上到左下,奇数从左下到右上
			{
				i = q - p + 1;
				j = p;
			}
			else
			{
				i = p;
				j = q - p + 1;
			}
			if (k >= n) {
				i = i + n - q;
				j = j + n - q;
			}
			a[i][j] = m;
			m++;
		}
		for (i = 1;i <= n;++i)
		{
			for (j = 1;j < n;++j)
			{
				printf("%4d", a[i][j]);
				printf("\n");
			}
		}
	}
}
*/


//设有一个背包可以放入的物品重量为s，现有n件物品，重量分别为w1...wn，问能否从这n件物品中选择若干件，使得放入的重量之和正好是s。
//若第n件物品能放入背包，问题变为能否从第n-1件物品中选出若干件使称为s-w[n]，若第n件物品不能放入，问题变为能否从第n-1件物品中选出若干件使称为s。若最终s=0，则有一解；若s<0或s>0但物品数n<1，无解
/*
	knap(s,n)
	若s=0
		则knap-true
	否则若s<0或（s>0且n<1)
		则knap-false
		否则若knap(s-w[n],n-1)=true	
			则print(w[n]) knap=true
			否则knap(s,n-1) 

*/

//对于正整数n，输出其和等于n且满足以下限制条件的所有正整数的和式，组成和式的数字自左至右构成一个非递增的序列，如n=4，程序输出为
/*
	4=4
	4=3+1
	4=2+2
	4=2+1+1
	4=1+1+1+1
*/
/*
int a[100];
test(int n,int k)//参数n为分解和式的数，k为当前的分解深度
{
	int i,j;
	for(j=n;j>=1;j--)
	{
		a[k]=j;
		if(n-j==0){
			printf("%d= %d",a[0],a[1]);
			for(i=2;i<=k;i++)
				printf(" + %d",a[i]);
			printf("\n");
		}
		else
			test(n-j,k+1);
	}
}
main{
	test(4,1);
	a[0]=n;
}
*/

/*
	行逻辑链接顺序表是稀疏矩阵压缩存储的一种形式，为了随机存取任意一行的非零元，需要知道每一行第一个非零元在三元组表中的位置。
	为此，除非零元的三元组外，还需要一个向量，其元素值是每行第一个非零元在三元组表中的位置
	typedef struct {
		int mu, nu, tu;
		int rpos[maxrow + 1];//行向量，元素值为每行第一个非零行在三元组中的位置
		triple data[maxsize];
	}sparsmatrix;
};
*/

/*
	n对角矩阵公式推导：
	以三对角矩阵为例：三对角矩阵第一行和最后一行各有两个非零元素，其余每行均有三个非零元素，所以共有3*n-2个元素。
	1.主对角线左下对角线上的元素下标有i=j+1关系，k与i和j的关系为k=3*（i-1）；
	2.主对角线对角线上的元素下标有i=j关系，k与i和j的关系为k=3*（i-1）+1；
	3.主对角线右下对角线上的元素下标有i=j-1关系，k与i和j的关系为k=3*（i-1）+2；
	综上得出k=2*（i-1)+j
	因此i=k/3+1；j=k-2（i-1）=k-2*（k/3）=k%3+k/3

	上三角矩阵第一行有n个元素，第i-1行有n-（i-1）+1个元素，第一行到第i-1行是梯形，第i行上第j个元素是第i行上第j-i+1个元素
	k=（n+n-（i-1）+1）*（i-1）/2+j-i+1
	
*/

//设有大小不等的n个数据组（n个数据组中数据的总数为m），顺序存放在空间D中，每个数据占一个存储单位，数据组的首地址由数组S给出，将新数据x插入第i个数据组的末尾且属于第i个数据组，插入后，空间d和s的对应关系不变
/*
	if(i==n)	d[m]=x;
	else{
		for(j=m-1;j>=s[i+1];j--)
			d[j+1]=d[j];
		d[s[i+1]]=x;//第i个数据组的末尾，即第i+1个数据组的开始
		for(j=i+1;j<=n;++j) s[j]++;
	}
	m++;//总数+1
*/

//三元组存储的稀疏矩阵a，b的非零元分别为m和n，将a和b相加的算法，O（m+n）
/*
	设稀疏矩阵的非零元素的三元组以行序为主存储的三元组表内。为使时间复杂度为m+n，因此从两个三元组表的最后一个元素开始相加，结果非零元素放在a矩阵三元组表的m+n-1位置上。
矩阵的相加是对应元素的相加：若行号不等，则行号大者是结果矩阵中的元素；若行号相同，列号大者是结果矩阵中的元素；若行号列号相同，但对应元素之和为0，不予存储，否则作为新三元组存到三元组表中。结果的三元组至多是m+n个非零元素。最后对三元组表中的元素进行整理，使第一个三元组存在下标为0的位置。
*/


//对矩阵进行行变换，使它每行的平均值按递增顺序排列
/*
	由于每行元素个数相等，按平均值排列与按每行元素之和排列是相等的，所以先求出各行元素之和，放入一维数组，并根据一维数组进行排序。
*/

//寻找矩阵中的马鞍点，即在行中最小，列中最大的点
/*
	max[n]={0};//各列最大值的行号
	min[m]={0};
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
		{
			if(a[max[j]][j]<a[i][j]) max[j]=i;
			if(a[i][min[i]]>a[i][j]) min[i]=j;
		}
	for(i=0;i<m;++i)
	{
		j=min[i];
		if(i==max[j])
			printf("yes");
	}
*/

//给定一个整数数组b[0...n-1]，b中连续的相等元素构成的子序列称作平台，写出b中最长平台的长度
/*
	longest=1;k=0;j=0;i=0;
	while(i<n-1)//n是数组元素大小
	{
		while(i<n-1&&b[i]==b[i+1]) i++;
		if(i-j+1>longest){
			longest=i-j+1;
			k=j;
		}
		i++;j=i;
	}

	longest=1;a=b[0];k=1;
	for(i=1;i<n;++i)
	{
		if(b[i]==a)
		{
			k++:
		}
		else
		{
			if(k>longest) longest=k;
			k=1;
			a=b[i];
		}
	}
*/

//给定n*m矩阵a[a...b,c...d],并设a[i,j]<=a[i,j+1]和a[i,j]<=a[i+1,j],设计一算法判定x的值是否在a中，要求时间复杂度为o（m+n）
/*
	//从a[a][d]开始找起，若a[i][j]==x，找到；若a[i][j]<x，往i大的方向查找；反之往j小的方向查找
	while(i<=b&&j>=c&&!flag)
		if(a[i][j]==x) flag=1;
		else if(a[i][j]>x) j--;else i++:
*/

//蛇形将自然数1..n^2填入n*n矩阵
/*
	//按右上到左下的蛇形，沿平行于副对角线的各条对角线上，将自然数从小到大填写。当右上到左下时坐标i增加，坐标j减小，当j减到小于0时结束。然后j从0开始增加，而i从当前值减少，到i<0时结束，然后继续循环。当过副对角线后，i>n-1时j=j+2，开始从左下到右上填数；而j>n-1时i=i+2，开始从右上到左下填数，直到填完。
	while(i<n&&j<n)//i=0,j=0,k=1
	{
		while(i<n&&j>-1)
		{
			a[i][j]=k++;
			i++;j--;
		}
		if((j<0)&&(i<n)) j=0;
		else{
			j=j+2;
			i=n-1;
		}
		while(i>-1&&j<n)
		{
			a[i][j]=k++;
			i--;
			j++;
		}
		if(i<0&&j<n) i=0;
		else{
			i=i+2;
			j=n-1;
		}
	}
*/

//给定a[m][n],判断a中所有元素是否互不相同
/*
	//初值int *p=a
	//每个元素与同行后面的元素和后面行的元素比较
	//元素互不相等时总的比较次数为（m*n-1)+(m*n-2)+...1=(m*n)(m*n-1)/2，平均复杂度为O(（m*n）^2)
	for(i=0;i<m;++i)
		for(j=0;j<n-1;++j)
			for(p=a+[i*n+j];p<a+m*n;p++);
*/

//二项式(a+b)^n展开式的系数为C(n,0)=1,C(n,n)=1，对于n大于0；C(n,k)=C(n-1,k)+C(n-1,k-1)，对于k小于n大于0
/*
	//杨辉三角的递归解法
	int biform(int n,int k)
	{
		if(n<0||k<0||k>n)
		{
			cout<<"error"<<endl;
			exit(0);
		}
		if(k==0||k==n)
			return 1;
		else
			return biform(n-1,k)+biform(n-1,k-1);
	}

	//非递归解法，阶乘公式
	int cnk(int n,int k)
	{
		int i;long x=1,y=1;
		for(i=1;i<=k;++i) x*=i;
		for(i=n-k+1;i<=n;++i) y*=i;
		return y/x;
	}
	}
*/

//设计算法数组a[n]所有偶数移到奇数前，复杂度O（n）
/*
	while(i<j)
	{
		while(i<j&&a[i]%2==0) i++;
		while(i<j&&a[i]%2==1) j--;
		if(i<j)
		{
			x=a[i];
			a[i++]=a[j];
			a[j--]=x;
		}
	}
*/

//设S是n个元素的集合，则S的幂集P(S)定义为S所有子集的集合，例如S=（a,b,c),P(S)={(),(a),(b),(c)...(a,b,c)}
/*
	设n个元素存放在数组a[1...n]中，设S初始为空集，可依次将数组a的每个元素并入S，产生含一个元素的若干集合，再以含一个元素的集合为初始集合，依次将a的第二个元素并入S，形成了含有两个元素的若干集合，直到全部元素并入
	void powerset(set S,int num)
	{
		outset(S);
		for(int i=num+1,i<=n;++i)
			powerset(S+a[i],i);
	}
*/

//遍历以十字链表表示的稀疏矩阵每一行的元素，每一行、列为循环链表
/*
	//设rch是行列表头指针，则rch->right==rch时该行无非零元素，用i记行号，用一维数组元素a[i]记第i行非零元素的个数
	while(rch!=Hm)//各行元素计算完毕
	{
		p=rch->right;
		num=0;
		while(p!=rch)
		{
			printf("M[%d][%d]=%d",p->row,p->col,p->uval.e);
			num++;
			p=p->right;
			printf("\n");
		}
		a[i++]=num;
		rch=rch->uval.next;//移到下一行首
	}
*/

//数组h[1:1000]中存放着1000个大小不同的正整数。
//选择一分类算法使能最快地得到其中10个最大地整数。
/*
	在n个正整数中，选出k个最大的数，应使用堆排序方法。最坏情况下的时间复杂度为O（nlogn）
*/

//已知两个定长数组，它们分别存放两个非降序有序序列，编写程序把第二个数组序列中的数逐个插入前一个数组序列，完成后两个数组分别有序，且不能另开辟数组也不能进行排序算法
/*
	//设两个数组分别是a和b，各有m和n个元素。结果要求第一个数组的最后一个数a[m-1]<b[0]
	while(a[m-1]>b[0])
	{
		x=a[m-1];
		a[m-1]=b[0];
		在0..m-2间折半查找a[m-1]的插入位置，并插入
		在1..n-1间折半查找x的插入位置，并插入
	}
*/

//设数组a[1..n]中，a[n-2k+1...n-k]和a[n-k+1..n]中元素各自从小到大排好序，使a[n-2k+1..n]有序
/*
	两段有序合并成一段有序：可以将两段最后一个元素进行比较，若正序，则指针前移；若逆序则交换，并调整前端有序，重复以上过程
*/

//a[1.100]为一个记录构成的数组，b[1..100]是一个整数数组，要求按b[1..100]的内容调整a中记录的顺序，比如b[1]=11,将a[1]的内容调至a[11]
/*
	while(i<n)//初始值i=1，n=100
	{
		if(b[i]!=i)
		{
			j=i;
			while(b[j]!=i)
			{
				k=b[j];b[j]=b[k];b[k]=k;
				r0=a[j];a[j]=a[k];a[k]=r0;
			}
		}
		i++;
	}
*/

//升序数组a[m]和降序数组b[n]合并的问题，结果保存在新数组
/*
	i=0;j=n-1;k=0;//i,j,k分别为a,b,c的下标
	while(i<m&&j>=0)
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j--];
	while(i<m)
		c[k++]=a[i++];
	while(j>=0)
		c[k++]=b[j--];
	//注意不开辟新空间的解法，（结果在a数组，且a数组空间足够大，初始k=m+n-1)
*/

//将两个下三角矩阵的下三角存储到c矩阵
//a矩阵，b矩阵n*n，c矩阵n*（n+1），a的下三角复制到c，b逆置后复制到c
/*
	for(i=0;i<n;++i)
	{
		for(j=0;j<=i;++j)
			c[i][j]=a[i][j];
		for(j=i+1;j<=n;j++)
			c[i][j]=b[j-1][i];
	}
*/