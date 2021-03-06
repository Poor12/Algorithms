//树与二叉树总结
//将bt中每一个节点的左右子树互换
/*
	typedef struct node
	{
		int data;
		struct node *left,*right;
	}btnode;
	void exchange(btnode *bt)
	{
		btnode *p,*q;
		queue Q;
		if(bt)
		{
			add(Q,bt);
			while(!empty(Q))
			{
				p=delq(Q);
				if(p->lchild) add(Q,p->lchild);
				if(p->rchild) add(Q,p->rchild);
				q=p->rchild;
				p->rchild=p->lchild;
				p->lchild=q;
			}
		}
	}
*/

//求二叉树的高度
/*
	height(p)
	{
		if(p)
		{
			if(p->left==null) lh=0;else lh=height(p->left);
			if(p->right==null) rh=0;else rh=height(p->right);
			if(lh>rh) hi=lh+1;else hi=rh+1;
		}
		else hi=0;
		return hi;
	}
*/

//将二叉树中左右孩子交换，采用非递归的方式，设立一个堆栈存放还没有转换过的节点，它的栈顶指针为up
//交换算法：1.把根节点放入堆栈。2.堆栈不空时取出栈顶元素，交换左右子树，并把它的左右子树分别入栈。3.重复直到栈空
/*
	typedef struct node *tree;
	struct node{
		int data;
		tree lchild;
		tree rchild;
	}
	exchange(t)
	{
		tree r,p;
		tree stack[500];
		int tp=0;
		stack[tp]=t;
		while(tp>=0)
		{
			p=stack[tp--];
			if(p)
			{
				r=p->lchild;
				p->lchild=p->rchild;
				p->rchild=r;
				stack[++tp]=p->lchild;
				stack[++tp]=p->rchild;
			}
		}
	}
	
*/

//二叉树存储广义表
/*
	具体规定：
	（1）树的根节点作为由子树构成的表的表名放在表的最前面
	（2）每个节点的左子树和右子树用逗号隔开，若仅有右子树没有左子树，逗号不能省略
	（3）整个广义表输入#表示结束
	基本思路：
		依次从保存广义表的字符串ls中输入每个字符。若遇到的是字母，则表示是节点的值，应为它建立一个新的节点，并把该节点作为左子女（k=1）或右子女（k=2）链接到双亲节点上，若遇到左括号则表明子表的开始，遇到右括号表明子表结束，遇到逗号，表示以左子女为根的子树处理完毕，接着处理以右子女为根的子树，将k=2.
		算法使用一个栈s，在进入子表之前，将根节点指针进栈，以便括号内的子女链接使用。
	如：A（B（D，E(G)),C(,F))
	void createbintree(node *&bt,char ls)
	{
		stack<node*> s;
		makeempty(s);
		bt=null;//置空二叉树
		node *p;
		int k;istream ins(ls);//把串ls定义为输入字符流对象ls
		char ch;
		ins>>ch;//依次读入字符
		while(ch!='#')
		{
			switch(ch){
				case '(':push(s,p);k=1;break;
				case ')':pop(s);break;
				case ',':k=2;break;
				default:
					p=new node();
					p->data=ch;
					p->leftchild=null;
					p->rightchild=null;
					if(bt==null)
						bt=p;
					else if(k==1)
						top(s)->leftchild=p;
					else
						top(s)->rightchild=p;
			}
		}
		ins>>ch;
	}
	
*/

//中序非递归
/*
	status inorder(bitree t)
	{
		initstack(s);
		push(s,t);
		while(!s.empty())
		{
			while(gettop(s,p)&&p)
				push(s,p->left);
			pop(s,p);
			if(!s.empty())
			{
				pop(s,p);
				printf(p->data);
				push(s,p->right);
			}
		}
	}

*/

//先序非递归(仅先序）
/*
	void example(b)
	{
		btree *stack[20],*p;
		int top;
		if(b!=null)
		{
			top=1;stack[top]=b;
			while(top>0)
			{
				p=stack[top];top--;
				printf("%d",p->data);
				if(p->right)
					stack[++top]=p->right;
				if(p->left)
					stack[++top]=p->left;
			}
		}
	}

	while(bt!=null||top>0)
	{
		while(bt!=null)
		{
			cout<<bt->data;
			if(bt->right) s[++top]=bt->right;
			bt=bt->left;
		}
		if(top>0) bt=s[top--];
	}

*/

