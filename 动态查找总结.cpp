//统计大于等于x的数目
/*
	#define n
	int uprx(int a[n],int x)
	{
		int head=1,mid,rear=n-1;
		do{
			mid=(head+rear)/2;
			if(x<=a[mid]) head=mid+1;
			else rear=mid-1;
		}while(head<=rear)
		if(a[head]<x) return head-1;
		return head;
	}

*/

//在数组的前n个元素中找到第k小的值
/*
	#define maxn 100
	int a[maxn],n,k;
	int search(int a[],int n,int k)
	{
		int low,high,i,j,m,t;
		k--;low=0;j=n-1;
		do{
			t=a[low];i=low;j=high;
			do{
				while(i<j&&t<a[j]) j--;
				if(i<j) a[i++]=a[j];
				while(i<j&&t>=a[j]) i++;
				if(i<j) a[j--]=a[i];
			}while(i<j);
			a[i]=t;
			if(i!=k)
				if(i<k)
					low=i+1;
				else
					high=i-1;
		}while(i!=k)
		return a[k];
	}

*/

//折半查找保持表的有序性
/*
	int bininsert(sqllist r,int x,int n)
	{
		int low=1,high=n,mid,flag=1,pos,i);
		while(low<=high)
		{
			mid=(low+high)/2;
			if(x<r[mid].key) high=mid-1;
			else if(x>r[mid].key) low=mid+1;
			else flag=0;
		}
		if(!flag) pos=mid;
		else flag=low;
		for(i=n;i>=pos;--i)
			r[i+1]=r[i];
		r[pos].key=x;
	}


*/

//非空查找树，在树中查找值为k的节点，若值为k的节点在树中，且是叶子节点，则删除叶子节点，同时success=1；若值为k的节点不在树中，或虽然在树中但不是叶子节点，则不删除，success=0
/*
	typedef struct node{
		int key;
		struct node *left,*right;
	}node;
	node *root;int k,success;
	void del_leaf(node **t,int k,int *sn)
	{
		node *p,*pf;p=*t;*sn=0;
		while(p&&!*sn)
			if(k==p->key) *sn=1;
			else{
				pf=p;
				if(k<p->key) p=p->left;else p=p->right;
			}
		if(*sn&&p->left==null&&p->right==null)
		{
			if(p!=*t)
				if(pf->left==p) pf->left=null;else pf->right=null;
			else *t=0;
			free(p)
		}
		else *sn=0;
	}
			
*/

//二叉排序树的删除
/*
	void deletep(bstree &root,bstree p)//p指向某个非叶子节点，删除p所指节点
	{
		if(p->lch)
		{
			s=p->lch;pre=p;
			while(s->rch){pre=s;s=s->rch;}
			p->data=s->data;
			if(pre==p) p->lch=s->lch;else pre->rch=s->lch;
		}
		else 
		{
			s=p->rch;pre=p;
			while(s->lch){pre=s;s=s->lch;}
			p->data=s->data;
			if(pre==p) p->rch=s->rch;else pre->lch=s->rch;
		}
	}
			

*/

//将以值为a的节点为根的子树删去
/*
	void free_tree(node *T)
	{
		if(T)
		{
			free_tree(T->left);
			free_tree(T->right);
			free(T);
		}
	}
	node *delete_subtree(node *t,int a)
	{
		node *p=null,*q=t;
		while(q&&q->data!=a)
		{
			p=q;
			if(a<q->data) q=q->left;else q=q->right;
		}
		if(q!=null)
		{
			free_tree(q);
			if(p==null) t=null;else if(a<p->data) p->left=null;else p->right=null;
		}
		return t;
	}
*/

/*
	void test1(int item,list_pointer ht[])
	{
		int hash_value=hash(item.key);
		list_pointer ptr,trail=null,lead=ht[hash_value];
		for(;lead;trail=lead,lead=lead->link)
		{
			if(!strcmp(lead->item.key,item.key))
			{
				fprintf(stderr,"the key is in the table\n");
				exit(1);
			}
		}
		ptr=(list_pointer)malloc(sizeof(list));
		ptr->item=item;ptr->link=null;
		if(trail) trail->link=ptr;else ht[hash_value]=ptr;

*/

