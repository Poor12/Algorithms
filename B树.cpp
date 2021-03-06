//B树，又称平衡多路查找树
//一棵m阶的B树的特性如下：
/*
	1.树中每个节点最多含有m个孩子
	2.除根节点和叶子节点外，其他每个节点至少有[ceil(m / 2)]个孩子
	3.若根节点不是叶子节点，则至少有2个孩子（没有孩子的根节点，整棵树只有一棵根节点）
	4.所有叶子节点都出现在同一层，叶子节点不包含任何关键字信息(可以看做是外部接点或查询失败的接点，实际上这些结点不存在，指向这些结点的指针都为null)；
	5.有j个孩子的非叶节点恰好有j-1个关键码（递增排列）
	6.每个非终端结点中包含有n个关键字信息： (n，P0，K1，P1，K2，P2，......，Kn，Pn)。其中：
       a)   Ki (i=1...n)为关键字，且关键字按顺序升序排序K(i-1)< Ki。 
       b)   Pi为指向子树根的接点，且指针P(i-1)指向子树种所有结点的关键字均小于Ki，但都大于K(i-1)。 
       c)   关键字的个数n必须满足： [ceil(m / 2)-1]<= n <= m-1

*/
//
//用度定义的B树
//1.B树每一个节点能包含的关键字数都有一个上界和下界，这个下界可以用一个称作B树的最小度数表示
//2.每个非根的内节点至多有m个子女，每个非根的节点至少有m-1个关键字,根节点至少含有1个。
//3.每个节点可包含至多2*m-1个关键字，所以一个内节点最多有2m个子女，若节点恰好有2*m-1个关键字，则说这个节点是满的
//4.当关键字树m=2时的B树是最简单的，此时每个节点可能因此而含有2个、3个或4个子女，即2-3-4树
/*
#define m 1024
struct BTNode;
typedef struct BTNode *PBTNode;
struct BTNode {
	int keynum;//关键字,keynum<m
	PBTNode parent;//父节点
	PBTNode *ptr;//子树指针向量ptr[0]....ptr[keynum]
	int *key;//关键字向量key[0]...key[keynum-1]
};
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define KeyType int
#define Record string
const int m = 3;//阶数
using namespace std;
typedef struct BTNode {
	int keynum;
	KeyType key[m + 1];//key[0]未用
	struct BTNode *parent;//双亲节点指针
	struct BTNode *ptr[m + 1];//孩子节点指针数组
	Record *recptr[m + 1];
	BTNode() {
		keynum = 0;
		parent = NULL;
		for (int i = 0;i < m + 1;++i)
		{
			ptr[i] = NULL;
		}
	}
}BTNode,*BTree;
BTree T = NULL;
typedef struct {
	BTree pt;//指向找到的节点
	int i;//在节点中的关键位序
	int tag;//1 查找成功 0 查找失败
}result;

int Search(BTree p, int k)//在以p为根的子树中寻找k的关键字
{
	int i = 1;
	while (i <= p->keynum&&k > p->key[i]) i++;
	return i;
}
void SearchBtree(BTree t, int k, result &r)//在以t为根节点的子树中找关键字为k的节点
{
	int i = 0, found = 0;
	BTree p = t, q = NULL;//p指向根节点，q指向双亲节点
	while (p!=NULL&&0==found)
	{
		i = Search(p, k);
		if (i <= p->keynum&&p->key[i] == k) found = 1;
		else
		{
			q = p;
			p = p->ptr[i - 1];
		}
	}
	if (1 == found)
	{
		r = { p,i,1 };
	}
	else
	{
		r = { q,i,0 };
	}
}
void split(BTree &q, int s, BTree &ap)//将q节点分裂成两个节点，前一半保留在原节点，后一半移向ap新节点
{
	int i, j, n = q->keynum;
	ap = (BTNode*)malloc(sizeof(BTNode));
	ap->ptr[0] = q->ptr[s];
	for (i = s + 1, j = 1;i <= n;i++, j++)
	{
		ap->key[j] = q->key[i];
		ap->ptr[j] = q->ptr[i];
	}
	ap->keynum = n - s;
	ap->parent = q->parent;
	for (i = 0;i <= n - s;++i)
		if (ap->ptr[i] != NULL)
			ap->ptr[i]->parent = ap;
	q->keynum = s - 1;
}
void newRoot(BTree &t, BTree p, int x, BTree ap)//生成新的根节点
{
	t = (BTNode*)malloc(sizeof(BTNode));
	t->keynum = 1;
	t->ptr[0] = p;
	t->ptr[1] = ap;
	t->key[1] = x;
	if (p != NULL) p->parent = t;
	if (ap != NULL) ap->parent = t;
	t->parent = NULL;
}
void insert(BTree &q, int i, int x, BTree ap)
{
	int j, n = q->keynum;
	for (j = n;j >= i;j--)
	{
		q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}
	q->key[i] = x;
	q->ptr[i] = ap;
	if (ap != NULL) ap->parent = q;
	q->keynum++;
}
void insertbtree(BTree &t, int k, BTree q, int i)
//在B树的q节点的key[i-1]和key[i]之间插入关键字，若插入后关键字数等于B树的阶，则沿着双亲指针分裂
{
	int x, s, finished = 0, needNewRoot = 0;
	BTree ap;
	if (q == NULL) newRoot(t, NULL, k, NULL);
	else
	{
		x = k;
		ap = NULL;
		while (0==needNewRoot&&0==finished)
		{
			insert(q, i, x, ap);
			if (q->keynum < m) finished = 1;
			else
			{
				s = (m + 1) / 2;
				split(q, s, ap);
				x = q->key[s];
				if (q->parent != NULL)
				{
					q = q->parent;
					i = Search(q, x);
				}
				else
					needNewRoot = 1;
			}
		}
		if (1 == needNewRoot)
			newRoot(t, q, x, ap);
	}
	
}
void remove(BTree &p, int i)
{
	int j, n = p->keynum;
	for (j = i;j < n;++j)
	{
		p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}
	p->keynum--;
}
void Successor(BTree &p, int i)//由后继最下层非终端结点的最小关键字代替结点中关键字key[i]
{
	BTree child = p->ptr[i];
	while (child->ptr[0]!=NULL)
	{
		child = child->ptr[0];
	}
	p->key[i] = child->key[1];
	p = child;
}
void restore(BTree &p, int i, BTree &t)//对B树进行调整
{
	int j;
	BTree ap = p->parent;
	if (ap == NULL)//若调整后出现空的根结点，则删除该根结点，树高减1
	{
		t = p;//根节点下移
		p = p->parent;
		return;
	}	
	BTree lc, rc, pr;
	int finished = 0, r = 0;
	while (!finished)
	{
		r = 0;
		while (ap->ptr[r] != p) r++; //确定p在ap子树中的位置
		if (r == 0)
		{
			r++;
			lc = NULL, rc = ap->ptr[r];
		}
		else if (r == ap->keynum)
		{
			rc = NULL;lc = ap->ptr[r - 1];
		}
		else
		{
			lc = ap->ptr[r - 1];rc = ap->ptr[r + 1];
		}
		if (r > 0 && lc != NULL && (lc->keynum > (m - 1) / 2))//向左兄弟借关键字
		{
			p->keynum++;
			for (j = p->keynum;j > 1;j--)//结点关键字右移
			{
				p->key[j] = p->key[j - 1];
				p->ptr[j] = p->ptr[j - 1];
			}
			p->key[1] = ap->key[r];//父亲插入到结点
			p->ptr[1] = p->ptr[0];
			p->ptr[0] = lc->ptr[lc->keynum];
			if (NULL != p->ptr[0])//修改p中的子女的父结点为p
			{
				p->ptr[0]->parent = p;
			}
			ap->key[r] = lc->key[lc->keynum];//左兄弟上移到父亲位置
			lc->keynum--;
			finished = 1;
			break;
		}
		else if (ap->keynum > r&&rc != NULL && (rc->keynum > (m - 1) / 2)) //向右兄弟借关键字
		{
			p->keynum++;
			p->key[p->keynum] = ap->key[r]; //父亲插入到结点
			p->ptr[p->keynum] = rc->ptr[0];
			if (NULL != p->ptr[p->keynum]) //修改p中的子女的父结点为p
				p->ptr[p->keynum]->parent = p;
			ap->key[r] = rc->key[1]; //右兄弟上移到父亲位置
			rc->ptr[0] = rc->ptr[1];
			for (j = 1;j < rc->keynum;j++)  //右兄弟结点关键字左移
			{
				rc->key[j] = rc->key[j + 1];
				rc->ptr[j] = rc->ptr[j + 1];
			}
			rc->keynum--;
			finished = 1;
			break;
		}
		r = 0;
		while (ap->ptr[r] != p) //重新确定p在ap子树的位置
			r++;
		if (r > 0 && (ap->ptr[r - 1]->keynum <= (m - 1) / 2)) //与左兄弟合并
		//if(r>0) //与左兄弟合并
		{
			lc = ap->ptr[r - 1];
			p->keynum++;
			for (j = p->keynum;j > 1;j--) //将p结点关键字和指针右移1位
			{
				p->key[j] = p->key[j - 1];
				p->ptr[j] = p->ptr[j - 1];
			}
			p->key[1] = ap->key[r]; //父结点的关键字与p合并
			p->ptr[1] = p->ptr[0]; //从左兄弟右移一个指针
			ap->ptr[r] = lc;
			for (j = 1;j <= lc->keynum + p->keynum;j++) //将结点p中关键字和指针移到p左兄弟中
			{
				lc->key[lc->keynum + j] = p->key[j];
				lc->ptr[lc->keynum + j] = p->ptr[j];
			}
			if (p->ptr[0]) //修改p中的子女的父结点为lc
			{
				for (j = 1;j <= p->keynum;j++)
					if (p->ptr[p->keynum + j])   p->ptr[p->keynum + j]->parent = lc;
			}
			lc->keynum = lc->keynum + p->keynum;  //合并后关键字的个数
			for (j = r;j < ap->keynum;j++)//将父结点中关键字和指针左移
			{
				ap->key[j] = ap->key[j + 1];
				ap->ptr[j] = ap->ptr[j + 1];
			}
			ap->keynum--;
			pr = p;free(pr);
			pr = NULL;
			p = lc;
		}
		else //与右兄弟合并
		{
			rc = ap->ptr[r + 1];
			if (r == 0)
				r++;
			p->keynum++;
			p->key[p->keynum] = ap->key[r]; //父结点的关键字与p合并
			p->ptr[p->keynum] = rc->ptr[0]; //从右兄弟左移一个指针
			rc->keynum = p->keynum + rc->keynum;//合并后关键字的个数
			ap->ptr[r - 1] = rc;
			for (j = 1;j <= (rc->keynum - p->keynum);j++)//将p右兄弟关键字和指针右移
			{
				rc->key[p->keynum + j] = rc->key[j];
				rc->ptr[p->keynum + j] = rc->ptr[j];
			}
			for (j = 1;j <= p->keynum;j++)//将结点p中关键字和指针移到p右兄弟
			{
				rc->key[j] = p->key[j];
				rc->ptr[j] = p->ptr[j];
			}
			rc->ptr[0] = p->ptr[0]; //修改p中的子女的父结点为rc
			if (p->ptr[0])
			{
				for (j = 1;j <= p->keynum;j++)
					if (p->ptr[p->keynum + j])    p->ptr[p->keynum + j]->parent = rc;
			}
			for (j = r;j < ap->keynum;j++)//将父结点中关键字和指针左移
			{
				ap->key[j] = ap->key[j + 1];
				ap->ptr[j] = ap->ptr[j + 1];
			}
			ap->keynum--;//父结点的关键字个数减1
			pr = p;
			free(pr);
			pr = NULL;
			p = rc;
		}
		ap = ap->parent;
		if (p->parent->keynum >= (m - 1) / 2 || (NULL == ap && p->parent->keynum > 0))
			finished = 1;
		else if (ap == NULL) //若调整后出现空的根结点，则删除该根结点，树高减1
		{
			pr = T;
			T = p; //根结点下移
			free(pr);
			pr = NULL;
			finished = 1;
		}
		p = p->parent;
	}

}
void deletebtree(BTree &p, int i, BTree &T)//删除b树上p节点的第i个关键字
{
	if (p->ptr[i] != NULL)//若不是最下层的终端
	{
		Successor(p, i);
		deletebtree(p, 1, T);//删除最下层非终端节点的最小关键字
	}
	else
	{
		remove(p, i);
		if (p->keynum < (m - 1) / 2)
			restore(p, i, T);//调整B树
	}
}
void show_btree(BTree &p)
{
	if (p == NULL)
	{
		puts("B tree does not exist");
		return;
	}
	bool have_child = false;
	printf("[");
	for (int i = 1;i <= p->keynum;++i)
	{
		if (i == 1);
		else printf(" ");
		printf("%d", p->key[i]);
	}
	printf("]");
	for (int i = 0;i <= p->keynum;++i)
	{
		if (p->ptr[i] != NULL)
		{
			if (i == 0)printf("<");
			else
			{
				printf(",");
			}
			show_btree(p->ptr[i]);
			have_child = 1;
		}
	}
	if (have_child)printf(">");
}
void show_tree2(BTree &p, int deep)
{
	if (p == NULL) {
		return;
	}
	int i;
	for (i = 0;i < p->keynum;++i)
	{
		show_tree2(p->ptr[i], deep + 1);
		for (int i = 0;i < deep;++i)
			printf("\t");
		printf("%d\n", p->key[i + 1]);
	}
	show_tree2(p->ptr[i], deep + 1);
}

void destroy(BTree &t)
{
	int i = 0;
	if (t != NULL)
	{
		while (i<t->keynum)
		{
			destroy(t->ptr[i]);
			free(t->ptr[i]);
			i++;
		}
	}
	free(t);
	t = NULL;
}
void create_btree()
{
	T = new BTNode;
	T->keynum = 0;
	puts("new success");
}
void insert_keytype()
{
	puts("enter an element to be inserted");
	KeyType temp;
	scanf("%d", &temp);
	result p;
	SearchBtree(T, temp, p);
	if (p.tag == 0)
	{
		insertbtree(T, temp, p.pt, p.i);
		puts("insert success");
		show_btree(T);
		puts(" ");
	}
	else
	{
		puts("the element is already in the b tree");
	}
}
void find_keytype()
{
	puts("enter an element to find");
	KeyType temp;
	scanf("%d", &temp);
	result p;
	SearchBtree(T, temp, p);
	if (p.tag)
	{
		puts("find success");
	}
	else
	{
		puts("lookup failure");
	}
}
void delete_keytype()
{
	puts("Enter an element to be deleted");
	KeyType temp;
	scanf("%d", &temp);
	result p;
	SearchBtree(T, temp, p);
	if (p.tag)
	{
		deletebtree(p.pt, p.i, T);
		puts("Delete success");show_btree(T);
		puts("");
	}
	else puts("The element does not exist in the B tree.");
}

int main()
{
	//freopen("in.txt","r",stdin);
	/*调试用代码
	BTree T = new BTNode ;
	T->keynum=0;
	result p ;
	//int in[]={15,30,50,10,25,45,60,80,90,75};
	int in[]={35,16,18,70,5,50,22,60,13,17,12,45,25,42,15,90,30,7};
	//int in[] = {35,25,22,30,60,42,70};
	for(int i=0;i<18;i++)
	{
		printf("insert %d ",in[i]);
		SearchBTree(T,in[i],p);
		InsertBTree(T,in[i],p.pt,p.i);
		show_Btree(T);
		puts("");
	}
	//int out[]={30,50,25,40};
	int out[]={45,90,50,22,42};
	//int out[]={22};
	for(int i=0;i<5;i++)
	{
		SearchBTree(T,out[i],p);
		if(p.tag)
		{
			printf("delete %d ",out[i]);
			DeleteBTree(p.pt,p.i,T);
			show_Btree(T);
			puts("");
		}
		else
		{
			printf("%d is not in the tree\n",out[i]);
		}
	}
	//Destory(T);
	//if(T) show_Btree(T);
	//else printf("B-tree is empty\n");
	show_Btree2(T,0);
	*/
	return 0;
}