//前序和中序确定一棵二叉树，并打印后序遍历序列
/*
	#define max 100
	typedef struct node{
		char info;
		struct node *left;
		struct node *right;
	}
	char pred[max],inod[max];
	int main(int argc,int **argv)
	{
		node *root;
		if(argc<3) exit 0;
		strcpy(pred,argc[1]);
		strcpy(inod,argv[2]);
		root=restore(pred,inod,strlen(pred));
		postorder(root);
	}
	node *restore(char *ppos,char *ipos,int n)
	{
		node *ptr;char *rpos;int k;
		if(n<=0) return null;
		ptr->info=*ppos;//根节点
		for(rpos=ipos;rpos<ipos+n;rpos++)
			if(*rpos==*ppos) break;
		k=rpos-ipos;
		ptr->left=restore(ppos+1,ipos,k);
		ptr->right=restore(ppos+1+k,rpos+1,n-1-k);
		return ptr;
	}
		
*/

//建立二叉树，并求其宽度，输出4
/*
	typedef struct node
	{
		char data;
		struct node *lch,*rch;
	}*tree;
	struct chtp
	{
		int len;char ch[100];
	}s;
	struct queue
	{
		struct node *elem[100];
		int front;
		int rear;
	}q;
	node *bt;int ii=0;
	void crt_pre(tree *t)
	{
		char c;
		c=s.ch[ii];
		ii++;
		if(c=='.') *t=0;
		else{
			*t=(node *)malloc(sizeof(node));
			(*t)->data=c;
			crt_pre(&(*t)->lch);
			crt_pre(&(*t)->rch);
		}
	}
	int unknown(node *p)
	{
		node *t;int max=0,w=0;q.front=q.rear=0;
		if(p)
		{
			q.elem[q.rear++]=p;
			q.elem[q.rear++]=0;
			while(q.front!=q.rear)
			{
				t=q.elem[q.front++];
				if(t)
				{
					w++;
					if(t->lch)
						q.elem[q.rear++]=t->lch;
					if(t->rch)
						q.elem[q.rear++]=t->rch;
				}
				else
				{
					if(q.front!=q.rear)
						q.elem[q.rear++]=0;
					if(w>max) max=w;
					w=0;
				}
			}
		}
		return max;
	}
	main()
	{
		char c[]={"abd..eh...cf.i..g..!"};
		int i=0,num;
		for(i=0,s.len=0;c[i]!='!';++i,s.len++)
			s.ch[i]=c[i];
		crt_pre(&bt);
		num=unknown(bt);
		printf("w=%d",num);
	}
*/

//后序线索树的遍历算法，1为线索，0为子树
/*
	prior(node,x)
	{
		if(node!=null)
			if(node->rflag==0)
				*x=node->right;
			else
				*x=node->left;
	}
	next(bt,node,x)//bt为树根
	{
		*x=bt;
		if(node!=bt&&node!=null)
			if(node->rflag)
				*x=node->right;
			else{
				do{
					t=*x;
					prior(t,x);
				}while(*x!=node);
				*x=t;
			}
	}
*/

//求出以T为根的二叉树或子树的节点个数
/*
	int size(struct node *T)
	{
		if(!T)
			return 0;
		else
			return 1+size(T->left)+size(T->right);
	}
*/

//树以孩子兄弟表示法存储，计算并返回根为r的树中叶子节点的个数
/*
	typedef struct node
	{
		node *firstchild,*nextbrother;
	}
	int numberofleaf(node *r)
	{
		int num=0;
		if(r==null)
			num=0;
		else if(r->firstchild==null)
			num=1+numberofleaf(r->nextbrother);
		else
			num=numberofleaf(r->firstchild)+numberofleaf(r->nextbrother);
		return num;
	}
				
*/

//将二叉树的叶子节点按从左到右的顺序练成一个带头节点的双向循环链表
/*
	void leafchain(bitree &bt)
	{
		p=(bitree)malloc(sizeof(binode));
		if(!p)
		{
			printf("overflow\n");
		}
		head=p;top=1;
		if(bt)
		{
			top++;stack[top]=bt;
			while(top)
			{
				t=stack[top--];
				if(!t->left&&!t->right)
				{
					p->next=t;
					t->pre=p;
					p=t;
				}
				else
				{
					if(t->right)
					{
						top++;
						stack[top]=t->right;
					}
					if(t->left)
					{
						top++;
						stack[top]=t->left;
					}
				}
			}
			p->next=head;
			head->pre=p;
		}
*/