//从哈希表将某个数据删去
/*
	int delete(int h[n],int k)
	{
		i=k%7;
		if(h[i]==maxint)
		{
			cout<<"无关键字"<<k<<endl;
			return 0;
		}
		if(h[i]==k)
		{
			h[i]==-maxint;
			return  1;
		}
		else
		{
			j=i;
			for(d=1;d<=n-1;++d)
			{
				i=(j+d)%n;//n为表长
				if(h[i]==maxint) return 0;
				if(h[i]==k){
					h[i]=-maxint;
					return 1;
				}
			}
		}
		cout<<"无关键字"<<k<<endl;
		return 0;
	}

*/

//长度为n的顺序表a中每一个数据元素均为整型，查找元素值为item的数据的递归
/*
	int search(int a[],int item,int i)//初始调用时n=n-1
	{
		if(i<0) return -1;
		else if(a[i]==item) return i+1;
		else return search(a,item,i-1);
	}
*/

//顺序遍历有序（递增）表查找失败的平均长度为（n+2）/2，失败位置除小于每一个之外，还存在大于最后一个

//某个任务的数据模型可以抽象为给定的k个集合：s1...sn，其中si的元素不定，在处理数据过程中将会涉及元素的查找和新元素的插入两种操作，查找和插入时用一个二元组（i，x）来规定一个元素i，i是集合的序号，x是元素值。
/*
	//设计数据结构来存储n个集合，高效完成插入和删除
	//在建立数据顺序表的同时建立索引表。数据表按k个集合分块，索引表中有两个域，一是各集合最后一个元素在数据表的位置（下标），二是集合的个数。
	//实现数据运算时，根据给定二元组（i，x），首先在索引表中找到集合i的位置，然后在数据表中查找，查到返回x在数据表的位置，否则查找失败。若要插入则将数据表中的数据后移，插入x，同时修改索引表
	if(i==1) first=0;//要求在第i个集合中插入数据
	else first=id.a[i-1]+1;//first指向第i个集合的首地址
	last=id.a[i];
	for(j=first;j<=last;++j)
	{
		if(r[j]==x) return j;//查找成功
	}
	for(j=id.a[id.k];j>id.a[i];--j)
	{
		r[j+1]=r[j];
	}
	r[j+1]=x;
	for(j=i;j<=k;++j) id.a[j]++;//更新索引表
*/

//找出n个数的最大值和最小值，要求元素比较次数为3n/2（向上取整）-2
//先将数据分成大者段和小者段，再对两端分别使用选择排序，选出最大值和最小值

//判断二叉树是否为二叉排序树
/*
	//中序遍历为增序，在遍历中将当前遍历节点与其前驱节点比较。
	void judge(bstree t,int& flag)
	{
		if(t!=null&&flag)
		{
			judge(t->left,flag);
			if(pre==null) pre=t;
			else if(pre->data<t->data) pre=t;
			else flag=0;
			judge(t->right,flag);
		}
	}
	
	//定义
	int judge(bstree t)
	{
		if(t==null) return true;
		if(judge(t->left)&&judge(t->right))
		{
			m=max(t->left);n=min(t->right);
			return (t->data>m&&t->data<n);
		}
		else
			return false;
	}
	int max(bstree p)
	{
		if(p==null) return -maxint;
		else
		{
			while(p->right)
				p=p->right;
			return p->data;
		}
	}
*/

/*
	bstree bst_search(bstree bst,f,int k,int &flag)//在二叉排序树中查找值为k的节点，返回父节点
	{
		if(!bst)
		{
			tag=0;
			return f;
		}
		else if(bst->key==k)
		{
			tag=1;
			return bst;
		}
		else if(bst->key>k)
		{
			f=bst;return bst_search(bst->left,f,k,tag);
		}
		else 
		{
			f=bst;return bst_search(bst->right,f,k,tag);
		}
	}
	//插入
	for(i=1;i<=n;++i)
	{
		f=bst_search(t,f,k[i],flag);
		if(tag==1) tag=0;
		else{
			s=new node();
			s->key=k[i];
			s->left=null;
			s->right=null;
			if(f==null) t=s;
			else if(s->key<f->key) f->left=s;
			else f->right=s;
		}
	}

*/

