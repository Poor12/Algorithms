//线索二叉树
typedef enum
{
	SubTree,
	Thread
}Nodeflag;//枚举值子树和线索分别为0，1
//ltag=0,left指向节点的左孩子；ltag=1,left指向节点的前趋；rtag=0,right指向节点的右孩子；rtag=1,right指向节点的后继；
typedef struct threadtree
{
	int data;
	Nodeflag lflag;//左标志
	Nodeflag rflag;
	threadtree *left;
	threadtree *right;
	threadtree *parent;
};
threadtree *Previous=NULL;
void ldr(threadtree *bt)//中序线索化
{
	if (bt)
	{
		ldr(bt->left);//左子树线索化
		bt->lflag = (bt->left) ? SubTree : Thread;
		bt->rflag = (bt->right) ? SubTree : Thread;
		if (Previous)//前驱存在
		{
			if (Previous->rflag == Thread)
				Previous->right = bt;//previous的右线索指向后继
			if (bt->lflag == Thread)
				bt->left = Previous;//当前节点的左线索指向中序前驱
		}
		Previous = bt;//previous设为刚保存的节点
		ldr(bt->right);
	}
}
void dlr(threadtree *bt)//前序线索化
{
	if (bt)
	{
		bt->lflag = (bt->left) ? SubTree : Thread;
		bt->rflag = (bt->right) ? SubTree : Thread;
		if (Previous)//前驱存在
		{
			if (Previous->rflag == Thread)
				Previous->right = bt;
			if (bt->lflag == Thread)
				bt->left = Previous;
		}
		Previous = bt;//previous设为刚保存的节点
		dlr(bt->left);
		dlr(bt->right);
	}
}
void lrd(threadtree *bt)
{
	if (bt)
	{
		dlr(bt->left);
		dlr(bt->right);
		bt->lflag = (bt->left) ? SubTree : Thread;
		bt->rflag = (bt->right) ? SubTree : Thread;
		if (Previous)//前驱存在
		{
			if (Previous->rflag == Thread)
				Previous->right = bt;
			if (bt->lflag == Thread)
				bt->left = Previous;
		}
		Previous = bt;//previous设为刚保存的节点
	}
}
threadtree *ldrnext(threadtree *bt)//查找指定节点的后继节点
{
	threadtree *nextnode;
	if (!bt)
		return NULL;
	if (bt->rflag == Thread)
		return bt->right;
	else
	{
		nextnode = bt->right;
		while (nextnode->lflag == SubTree)
			nextnode = nextnode->left;
		return nextnode;//右子树最左下的节点
	}
}
threadtree *dlrnext(threadtree *bt)
{
	if (!bt)
		return NULL;
	if (bt->rflag == Thread)
		return bt->right;
	else
	{
		if (bt->lflag == SubTree)
			return bt->left;
		else
			return bt->right;
	}
}
threadtree *dlrpre(threadtree *bt)
{
	threadtree *prenode;
	if (!bt)
		return NULL;
	if (bt->lflag == Thread)
		return bt->left;
	else
	{
		/*
			 ⒈若A为双亲左儿子，那么直接前驱就是A的双亲结点
             ⒉若A为双亲右儿子，那么直接前驱就是A的双亲左儿子
		*/
	}
}
threadtree *lrdnext(threadtree *bt,threadtree *root)
{
	if (!bt)
		return NULL;
	if (bt->rflag == Thread)
		return bt->right;
	else {
		if (bt == root)
			return NULL;
		else if (bt == bt->parent->left&&bt->rflag == SubTree)
		{
			threadtree *a = bt->parent->right;
			while (a->lflag == SubTree)
			{
				a = a->left;
			}
			return a;
		}
		else
			return bt->parent;
	}
}
threadtree *lrdpre(threadtree *bt)
{
	if (!bt)
		return NULL;
	if (bt->lflag == Thread)
		return bt->left;
	else
	{
		if (bt->rflag == SubTree)
			return bt->right;
		else
			return bt->left;
	}
}
threadtree *ldrpre(threadtree *bt)//查找指定节点的前驱节点
{
	threadtree *prenode;
	if (!bt)
		return NULL;
	if (bt->lflag == Thread)
		return bt->left;
	else
	{
		prenode = bt->left;
		while (prenode->rflag == SubTree)
			prenode = prenode->right;
		return prenode;//左子树最右的节点
	}
}
void ldrtravel(threadtree *bt, void(*oper)(threadtree *p))//lrd同ldr
{
	if (bt)
	{
		while (bt->lflag == SubTree)
		{
			bt = bt->left;
		}
		do {
			oper(bt);
			bt = ldrnext(bt);
		} while (bt != NULL);
	}
}
void dlrtravel(threadtree *bt, void(*oper)(threadtree *p))//指向函数的指针
{
	if (bt)
	{
		do {
			oper(bt);
			bt = ldrnext(bt);
		} while (bt != NULL);
	}
}
void oper(threadtree *p)
{
	printf("%d", p->data);
}