//设有一棵算术表达式，如何对表达式求值
//1.进行后序遍历，求得后缀表达式
//2.先递归求左子树表达式的值，再递归求右子树表达式的值，根据根的符号求解

//后缀表达式转换成二叉树的规则：
//从左到右读入后缀表达式，遇操作数就入栈，遇操作符就将该操作符当作当前的根节点，并从栈中弹出两个操作数，后弹出的是第一操作数作左子树，先弹出的作右子树，之后就根节点入栈，继续读后缀表达式

//树的广义表表示法：
//树是一个广义表，若括号内无元素，则为空树；若广义表是非空表，则表内第一个元素是树根；第一个元素后是表，若表内为空，则无子树；否则高层以逗号为分隔的是互为兄弟的子树，对每棵子树进行分解最后得到广义表对应的子树

//任意一个有n个节点的二叉树，已知它有m个叶子节点，则非叶子节点有（m-1）个度为2，其余度为1

//一棵高度为h的满二叉树：根节点所在层次为0；第h层上的节点都是叶子节点；其余各层每个节点都有k棵非空子树，如果按层次自顶向下，同一层自左向右进行编号：
//1.编号为i的节点的双亲结点的编号：因为该树每层上均有k^h（h为层数）个节点，则节点i的从右向左数第二个孩子的编号为kh，设n为节点i的子女，关系式（i-1)k+2<=n<=iK+1成立，所以节点i的第m个孩子的编号为int（（i-2）/k+2)+1
//2.节点i的前一节点的编号为i-1，节点i的第m个孩子的编号为（i-1）*k+1+m
//3.节点i有右兄弟的条件是它不是双亲的从右数的第一个节点，即（i-1）%k！=0，右兄弟的编号为i+1

//a[1...n]是一棵顺序存储的完全二叉树，如何求出i与j的公共祖先
/*
	while(i!=j)
	{
		if(i>j)
			i/=2;
		else
			j=j/2;
	}
	公共祖先为i
*/

//对于一棵含有n个节点的k叉树，最大可能高度和最小可能高度
//最大高度为k，设最小高度为h，第i层的节点数k^(i-1),则（K^(h-1)-1)/(k-1)<n<=(k^(h)-1)/(k-1)

//设T是具有n个内节点的扩充二叉树，I是它的内路径长度，E是它的外路径长度
//1.证明En=In+2n
/*
	设n=1，则e=0+2*1=2（只有根节点时有两个外部节点）
	设有n个节点时，公式成立
	证n+1时也成立
	增加一个内部节点，设路径长度为l，则I（n+1）=In+l
	该内部节点其实就是从一个外部节点变来的，这时相当于也增加了一个外部节点（原外部节点变成内部节点时，增加两个外部节点），则E（n+1）=En+1+2
	则推导出E（n+1）=I(n+1)+2（n+1）
*/
//2.成功查找的平均比较次数s=I/n 不成功查找的平均比较次数u=（E-n）/（n+1）=（I+n）/n+1

//入栈序列为1.2...n相当于前序遍历序列是1，2，3..n，出栈序列就是该前序遍历对应的二叉树的中序序列

//任何节点只有左子树的一棵树和任何节点只有右子树的二叉树前序和后序遍历相同，却是不同的二叉树

//三种二叉树的遍历的差别就是访问根的时机不同，二叉树是递归定义的，对左右子树都是按左右顺序来遍历的，所以叶子节点的相对位置不变

//森林的带右链的前序表示法。在前序序列中，任何节点的子树的所有节点都直接跟在该节点之后；每棵子树的所有节点聚集在一起，中间不会插入其他节点；任何分支节点后面跟的是它的第一个子女。故节点可采用如下结构（ltag，data，rlink）
//ltag为左标记，1表示该节点无子女或二叉树无左子女，0表示其后存储其第一子女或二叉树的左子女；rlink指向下一兄弟

//树的带度数的后根次序表示法。在后序序列中，任何子树的节点聚在一起，根节点在最后，节点结构为（data，degree）
//后根次序序列中任何一棵子树的节点个数减边数为1，设某节点的度degree=m，即该节点有m个子女，最右边的子女就是该节点的前驱。最后的第2个子女是最右子女为根的子树的前驱，以节点x为根的前驱求法如下：
//令q=0，从x开始往前走，每经过一个节点z，作q=q+1-degree（z），到q=1时再往前一个节点就是前驱