//二叉排序树的删除
/*
	while(p&&p->key!=x)
		if(p->key>x){ f=p;p=p->left;}
		else {f=p;p=p->right;}
	if(p==null)
		cout<<"无关键字为x的节点"<<endl;
	if(p->left==null)
		if(f->left==p) f->left=p->right;
		else f->right=p->right;
	else
	{
		q=p;s=p->left;
		while(s->right)
		{
			q=s;
			s=s->right;
		}
		p->key=s->key;
		if(q==p) p->left=s->left;
		else q->right=s->left;
		delete(s);
	}

*/

//bst递减排序遍历，输出左子树非空，右子树空的节点数值
/*
	void dec(bstree t)
	{
		if(t)
		{
			dec(t->right);
			if(!t->left&&t->right) cout<<t->data;
			dec(t->left);
		}
	}

*/

/*
	bstree findpre(t,pre,k)//pre初值为null
	{
		if(t->data=k) return pre;
		else if(t->data<k) return findpre(t->right,t,k);
		else return findpre(t->left,t,k);
	}

*/

//根据平衡因子求平衡树的高度
/*
	//根节点的层次为1，每下一层层次+1，直到层次最大的叶子节点，当b=-1时向右子树找，当b=1时向左子树找
	if(!bst) return 0;
	else if(bst->bt==1||bst->bt==0)
		return 1+height(bst->left);
	else 
		return 1+height(bst->right);
	
	while(p)
	{
		level++;
		if(p->bf<0) p=p->right;
		else p=p->left;
	}
*/

//判断二叉树的查找序列
/*
	low=prelow=-maxint;high=prehigh=maxint;
	while(low<high&&i<n)//n为数据个数，i=0
	{
		while(a[i]>low&&i<n)
		{
			prelow=low;low=a[i++];
		}
		if(i<n)
		{
			prehigh=low;low=prelow;high=a[i++];
		}
		while(a[i]<high&&i<n)
		{
			prehigh=high;high=a[i++];
		}
		if(i<n)
		{
			prelow=high;high=prehigh;low=a[i++];
		}
	}
	return low<high;
*/

//链地址删除数据
/*
	i=h(k);
	if(ht[i]==null) cout<<"无关键字";
	else
	{
		p=ht[i];q=p;
		while(p&&p->key!=k){q=p;p=p->next;}
		if(p!=null)
			if(q==p){ht[i]=ht[i].next;delete(p);}
			else{q->next=p->next;delete(p);}
		else
			cout<<"无关键字";
	}

*/

//链地址计算比较次数
/*
	for(i=1;i<=n;++I)
	{
		p=h[i];j=1;
		while(p){j++;p=p->next;}
		count+=j;
	}
	return count/26;

*/

//哈希查找
/*
	i=h(key);
	if(ht[i]==empty) return false;
	else if(ht[i]=key) return true;
	else
	{
		j=(i+1)%m;
		while(j!=i)
		{
			if(ht[j]==key) return 1;
			else if(ht[j]==empty) return false;
			j=(j+1)%m;
		}
		return false;
	}
*/

/*
	//返回x所指的节点在中序遍历中的次序，size为x的子树的节点总数
	if(x->left) r=x->left->size+1;else r=1;//初始时若x的左子树为空，r=1
	p=x;//p要上溯到根节点
	while(p!=t)//t为根节点
	{
		if(p==p->parents->right)
		{
			if(p->parents->left==null) r++;
			else r=r+p->parent->left->size+1;
		}
		p=p->parents;
	}

	//另一种算法是从根往下找
	if(t->left) r=t->left->size+1;else r=1;
	while(t)
		if(t->key>x->key)
		{
			t=t->left;
			if(t){
				if(t->right)
					r=r-t->right->size-1;
				else
					r=r-1;
			}
		}
		if(t->key<x->key)
		{
			t=t->right;
			if(t)
			{
				if(t->left)
					r=r+t->left->size+1;
				else 
					r=r+1;
			}
		}
		else return r;

*/