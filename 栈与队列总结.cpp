//栈与队列总结
/*中缀表达式exp1转换为后缀表达式exp2的规则如下：
	设操作符栈s，初始化为空栈，压入优先级最低的操作符‘#’。对中缀表达式从左向右扫描，遇操作数，直接写入exp2；若是操作符w，分如下情况处理，直至表达式扫描完：
	1.w为一般操作符（'+','-','*','/'等），要与栈顶操作符比较优先级，若w优先级高于栈顶操作符（左括号优先级最低），则入栈，否则栈顶运算符退栈到exp2，w再与新栈顶操作符作上述比较，直至w入栈
	2.w为左括号，入栈
	3.w为右括号，操作符栈退栈并进入exp2，直至碰到左括号为止，左括号退栈，右括号删除，完成消除括号的目的
	4.w为‘#’，表示中缀表达式结束，操作符栈中元素一次退栈进入exp2，直至遇到‘#’

简单方法：
	1.将中缀表达式中的所有子表达式按计算规则用嵌套括号括起来
	2.顺序将每对括号中的运算符移到相应括号的后面（后缀转前缀将运算符移至括号前）
	3.删除所有括号
*/

//hanoi塔问题，假设n个盘子从钢针x移动到钢针z，可借助钢针y
//Hn=H（n-1）*2+1=2^n-1


//堆栈的入栈操作
/*
typedef struct{
	int *base;
	int *top;
	int stacksize;
}spstack;
int push(spstack s,int e)
{
	if(s.top-s.base>=s.stacksize-1){//栈满了
		s.base=(int*) realloc(s.base,(s.stacksize+1)*sizeof(int));
		if(!s.base)
		{
			printf("not enough memory");
			return 0;
		}
		s.top=s.base+s.stacksize-1;
		s.stacksize=s.stacksize+1;
	}
	*(++s.top)=e;
	return 1;
}

*/


//中缀表达式转化为后缀表达式中从右向左进行计算
//规定栈顶运算符**的级别小于正从表达式中读出的运算符**，即刚读出的运算符**级别高于栈顶运算符**，因此入栈
/*
以a**b**c为例
	读入a，不是操作符，直接写入结果表达式。再读入*，这里规定在读入*后不能立即当乘号处理，要看下一个符号，若下一个符号不是‘*’，则前一个‘*’是乘号。
	因为下一个符号是‘*’，所以入栈，再读入b，直接进入结果表达式。接着读入**，遇栈顶比较，均为**，因为后加入的**级别高于先加入的**，因此**入栈，读入c直接到结果表达式。
	将运算符退栈至表达式，可得结果表达式为abc****
*/

//用栈作工具，完成十进制到八进制的转换
/*
while(n){
	push(s,n%8);
	n=n/8;
}
while(!empty(s))
{
	pop(s,e);
	cout<<e;
}
*/

//循环队列的实现
/*
1.
typedef struct node{
	elemtype elemcq[m];
	int front,rear;
}cqnode;
cqnode cq;
1.初始状态
	cq.front=cq.rear=0;
2.队列空
	cq.front=cq.rear;
3.队列满
	（cq.rear+1)%m==cq.front;

2.
typedef struct{
	elemtype q[m];
	int rear,length;//元素数
}sequeue;
sequeue initqueue(sequeue cq)
{
	cq.rear=0;
	cq.length=0;
	return cq;
}
sequeue enqueue(sequeue cq,elemtype x)
{
	if(cq.length==m) return 0;
	else{
		cq.rear=(cq.rear+1)%m;
		cq.q[cq.rear]=x;
		cq.length++;
	}
	return cq;
}
elemtype dlqueue(sequeue cq)
{
	if(cq.length==0)
		return 0;
	else{
		int front=(cq.rear-cq.length+1+m)%m;
		cq.length--;
		return cq.q[front];
	}
}
*/

