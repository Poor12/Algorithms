https://www.cnblogs.com/MyStringIsNotNull/archive/2018/01/13/8279126.html
//树转换为二叉树
/*
将树转换为二叉树的方法可以归纳为“加线”、“删除”、”旋转“3个步骤，其具体描述如下:
加线：将树中所有相邻的兄弟之间加一条连线。
删线：对树中的每一个节点，只保留它与第一个孩子节点之间的连线，删去它与其他孩子节点之间的连线。
旋转：以树的根节点为轴心，将树平面顺时针旋转一定的角度并适当的进行调整，使得转化后所得的二叉树看起来比较规整(该步骤不是必须)
*/
/*
二叉树转换成树是由树转换成二叉树的一个逆过程，也就是一个由二叉树还原成它原来所对应的树的过程，其步骤如下:
加线：若某节点是其双亲节点的左孩子，则将该节点沿着右分支向下的所有节点与该节点的双亲节点用线连接
删线：将所有本来双亲节点与右孩子节点的连线删除
旋转：对经过步骤1、2两步后所得的树以根节点为轴心，按逆时针方向旋转一定的角度并做适当调整，使得转化后所得的树看起来比较规整
*/
/*
将森林转换为二叉树的步骤是：
一：
（1）先把每棵树转换为二叉树；
（2）第一棵二叉树不动，从第二棵二叉树开始，依次把后一棵二叉树的根结点作为前一棵二叉树的根结点的右孩子结点，用线连接起来。当所有的二叉树连接起来后得到的二叉树就是由森林转换得到的二叉树。
二：
（1）增加一个虚节点，将森林转化成一棵树
（2）按树转化成二叉树的方式转化成二叉树
*/
/*
二叉树与森林之间存在着一一对应的关系，可以根据以下步骤将一棵二叉树转化为森林：
1.将二叉树的根节点的右孩子节点的各个连线之间依次断开，将一棵二叉树分解为多棵二叉树
2.依次将每一棵二叉树通过加线、删线、旋转的方式转换为一棵树
3.各个树构成的整体即为一个森林
*/
#include <queue>
#include <map>
struct node {//二叉树节点
	int data;
	node *left;
	node *right;
};
struct treenode{//树节点
	int data;
	queue<int> firstchild;
	void addchild(int child)
	{
		firstchild.push(child);
	}
};
struct mapnode {//中间节点
	int data;
	int left = -1;//存储左孩子的下标，-1表示没有
	int right = -1;//存储右孩子的下标
};
vector<treenode> tree;//原树
vector<treenode> tree1;//将二叉树转换后的树
vector<mapnode> m; // 用于记录树的中间转化过程中的相关信息
map<int, node*> nm;//用于记录树中各个存储节点的指针，便于树的构造过程
map<node*, int> indexmap;
void forest(int n)
{
	tree.resize(n);
	m.resize(n);
	for (int i = 0;i < n;++i)
		nm[i]=new node();
}
void settreedata(int index, int data)
{
	tree[index].data = data;
	m[index].data = data;
	nm[index]->data = data;
}
void addtreechild(int index, int childindex)
{
	tree[index].firstchild.push(childindex);
}
node* totranslate(int nodecount)
{
	for (int i = 0;i < nodecount;++i)
	{
		queue<int> childlist = tree[i].firstchild;
		int now = -1;
		int previous = i;
		if (!childlist.empty())
		{
			now = childlist.front();
			childlist.pop();
			m[previous].left = now;
			previous = now;
		}
		while (!childlist.empty())
		{
			now = childlist.front();
			childlist.pop();
			m[previous].right = now;
			previous = now;
		}
	}
	for (int i = 0;i < nodecount;++i)
	{
		int left = m[i].left;
		int right = m[i].right;
		node *n = nm[i];
		if (left != -1)
			n->left = nm[left];
		if (right != -1)
			n->right = nm[right];
	}
	node *root = nm[0];
	return root;
}
void reverseforest(node *root)
{
	queue<node*> q;
	q.push(root);
	int nodec = 0;
	nm[nodec] = root;
	indexmap[root] = nodec++;
	while (!q.empty())
	{
		node *n = q.front();
		q.pop();
		if (n->left)
		{
			q.push(n->left);
			nm[nodec] = n->left;
			indexmap[n->left] = nodec++;
		}
		if (n->right)
		{
			q.push(n->right);
			nm[nodec] = n->right;
			indexmap[n->right] = nodec++;
		}
	}
	tree1.resize(nodec);
	for (int i=0;i<tree1.size();++i)
	{
		tree1[i].data = nm[i]->data;
	}
}
void addtreechild1(int index, int childindex)
{
	tree1[index].firstchild.push(childindex);
}
vector<treenode> totranslatetree()
{
	for (int index = 0;index < tree1.size();index++)
	{
		node *a = nm[index];
		a = a->left;
		if (a)
		{
			addtreechild1(index, indexmap[a]);
			while (a->right)
			{
				addtreechild1(index, indexmap[a->right]);
				a = a->right;
			}
		}
	}
	return tree1;
}
void ldr(node *root)
{
	if (root)
	{
		ldr(root->left);
		printf("%d ", root->data);
		ldr(root->right);
	}
}
int main() {
	forest(8);
	settreedata(0, 1);
	settreedata(1, 2);
	settreedata(2, 3);
	settreedata(3, 4);
	settreedata(4, 5);
	settreedata(5, 6);
	settreedata(6, 7);
	settreedata(7, 8);
	addtreechild(0, 1);
	addtreechild(0, 2);
	addtreechild(0, 3);
	addtreechild(1, 4);
	addtreechild(1, 5);
	addtreechild(5, 7);
	addtreechild(3, 6);
	node *root=totranslate(tree.size());
	ldr(root);
	cout << "\n";
	reverseforest(root);
	tree1 = totranslatetree();
	for (int i = 0;i < tree1.size();++i)
	{
		cout << i <<" "<< tree1[i].data << ": ";
		queue<int> q = tree1[i].firstchild;
		if (!q.empty())
		{
			while (!q.empty())
			{
				cout << q.front() << " ";
				q.pop();
			}
		}
		else
		{
			cout << "无孩子节点";
		}
		cout << "\n";
	}
	
}