//扩充二叉树的一种遍历序列能唯一确定一棵二叉树

//返回后序遍历的第一个节点，即最左下的叶子节点
/*
	if(p!=null)
	{
		while(p->left!=null||p->right!=null)
		{
			while(p->left) p=p->left;
			if(p->right) p=p->right;
		}
	}
	return p;
*/

//中序遍历，消除尾递归
/*
	inorder(node)
	{
		if(node)
		{
			inorder(node->left);
			printf(node->data);
			node=node->right;
			while(node->right!=null)
			{
				inorder(node->left);
				printf(node->data);
				node=node->right;
			}
		}
	}
*/

//森林中有n个节点，b条边，则森林中有n-b棵树，森林的n个节点可看作n个连通分量，加入一条边将减少一个连通分量，因为树可以定义为无环图，故加入b条边将减少b个连通分量

//构造最优k叉树，设m为叶子节点，若（m - 1）%（k - 1）！ = 0，要增加虚节点。第一次构造用（m - 1）%（k - 1） + 1个节点，之后都用k个节点构造k叉树

//设计求wql的算法
/*
	typedef struct node
	{
		int weight;//节点权
		node *left;
		node *right;
	}*tree;
	int wpl=0;
	void inorder(tree bt,int lv)
	{
		if(bt)
		{
			inorder(bt->left,lv+1);
			if(bt->left==null&&bt->right==null)//找到叶子节点
			{
				wpl+=bt->weight*(lv-1);
			}
			inorder(bt->right,lv+1);
		}
	}
*/

//假设一个仅包含二元运算符的算术表达式以链表形式存储于bt上，计算表达式的值
/*
	重新定义二叉树的节点结构为（left，right，val，right），其中left和right是左右子树的指针，data是字符，val是子表达式的值。采用后序遍历，先分别计算左右子树的子表达式值再最后计算表达式的最后结果
	int posteval(bitree bt)
	{
		bitree p=bt;int lv,rv;
		if(p)
		{
			lv=posteval(p->left);
			rv=posteval(p->right);
			if(!p->left&&!p->right)
				p->val=p->data-'0';
			else
			{
				switch(p->data)
				{
					case '+':p->val=p->left->val+p->right->val;
					case '-':p->val=p->left->val-p->right->val;
					case '*':p->val=p->left->val*p->right->val;
					case '/':p->val=p->left->val/p->right->val;
				}
			}
			return p->val;
		}
	}
	//若是多位数要做如下修改：在建立二叉树时进行拼数，一个数输入完毕再存入二叉树节点
	case '0'<=x<='9':
		while((x>='0'&&x<='9')||x=='.')
			if(x!='.')
			{
				num=num*10+(ord(x)-ord('0'));//num初始化为0.0
				cin>>x;
			}
			else
			{
				scale=10.0;cin>>x;
				while(x>='0'&&x<='9')
				{
					num=num+(ord(x)-ord('0'))/scale;
					scale=scale*10;
					cin>>x;
				}
			}
*/

//用二叉树表示算术表达式，中缀表达式与中序遍历基本相同，差别仅在于二叉树删除了括号
/*
	结构同上：
		if(bt)
		{
			if(bt->left)
			{
				bracket=precede(bt->data,bt->left->data);//precede比较优先级
				if(bracket==1) printf('(');
				inorderexp(bt->left);
				if(bracket==1) printf('(');
			}
			printf(bt->data);
			if(bt->right)
			{
				bracket=precede(bt->data,bt->right->data);//precede比较优先级
				if(bracket==1) printf('(');
				inorderexp(bt->right);
				if(bracket==1) printf('(');
			}
		}

*/

//节点计数可在遍历中进行，度数为2的节点即既有左子女又有右子女的节点，叶节点即两者都没有的节点

//二叉树存在bt[0..2^h-2]的数组中，求叶子节点的个数
/*
	设没有存放节点（虚节点）对应的位置为负数
	for(i=0;i<n;++i)
	{
		if(i<n/2)
		{
			if(bt[2*i+1]<0&&bt[2*i+2]<0)
				num++;
		}
		else if(bt[i]>0)
			num++;
	}
*/