//队列逆置
/*
	makeempty(s);
	while(!isempty(q))
	{
		value=dequeue(q);
		push(s,value);
	}
	while(!isempty(q))
	{
		value=pop(s);
		enqueue(q,value);
	}
*/
//两个栈实现队列
/*
初始时设栈s1和栈s2均为空
1.用栈s1和s2模拟一个队列的输入：设s1和s2容量相等，分以下三种情况讨论：若s1未满，则元素入s1栈；若s1满，s2空，则将s1退栈到空，退栈元素依次压栈入s2，之后元素入s1栈；若s1满，s2不空则不能入队
if(top1==n&&!empty(s2))
{
	cout<<"栈满"<<endl;
	return 0;
}
if(top1==n&&empty(s2))
{
	while(!empty(s1))
	{
		pop(s1,x);
		push(s2,x);
	}
	push(s2,x);
	return 1;
}
2.模拟出队：若s2不空，退栈，即出队；若s2为空且s1不空，则将s1栈中全部元素退栈，并依次压入s2中，s2栈顶元素退栈，若均为空，则队列为空
if(!empty(s2))
{
	pop(s2,x);
	cout<<"出队元素为"<<x<<endl;
}
else{
	if(empty(s1))
	{
		cout<<"队列空"<<endl;
	}
	else
	{
		while(!empty(s1))
		{
			pop(s1,x);
			push(s2,x);
		}
		pop(s2,x);
		cout<<"出队元素为"<<x<<endl;
	}
}
3.判断队列空：s1和s2均为空，队列空
if(empty(s1)&&empty(s2)) return 0;
else return 1;
s1和s2容量之和是队列的最大容量。其操作是：s1栈满后全部退栈并压栈入s2，再入栈s1直至s1满，相当于元素入队完毕。出队时，s2退栈完毕后，s1栈中元素依次退栈至s2，s2退栈完毕，相当于全部退栈完毕。
*/

//两栈共享空间
/*
typedef struct
{
	elementtype stack[maxsize];
	int top[2];
}stk;

if(s.top[1]-s.top[0]==1) cout<<"full"<<endl;
switch(i)
{
	case 0:s.stack[++s.top[0]]=x;return 1;break;
	case 1:s.stack[--s.top[1]]=x;return 1;break;
}

switch(i)
{
	case 0:
		if(s.top[0]==-1){ cout<<"empty";return -1;}
		else return s.stack[s.top[0]--];
	case 1:
		if(s.top[1]==maxsize){ cout<<"empty";return -1;}
		else return s.stack[s.top[1]++];
}
*/

//判断括号是否匹配
//左括号进栈，右括号退栈。退栈时，若栈顶元素是左括号，则新读入的右括号与左括号可消去

//整数序列a1...an，给出求解最大值的递归程序
/*
	if(n==0) maxn=a[0];
	else if(a[n]>maxvalue(a,n-1)) maxn=a[n];
	else maxn=maxvalue(a,n-1);
*/
//求最大最小元素类似
/*
	void minmaxvalue(int a[],int n,int &max,int &min)//min,max初始时赋a[0]
	{
		if(n>=0)
		{
			if(max<a[n]) max=a[n];
			if(min>a[n]) min=a[n];
			minmaxvalue(a,n-1,max,min);
		}
	}
*/

//递归程序的转换
/*
	int ack(int m,n)
	{
		if(m==0) return n+1;
		else if(m!=0&&n=0) return ack(m-1,1);
		else return ack(m-1,ack(m,m-1));
	}

	int ack(int m,int n)
	{
		int akm[m][n];
		int i,j;
		for(j=0;j<n;++j)
			akm[0][j]=j+1;
		for(i=1;i<m;++i)
		{
			akm[i][0]=akm[i-1][1];
			for(j=1;j<n;++j)
				akm[i][j]=akm[i-1][akm[i][j-1]];
		}
		return akm[m][n];
	}
*/

//根据函数式表达函数，分为递归和非递归版本
//f(m)=1 if m=0;f(m)=mf(m/2) else
/*
void recurse(int m, int &s)
{
	if (m == 0) s = 1;
	else {
		int r;
		recurse(m / 2, r);
		s = m * r;
	}
}

void nonrecure(int m, int &s)
{
	typedef struct {
		int a, b;
	}node;
	node sa[100];
	if (m < 0) return;
	if (m == 0) s = 1;
	else {
		int top = 0;
		while (m)
		{
			top++;
			sa[top].a = m;
			sa[top].b = m / 2;
			m = sa[top].b;
		}
		s = 1;
		while (top)
		{
			s = s * sa[top--].a;
		}
	}
}
*/

//s[1...n]中n个元素的全排列
/*
void Permute(int s[], int j, int n)
{
	int i, temp;
	if (j == n - 1)
	{
		for (i = 0;i < n;++i)
			cout << s[i];
		cout << endl;
	}
	else
		for (i = j;i < n;++i)
		{
			temp = s[j];s[j] = s[i];s[i] = temp;
			Permute(s, j + 1, n);
			temp = s[j];s[j] = s[i];s[i] = temp;
		}
}
*/

//只用一个指针完成队列的实现，要求入队出队操作的时间复杂度为O（1）
//带头节点的带尾指针的循环链表
/*
入队：
	s=new lnode;
	s->data=x;s->next=p->next;p->next=s;
	p=s;

出队：
	if(p->next==p) {cout<<"队空"<<endl;}
	s=p->next->next;p->next->next=s->next;
	cout<<"出队元素是"<<s->data<<endl;
	if(s==p) p=p->next;
	delete(s);
*/