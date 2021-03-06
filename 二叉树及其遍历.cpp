//二叉树的链式存储
typedef struct chaintree
{
	int data;
	chaintree *left;
	chaintree *right;
};
//初始化
chaintree* bintreeinit()
{
	chaintree *node;
	if (node = (chaintree*)malloc(sizeof(chaintree)))
	{
		printf("\n输入根节点数据：");
		scanf("%s", &node->data);
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	return NULL;
}
//获取左右子树-递归
chaintree* bintreeleft(chaintree *node)
{
	if (node)
		return node->left;
	else
		return NULL;
}

//判空
bool bintreeisempty(chaintree *node)
{
	if (node)
		return 0;
	else
		return 1;
}
//计算深度 --递归
int bintreedepth(chaintree* node)
{
	int dep1, dep2;
	if (!node)
		return 0;
	else {
		dep1 = bintreedepth(node->left) + 1;
		dep2 = bintreedepth(node->right) + 1;
		return dep1 > dep2 ? dep1 : dep2;
	}
}
//查找 --递归
chaintree *bintreefind(chaintree *bt, int d)
{
	chaintree *p;
	if (!bt)
		return NULL;
	else
	{
		if (bt->data == d)
			return bt;
		else
		{
			if (bintreefind(bt->left, d))
				return bt->left;
			else if (bintreefind(bt->right, d))
				return bt->right;
			else
				return NULL;
		}
	}
}
//清空 --递归
void bintreeclear(chaintree *bt)
{
	if (bt)
	{
		bintreeclear(bt->left);
		bintreeclear(bt->right);
		free(bt);
		bt = NULL;
	}
}
//遍历--递归
void mlr(chaintree *bt, void(*oper)(chaintree *p))
{
	if (bt)
	{
		oper(bt);//M
		mlr(bt->left,oper);//L
		mlr(bt->right,oper);//R
	}
}
//层序遍历
#include <queue>
void level(chaintree *bt)
{
	if (bt)
	{
		queue<chaintree*> q;
		q.push(bt);
		while (!q.empty()) {
			chaintree *a = q.front();
			q.pop();
			//oper(a);
			q.push(a->left);
			q.push(a->right);
		}
	}
}

//非递归--中序
#include <stack>
void lmr(chaintree *bt)
{
	chaintree *t = bt;
	stack<chaintree*> s;
	while (t || !s.empty())//t插入第一个点的条件，栈空为退出的条件
	{
		while (t)
		{
			//printf("%d", t->data); 前序遍历
			s.push(t);
			t = t->left;
		}
		if (!s.empty())
		{
			t = s.top();
			s.pop();
			printf("%d", t->data);
			t = t->right;
		}
	}
}

//非递归--后序
//1.保存最后访问节点last--（1）对于叶子节点直接输出（2）p有孩子且没有访问过，按右到左顺序入栈（3）p有孩子且被访问过则访问p
//2.压两次
void lrm(chaintree *bt)
{
	if (bt)
	{
		stack<chaintree*> s;
		s.push(bt);
		s.push(bt);
		while (!s.empty())
		{
			chaintree *p = s.top();
			s.pop();
			if (!s.empty() && p == s.top())
			{
				if (p->right)
				{
					s.push(p->right);
					s.push(p->right);
				}
				if (p->left)
				{
					s.push(p->left);
					s.push(p->left);
				}
			}
			else
			{
				printf("%d", p->data);
			}
		}
	}
}
void lmr2(chaintree *bt)
{
	if (bt)
	{
		chaintree *p = bt;
		chaintree *a;
		stack<chaintree*> s;
		stack<chaintree*> last;
		s.push(p);
		last.push(NULL);
		while (!s.empty())
		{
			p = s.top();
			if (p->left == NULL && p->right == NULL)
			{
				printf("%d", p->data);
				s.pop();
			}
			else
			{
				a = last.top();
				if (a != p)
				{
					last.push(p);
					if (p->right) s.push(p->right);
					if (p->left) s.push(p->left);
				}
				else
				{
					printf("%d", p->data);
					s.pop();last.pop();
				}
			}
		}
	}
}