//假定用两个一维数组l[n]和r[n]作为二叉树的存储结构，l[i]和r[i]分别表示节点i的左子女和右子女，为0表示为空，确立t[n]使t[n]存放节点i的父亲
/*
	for(i=1;i<n;++i) t[i]=0;
	for(i=1;i<n;++i)
		if(l[i])
			t[l[i]]=i;
		if(r[i])
			t[r[i]]=i;
	//判断u是否为v的后代
	int parent=u;
	while(parent!=v&&parent!=0) parent=t[parent];
	if(parent==v)
		cout<<"yes";
	else
		cout<<"no";
*/

//判断二叉树是否是完全二叉树，利用完全二叉树若某节点无左子女就不应该有右子女的原则判断。
//注意：左子树和右子树都是完全二叉树不能推出整棵树都是完全二叉树
/*
	if(p==null) return 1;
	queueinit(Q);queuein(Q,p);//初始化队列，根节点入队
	while(!queueempty(Q))
	{
		p=queueout(Q);
		if(p->left&&!tag) queuein(Q,p->left);//tag初始化为0
		else if(p->left) return 0;
		else tag=1;//首次出现节点为空
		if(p->right&&!tag) queuein(Q,p->right);//tag初始化为0
		else if(p->right) return 0;
		else tag=1;//首次出现节点为空
	}
*/

//一维数组a[1...n]的完全二叉树建立二叉链表
/*
	bitree creat(int a[],int i)
	{
		bitree tree;
		if(i<=n)
		{
			tree=new node();
			tree->data=a[i];
			if(2*i>n) tree->left=null;
			else tree->left=creat(a,2*i);
			if(2*i+1>n) tree->right=null;
			else tree->right=creat(a,2*i+1);
		}
		return tree;
	}
	//非递归实现，借助栈，元素结构是（int num,bitree),初始时调用num=1，设n=2^h-1
	top=1;S[1]={1,bt};
	while(i<=n&&top>0)
	{
		j=s[top].num;
		t=s[top--].bt;
		if(btt[j]!='#')
		{
			bt=new node();
			bt->data[i]=btt[j];
			if(btt[j*2+1]!='#')
				s[++top]={j*2+1,bt->right};
			if(btt[j*2]!='#')
				s[++top]={j*2,bt->left};
			i=2*j;
		}
	}

	//二叉链表->数组
	if(bt)
	{
		a[i]=bt->data;//初始时i=1
		if(bt->left) creat(a,2*i,bt->left);
		if(bt->right) creat(a,2*i+1,bt->right);
	}
*/

//动态二叉链表转换成静态二叉链表
//静态二叉链表中节点是按动态二叉链表的前序遍历存放的，首先对动态二叉链表进行前序遍历，填写静态链表下标和data；再对动态二叉链表的二叉树进行层次遍历，设队列q，填写静态链表的left与right
//建立下标与节点的索引关系

//双亲表示法中求树的深度,对每一节点求层次，最大的节点层次即为深度
/*
	int maxdepth=0;
	for(i=1;i<=t.n;++i)
	{
		temp=0;
		f=i;
		while(f>0)
		{
			temp++;
			f=t.nodes[f].parent;
		}
		if(temp>maxdepth)
			maxdepth=temp;
	}
*/

//求二叉树的最大宽度，宽度是二叉树各层上具有节点最多的那一层的节点总数
/*
	q[rear]=bt;//根节点入队
	while(front<=last)//front，rear初始值为1，last同层最右节点在队列中的位置，last初值为1
	{
		p=q[front++];temp++;//同层元素数+1，temp表示当前层宽度
		if(p->left!=null) q[++rear]=p->left;
		if(p->right!=null) q[++rear]=p->right;
		if(front>last)//一层结束
		{
			last=rear;//last指向下一层的最右位置
			if(temp>maxw) maxw=temp;//更新最大宽度
			temp=0;//准备下层
		}
	}
*/

//以孩子兄弟链表为存储结构，求树的深度
/*
	//递归
	if(bt==null) return 0;
	else if(!bt->firstchild) return max(1,height(bt->nextsibling);
	else 
	{
		hc=height(bt->firstchild)+1;
		hs=height(bt->nextsibling);
		if(hc>hs)
			return hc+1;
		else return hs;
	}

	//非递归
	q[rear]=t;
	while(front<=last)
	{
		t=q[front++];
		while(t!=null)
		{
			if(t->firstchild) q[++rear]=t->firstchild;
			else t=t->nextsibling;
		}
		if(front>last)
		{
			h++;last=rear;//初始深度为0
		}
	}
*/

