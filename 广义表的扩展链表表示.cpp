//广义表的第二种存储结构是非空广义表最高元素间有逻辑关系，第一个元素无前驱有后继，最后一个元素无后继有前驱，其余元素有唯一前驱和唯一后继。
//在这种存储结构中，原子和表均采用三个域的节点结构，节点中都有一个指针域指向后继节点，原子节点中包括标志域tag=0和原子域data，子表节点包括标志域tag=1和指向子表的指针hp。
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct GLNode
{
	int tag;//节点类型标记
	union
	{
		char data;//原子值
		struct GLNode *sublist;//指向子表的指针
	}val;
	struct GLNode *link;//指向下一个元素
};
//在读入表达式时，遇到左括号就递归的构造子表；否则若是原子就建立原子节点；若读入逗号，就递归构造后续子表，直到输入结束表达式
GLNode *GLCreate(const char *&s)
{
	GLNode *g;
	char ch = *s++;
	if (ch != '\0')
	{
		g = (GLNode *)malloc(sizeof(GLNode));
		if (ch == '(')
		{
			g->tag = 1;
			g->val.sublist = GLCreate(s);
		}
		else if (ch == ')')
			g = NULL;
		else if (ch == '#')
			g = NULL;
		else
		{
			g->tag = 0;
			g->val.data = ch;
		}
	}
	else
		g = NULL;
	ch = *s++;
	if (g != NULL)
		if (ch == ',')
			g->link = GLCreate(s);
		else
			g->link = NULL;
	return g;
}
int GLLength(GLNode *g)//求广义表长度非递归
{
	int gCount = 0;
	GLNode *g1 = g->val.sublist;
	while (g1 != NULL)
	{
		gCount++;
		g1 = g1->link;
	}
	return gCount;
}
int GLLength_recursion(GLNode *g)//求长度递归
{
	if (!g)
		return 1;
	return GLLength_recursion(g->link) + 1;
}
int GLDepth(GLNode *g)
{
	GLNode *g1;
	int max = 0, dep;
	if (g->tag == 0)//为原子时
		return 0;
	g1 = g->val.sublist;//g1指向表的第一个元素
	if (g1 == NULL)//为空表时
		return 1;
	while (g1 != NULL)//遍历表中每个元素
	{
		if (g1->tag == 1)//元素为子表的情况
		{
			dep = GLDepth(g1);
			if (dep > max)
				max = dep;
		}
		g1 = g1->link;//指向下一个元素
	}
	return (max + 1);
}
void GLDisplay(GLNode *g)
{
	if (g != NULL)//表不为空
	{
		if (g->tag == 0)//为原子时直接输出
			cout << g->val.data << " ";
		else
		{
			cout << "(";
			if (g->val.sublist == NULL)
				cout << "#";
			else
				GLDisplay(g->val.sublist);
			cout << ")";
		}
		if (g->link != NULL)
		{
			cout << ",";
			GLDisplay(g->link);
		}
	}
}
int main()
{
	GLNode *g = NULL;
	const char *s = "((a,b),(c,d))";
	g = GLCreate(s);
	cout << "广义表的深度为：" << GLDepth(g) << endl;
	cout << "广义表的长度为：" << GLLength(g) << endl;
	cout << "广义表的长度为：" << GLLength_recursion(g) << endl;
	cout << "广义表的内容为：";
	GLDisplay(g);
	cout << endl;
	return 0;
}