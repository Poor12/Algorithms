//稀疏矩阵的十字链表存储表示
#include <stdio.h>
#include <stdlib.h>
typedef int ELemType;
typedef struct OLNode
{
	ELemType e;//值
	int i, j;//第i行，第j列
	struct OLNode *right, *down;//right指向同一行列数大的非零项，down指向同一列行数大的非零项
}OLNode, *OLink;
typedef struct
{
	OLink *rhead, *chead;//行列的头指针
	int mu, nu, tu;//行数、列数、非零项数
}CrossList;

int create_SMatrix(CrossList *M)
{
	int i, j, m, n, t;
	int k, flag;
	ELemType e;
	OLNode *p, *q;
	if (M->rhead)
	{
		do
		{
			flag = 1;
			printf("输入要创建矩阵的行数，列数，以及非零元素的个数:\n");
			scanf("%d%d%d", &m, &n, &t);
			if (m < 0 || n < 0 || t < 0 || t > m * n)
				flag = 0;
		} while (!flag);
		M->mu = m;
		M->nu = n;
		M->tu = t;
		M->rhead = (OLink *)malloc((m + 1) * sizeof(OLink));
		if (!M->rhead)
			exit(-1);
		M->chead = (OLink *)malloc((n + 1) * sizeof(OLink));
		if (!(M->chead))
			exit(-1);
		for (k = 1; k <= m; k++)
			M->rhead[k] = NULL;
		for (k = 1; k <= n; k++)
			M->chead[k] = NULL;
		for (k = 1; k <= t; ++k)
		{
			do {
				flag = 1;
				printf("输入第%d个结点行号、列号以及值：\n", k);
				scanf("%d%d%d", &i, &j, &e);
				if (i <= 0 || j <= 0)
					flag = 0;
			} while (!flag);
			p = (OLink)malloc(sizeof(OLNode));
			if (NULL == p)
				exit(-1);
			p->i = i;
			p->j = j;
			p->e = e;
			if (NULL == M->rhead[i] || M->rhead[i]->j > j)
			{
				p->right = M->rhead[i];
				M->rhead[i] = p;
			}
			else
			{
				for (q = M->rhead[i]; q->right && q->right->j < j; q = q->right)
					;
				p->right = q->right; // 完成行插入      
				q->right = p;
			}
			if (NULL == M->chead[j] || M->chead[j]->i > i)
			{
				p->down = M->chead[j];
				M->chead[j] = p;
			}
			else
			{
				for (q = M->chead[j]; q->down && q->down->i < i; q = q->down)
					;
				p->down = q->down;
				q->down = p;
			}
		}
		return 1;
	}
}

int main()
{
	CrossList M;
	create_SMatrix(&M);
	return 0;
}