//二叉链表存储的二叉树上找节点的所有祖先，某两个节点的最近公共祖先，从根节点到某节点的路径，根节点到每个叶子节点以及最远叶子的路径等采用后序非递归遍历
//后序遍历最后访问根节点，当访问到某节点时，栈中所有元素均为该节点的祖先
//例：找p和q的最近共同祖先节点r，设p在q的左边，后序遍历必先遍历到节点p，栈中元素均为p的祖先。将栈复制到另一个辅助栈，再继续遍历到节点q时，将栈中元素从栈顶开始逐个到辅助栈匹配，第一个匹配的就是最近公共节点
/*
	while(bt!=null||top>0)//top 初始为0
	{
		while(bt!=null&&bt!=p&&bt!=q)//节点入栈
		{
			s[++top].t=bt;
			s[top].tag=0;
			bt=bt->left;
		}
		if(bt==p)//假定p在q的左侧，遇节点p时，栈中元素均为p的祖先
		{
			for(i=1;i<=top;++i)
				s1[i]=s[i];//转入辅助栈
			top1=top;
		}
		if(bt==q)
		{
			for(i=top;i>0;--i)
			{
				pp=s[i].t;
				for(j=top1;j>0;--j)
				{
					if(s1[j].t==pp}
					{
						cout<<"共同祖先已找到";
						return pp;
					}
				}
			}
		}
		while(top!=0&&s[top].tag==1)
			top--;//退栈
		if(top!=0)
		{
			s[top].tag=1;
			bt=s[top].t->right;//沿右分支向下遍历
		}
	}
	return null;//无公共祖先

	
*/

//完全二叉树的前序非递归遍历
/*
	while(i<=n||top>0)//i=1,top=0
	{
		while(i<=n)
		{
			cout<<bt[i];
			if(2*i+1<=n) s[++top]=2*i+1;
			i=i*2;
		}
		if(top>0) i=s[top--];
	}
*/

//双亲表示法改，节点结构为（data，parent）。对于每个节点，直接给出双亲的下标，用正和负表示该子女是左子女还是右子女，左子女为负，右子女为正，0表示根节点。该类结构不适合直接进行前序遍历，较好的办法是将这类结构转为节点及其左右子女的顺序存储结构
/*
	for(i=1;i<=max;++i)
	{
		bt[i].lc=bt[i].rc=0;
	}
	for(i=1;i<=max;++i)
	{
		bt[i].data=t[i].data;
		if(t[i].parent<0) bt[-t[i].parent].lc=i;
		else if(t[i].parent>0) bt[t[i].parent].
		else root=i;
	}

*/

//二叉树先序遍历最后一个节点的特征：若有右子树，则是右子树中最右下的节点；若无右子树，仅有左子树，则是左子树中最右下的叶子节点，若都没有，返回
/*
	while(p)
		if(p->right) p=p->right;
		else if(p->left) p=p->left;
		else return p;
*/


//顺序存储的二叉树最大序号的叶子节点到祖先节点的路径
/*
	while(bt[c]==0) c--;//过滤虚节点
	f=c/2;
	while(f!=0)
	{
		cout<<bt[f];
		f/=2;
	}

*/

//二叉树不使用堆栈 前序遍历
//增设一个指针域，指向双亲
/*
	while(t)//t是二叉树根节点的指针
	{
		while(t)
		{
			cout<<t->data;
			t->pre=f;//f初值为null
			f=t;t=t->left;
		}
		t=f;
		while(t&&t->right==null) t=t->pre;
		if(t&&t->right)
		{
			f=t->pre;
			t=t->right;
		}
	}

*/
//二叉树非递归中序遍历
/*
	while(p||top>0)
	{
		while(p)
		{
			s[++top]=p;
			p=p->left;
		}
		if(top>0)
		{
			p=s[top--];
			printf(p->data);
			p=p->right;
		}
	}
*/

//二叉树顺序存储的遍历方式与链表方式类似
/*
	void inorder(int i)
	{
		if(i!=0)
		{
			inorder(ar[i].lc);
			cout<<ar[i].data;
			inorder(ar[i].rc);
		}
	}
*/

