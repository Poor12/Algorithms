//链表的算法设计总结
//1.已知一个带头节点的单链表，查找链表中倒数第k个位置
//设指针q指向链表，指针p指向链表第一元素，p向后移动k个节点后p与q相距k。之后同步移动p和q，直到p=null，q指向倒数第k个节点
/*
	while(p&&i<k){
		i++;
		p=p->next;
	}
	if(p==null){
		printf("not exist\n");
		return 0;
	}
	while(p)
	{
		q=q->link;
		p=p->link;
	}
	return 1;
*/

//2.将一维数组循环左移p个位置，要求时空复杂度尽可能高效
//按照下标0到p-1、p到n-1、0到n-1的顺序，将这三段分别逆置
//时间复杂度o(n),空间复杂度o(1)
/*
以逆置0到p-1段为例：
	for(i=0;i<p/2;++i){
		t=r[i];
		r[i]=r[p-1-i];
		r[p-1-i]=t;
	}
*/

//3.用带头节点的单链表表示单词的每个字母，找出共同后缀的起始位置
//找两个单词的共同后缀，应从两个单词的词尾向前找，找到最前边那个相同的字母即可
//因为用单链表存储，若想找到最后字母，需用栈，增加空间复杂度
//因此可以先求出两个链表的长度m和n，让两个链表尾对齐，即长链表将指针移动m-n+1，短链表的指针指向第一个字母，两个链表进行模式匹配：对应字母比较，从开始遇到两个链表相等到表尾对应节点的值都相等
/*
尾对齐后的比较：
while(s)	//长表已移到两个链表尾部对齐的位置
{
	while(s&&s->data!=q->data)
	{
		s=s->next;
		q=q->next;
	}
	p=s;
	while(s&&s->data==q->data)
	{
		s=s->next;
		q=q->next;
	}
}//返回p

*/


//4.将两个递增链表合并为一个递减的链表，要求使用原空间
/*
p=la->next;q=lb->next;
la->next=null;
while(p&&q)
{
	if(p->data<=q->data)	//合并同时逆置
	{
		r=p->next;//将p的后序节点暂存于r
		p->next=la->next;//将p节点链于结果表中，同时逆置
		la->next=p;
		p=r;//恢复p为待比较节点
	}
	else{
		r=q->next;
		q->next=la->next;
		la->next=q;
		q=r;
	}
	if(p) q=p;
	while(q!=null)
	{
		r=q->next;
		q->next=la->next;
		la->next=q;
		q=r;
	}
}
*/

//5.最快速度将两个带头节点的单循环链表合并成一个带头节点的循环单链表
//应找节点个数少的链表查其尾节点，将尾节点插入长链的首节点前，更改长链头节点的指针

//6.顺序结构线性表a与b递增，要求b合并至a中，新表仍递增排列，最大限度避免移动元素
//设两表的长度各为m和n，应从线性表的最后一个元素开始比较，大的放到最终位置
/*
	k=m+n-1;i=m-1;j=n-1;
	while(i>=0&&j>=0)
		if(a[i]>=b[j]) a[k--]=a[i--];
		else a[k--]=b[j--];
	while(j>=0)//如果j还没放完
		a[k--]=b[j--];
*/

//7.长度为n的线性表采用顺序结构，要求删去线性表中所有值为item的数据，且时间复杂度为o(n),空间复杂度为o(1)
//设头尾两个指针i=0，j=n-1，从两端向中间移动
/*
	while(i<j)
	{
		while(i<j&&a[i]!=item) i++;
		while(i<j&&a[j]==item) j--;
		if(i<j) a[i++]=a[j--];//最后线性表的元素个数为j+1
	}

	若题目要求元素间相对顺序不变：
	j=-1;i=0;
	while(i<n)
		if(a[i]==item)
			i++;
		else 
			a[++j]=a[i++];//最后线性表的元素个数为j+1
*/

//8.链表排序问题推荐使用直接插入排序，若无头节点且不得使用链表外的空间要单独处理第一元素；有头节点可将头节点做监视哨，数据域设为最小值，循环链表要保证所有节点正好处理一遍

//9.链表的分解问题
//处理当前节点时，一定要保存后继，以便处理完所有节点，其后继变成当前节点。
//插入方法：尾插法和头插法
//将单链表l1拆成两个链表，其中以l1为头的链表保持原来向后的链接，另一个链表的头为l2，链接方向与l1相反，l1包含原链表的奇数序号，l2包含原链表的偶数序号的节点
/*
int i=0;l2=new (lnode);//i表示节点序号，增加一个表头节点l2
l2->next=null;p=l1->next;pre=l1;//l2偶序号链表，l1奇序号链表
while(p)
{
	i++;
	if(i%2)
	{
		pre->next=p;
		pre=p;
		p=p->next;
	}
	else
	{
		s=p->next;//保存后继
		p->next=l2->next;//头插法
		l2->next=p;
		p=s;
	}
}
pre->next=null;
*/

//10.寻找链表中的特殊节点
//例：将最小值节点移到最前面
/*
p=list->link;pre=list;
q=p;
while(p->link)
{
	if(p->link->data<q->data)
	{
		pre=p;
		q=p->link;
	}
	p=p->link;
}
if(q!=list->link)
{
	pre->link=q->link;
	q->link=list->link;
	list->link=q;
}
//双向链表类似
*/

//11.判断链表的中心对称（带头节点的双向链表）
//设p和q分别指向链表的首尾节点，两指针相向移动比较，不等就退出，直到p=q或p->next=q时，对称
/*
	while(p!=q&&p->rlink!=q)
	{
		if(p->data=q->data)
		{
			p=p->rlink;
			q=q->llink;
		}
		else{
			return 0;
		}
	}
	if(p==q)
		return 1;
	else if(p->data==q->data)
		return 1;
	else return 0;
*/