//二叉树自下而上，自右向左的层次遍历即为一般层次遍历的逆序

//层次遍历二叉树，统计度为1的节点个数
/*
	queueinit(q);queuein(q,bt);
	while(!q.empty())
	{
		p=queueout(q);
		cout<<p->data;
		if((p->left&&!p->right)&&(!p->left&&p->right)) num++;
		if(p->left) queuein(q,p->left);
		if(p->right) queuein(q,p->right);
	}
*/

//交换左右子树，前序和后序遍历均可，中序不行
/*
	void exchange(tree bt)
	{
		if(bt)
		{
			swap(bt->left,bt->right);
			exchange(bt-left);
			exchange(bt->right);
		}
	}
	//非递归，栈与队列均可
	s[++top]=t;//top=0
	while(top>0)
	{
		t=s[top--];
		if(t->left||t->right)
		{
			swap(t->left,t->right);
		}
		if(t->left) s[++top]=t->left;
		if(t->right) s[++top]=t->right;
	}
*/

//满二叉树的后序遍历转换为先序遍历
/*
	//满二叉树的任一节点的左右子树均含有数量相同的节点，据此可将任一遍历序列转换为另一遍历序列
	//设post和pre分别为存放后序序列和先序序列的向量，l1和h1以及l2和h2分别为post和pre初始和最后的下标
	void posttopre(int post[],int pre[],int l1,int h1,int l2,int h2)
	{
		if(h1>=l1)
		{
			pre[l2]=post[h1];
			half=(h1-l1)/2;
			posttopre(post,pre,l1,l1+half-1,l2+1,l2+half);
			posttopre(post,pre,l1+half,h1-1,l2+half+1,h2);
		}
	}
	
*/

//严格二叉树：每个节点，其左右树都为空或者其左右子树都不为空，称为严格二叉树,可用前序与后序遍历推出中序
/*
	void creat(tree *bt,char pre[n],char post[n],int l1,int h1,int l2,int h2)
	{
		tree p=*bt;
		if(l1<=h1)
		{
			p=new node();
			p->data=pre[l1];
			if(l1==h1){p->left=p->right=null;}
			else
			{
				for(int i=l2;i<=h2;++i)//到后序序列找左子树的根
					if(post[i]==pre[l1+1])
						break;
				L=i-l2+1;
				creat(&(p->left),pre,post,l1+1,l1+L-1,l2,i);
				creat(&(p->right),pre,post,l1+L,h1,i+1,h2-1);
			}
		}
	}
*/

//后序遍历非递归
/*
	void postorder(tree t)
	{
		typedef struct node
		{
			tree t;
			int tag;
		}stack;
		stack s[n+1];
		top=0;
		while(t||top!=0)
		{
			while(t)
			{
				s[++top].t=t;
				s[top].tag=0;
				t=t->left;
			}
			while(top&&s[top].tag==1)//左右子树均访问
			{
				cout<<s[top--].t->data;
			}
			if(top)//右分支
			{
				s[top].tag=1;
				t=s[top].t->right;
			}
		}
	}

*/

//已知一棵度为12的树，它的根节点的地址为root，前序非递归遍历
/*
	struct node
	{
		int data;
		int son[12];
	}tnode[m];
	//根进栈，如果栈不空，出栈，访问栈顶节点，从12到1的逆序将节点的非空儿子入栈，再重复判断
	//根不进栈，访问进入的节点，从12到2的逆序将节点的非空儿子入栈，节点置为序号为1的子节点，再重复判断

*/

//二叉树计算每层中节点data大于50的节点个数，并输出这些节点的数值
/*
	typedef struct { int level,value,idx;}node;//元素所在层号，值和本层的序号
	int front=1,rear=1,last=1,level=1,i=0,num=0;
	tree q[];q[1]=bt;//入队
	while(front<=last)
	{
		bt=q[front++];
		if(bt->data>50)
		{
			s.level=level;s.value=bt->data;s.idx=++i;a[num]=s;num++;
		}
		if(bt->left) q[++rear]=bt->left;
		if(bt->right) q[++rear]=bt->right;
		if(front>last)
		{
			last=rear;
			level++;
			i=0;
		}
	}

*/

//假设在二叉链表的节点中增设两个域，parent以指示其双亲节点，flag区分在遍历过程中到达该节点时应继续向左或向右或访问节点，后序非递归遍历
/*
	while(p)
	{
		switch(p->flag)
		{
			case 0:if(p->left) p=p->left;flag=1;break;
			case 1:if(p->right) p=p->right;break;
			case 2:printf(p->data);p=p->parent;break;
		}
	}

*/

//前序与中序确定二叉树
/*
	void preincreat(tree root,int pre[],in[],int l1,h1,l2,h2)
	{
		root=new node();
		root->data=pre[l1];
		for(i=l2;i<=h2;++i)
		{
			if(in[i]==pre[l1]) break;
		}
		L=i-l2+1;
		if(i==l2) root->left=null;//没有左子树的情况
		else 
		{
			preincreat(root->left,pre,in,l1+1,l1+L-1,l2,i-1);
		}
		if(i==h2) root->right=null;
		else
		{
			preincreat(root->right,pre,in,l1+L,h1,i+1,h2);
		}
	}
	
*/

//层序和中序确定一棵二叉树
//层序第一个节点是二叉树的根，在中序中根将左右子树分开，但在层序中不能分辨出节点是属于哪个子树。应从层次序列第2个节点起，逐一到二叉树左子树比对，形成左子树的层次遍历序列，同时形成右子树的层次遍历。
/*
	tree creat(int level[],in[],l1,h1,l2,h2)
	{
		bt=new node();
		bt->data=level[l1];
		for(i=l2;i<=h2;++i)
			if(level[l1]==in[i]) break;
		if(i=l2) bt->left=null;
		else{
			int ii=-1;
			for(k=l1+1;k<=h1;++k)
			{
				for(j=l2;j<i;++J)
					if(level[k]==in[j])
						levell[++ii]=level[k];//左子树层次序列，ii初值为-1
			}
			bt->left=creat(levell,in,0,ii,l1,i-1);
		}
		if(i==h2) bt->right=null;
		else
		{
			int ii=-1;
			for(k=l1+1;k<=h1;++k)
			{
				for(j=i+1;j<=h2;++j)
					if(level[k]==in[j])
						levelr[++ii]=level[k];
			}
			bt->right=creat(levelr,in,0,ii,i+1,h2);
		}
		return bt;
	}

*/

//复制二叉树的算法
/*
	tree copy(tree t)
	{
		tree bt;
		if(t==null) bt=null;
		else{
			bt=new node();
			bt->data=t->data;
			bt->left=copy(t->left);
			b->right=copy(t->right);
		}
		return bt;
	}
	//非递归
	queuein(q,(t,bt));
	while(!q.empty())
	{
		(t,bt)=queueout(q);
		bt=new node();
		bt->data=t->data;
		if(t->left) queuein(q,(t->left,bt->left));else bt->left=null;
		if(t->right) queuein(q,(t->right,bt->right));else bt->right=null;
	}
*/

//判断两棵二叉树相似
/*
	if(p==null&&q==null) return 1;
	else if((p&&!q)||(!p&&q)) return 0;
	//else if(p->data!=q->data) return 0;判断相等
	else return similar(p->left,q->left)&&similar(p->right,q->right);
*/

//编写递归算法，依据树的双亲表示法以及根节点写出孩子兄弟链表表示
/*
	cstree cst=new node();
	cst->data=pt.nodes[root].data;//根节点
	cst->firstchild=null;cst->nextsibling=null;firstchild=1;//孩子标记
	for(i=1;i<=pt.n;i++)
	{
		if(pt.nodes[i].parent==root)
		{
			child=ptreetocstree(pt,i);
			if(firstchild)
			{
				cst->firstchild=child;firstchild=0;sibling=cst->firstchild;
			}
			else
			{
				sibling->nextsibling=child;sibling=sibling->next;
			}
		}
	}
	return cst;

*/

//删除每一个以元素值为x的节点为根的子树
//删除左右子树，采用后序遍历，删除值为x的节点意味着将其父节点的左或右指针制空，用层序遍历易找到父节点

//孩子兄弟表达法求树的度，节点和其兄弟的个数是该节点双亲的度
//设节点的度degree，树的度maxdegree，设一队列，将树根入队，重复执行，直至队空：
//出队，沿兄弟链计数兄弟求出该节点双亲的度，计数兄弟的同时将孩子入队，直到兄弟链空，若maxdegree<degree,修改max