//12.将单循环链表改成双循环链表，初始时pre均为null
/*
	while(la->link->pre==null)
	{
		la->link->pre=la;
		la=la->link;
	}
*/

//13.链表的模式匹配 已知链表a和链表b，判断b是不是a的子序列
//操作从两链表的第一个节点开始，若对应数据相等，则后移指针；若不等则a从上次的后继开始，b仍从第一个节点开始比较，直到b链表尾
/*
//bf算法
	while(p&&q)
	{
		if(p->data==q->data)
		{
			p=p->next;
			q=q->next;
		}
		else
		{
			pre=pre->next;//pre为每趟比较的开始节点
			p=pre;
			q=b;
		}
	}
	if(q==null) return 1;
	else return 0;

//找出链表l2在链表l1中的出现，然后将l1中的l2倒置过来
	while(q&&s)
		if(q->data==s->data)
		{
			q=q->next;s=s->next;
		}
		else
		{
			pre=pre->next;
			q=pre->next;
			s=l2->next;
		}
	}
	if(s==null)//倒置
	{
		r=pre->next;
		pre->next=q;
		while(r!=q)
		{
			s=r->next;
			r->next=pre->next;
			pre->next=r;
			r=s;
		}
	}
	else
		return 0;
*/

//14.线性表的逆置
//顺序表的逆置
/*
	for(i=0;i<=(n-1)/2;++i) swap(a[i],a[n-1-i])
*/
//带头节点的单链表逆置 1.初始化为空链表 2.判断表尾
/*
	while(p!=null)
	{
		r=p->next;
		p->next=head->next;
		head->next=p;
		p=r;
	}

*/
/*
无头节点的逆序
void inverse(&h) {
	if (h ==null) return;
	p = h->next;pr = null;
	while (p!=null)
	{
		h->next = pr;
		pr = h;
		h = p;
		p = p->next;
	}
	h->next = pr;
}

*/
//循环链表的逆置 1.初始化为循环链表 2.判断表尾
/*
	while(p!=la)
	{
		r=p->next;
		p->next=la->next;
		la->next=p;
		p=r;
	}
*/
//逆置输出链表值
/*
	void output(linkedlist list)
	{
		if(list->next) output(list->next);
		cout<<list->data<<endl;
	}
*/

//15.线性表的去重
/*
//有序
while(p)//p指向第二个节点，pre指向第一个节点
{
	if(p->data==pre->data)
	{
		u=p;
		p=p->next;
		delete(u);
	}
	else{
		pre->next=p;
		pre=p;
		p=p->next;
	}
}
pre->next=p;
*/

//无序
/*
while(pre!=null)
{
	m=pre->data;
	q=pre;
	p=pre->next;
	while(p!=null)
		if(p->data==m)
		{
			u=p;
			p=p->next;
			free(u);
		}
		else
		{
			q->next=p;
			q=p;
			p=p->next;
		}
	q->next=p;
	pre=pre->next;
*/

//16.查找节点（单链表），并交换所指节点与后继节点
/*
	pre=head;
	q=head->next;
	while(q!=null&&q!=P)
	{
		pre=q;
		q=q->next;
	}
	if(P->next==null)
	{
		//无后继节点
	}
	else
	{
		pre->next=P->next;
		P->next=P->next->next;
		pre->next->next=P;
	}

*/

//17.建立一个带头节点的线性链表，用以存放二进制数，链表中每个节点的data域存放一个二进制位，实现二进制+1的运算
/*
//用带头节点的双循环链表存储，尾插法建表
la=new (dlnode);la->prior=la->next=null;pre=la;
while((cin>>ch)!='*')
{
	p=new (dlnode);
	p->data=ch;
	p->prior=pre;
	p->next=pre->next;
	pre->next=p;
	la->prior=p;
	pre=p;
}

//二进制运算
p=la->prior;
while(p!=la&&p->data=='1')
{
	p->data='0';
	p=p->prior;
}
if(p!=la) p->data='1';
else
{
	p=new (dlnode);
	p->data='1';
	p->prior=la;
	p->next=la->next;
	la->next->prior=p;
	la->next=p;
}

//输出
while(p!=la)
{
	cout<<p->data<<" ";
	p=p->next;
}
*/

18.//单链表在指针p所指节点之前插入s所指节点
/*
	//只能交换数据
	s->next=p->next;
	p->next=s;
	p->data<-->s->data

*/

//多项式求导
/*
	derivative(ha)
	{
		q=ha;
		pa=ha->next;
		while(pa!=ha)
		{
			if(pa->exp==0)
			{
				q->next=p->next;
				free(pa);
				pa=q;
			}
			else
			{
				pa->coef=pa->coef*pa->exp;
				pa->exp--;
				q=pa;
			}
			pa=pa->next;
		}
	}
*/

/*
	void insertsort(bnodetp *l)//l为头节点
	{
		p=l->next;
		q=p->next;
		r=q->next;
		while(q!=l)
		{
			while(p!=l)&&(p->data>q->data) p=p->prior;
			q->prior->next=r;
			r->prior=q->prior;
			q->next=p->next;
			q->prior=p;
			p->next->prior=q;
			p->next=q;
			q=r;
			p=q->prior;
			r=r->next;
		}
	}

*/

/*
//单循环合并
	node *link(node *head1,*head2)
	{
		node *p,*q;
		p=head1;
		while(p->next!=head1) p=p->next;
		q=head2;
		while(q->next!=head2) q=q->next;
		p->next=head2;
		q->next=head1;
		return head1;
*/

