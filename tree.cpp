//树的表示法
//1.双亲节点数组表示法
/*
struct treenode {
	int data;
	int parent;
};
treenode tree[];
*/
//2.孩子节点多重链表表示法
//3.孩子节点链表表示法
/*
#include <list>
struct treenode {
	int data;
	list<int> firstchild;//存放孩子的地址，也就是tree数组的下标
};
treenode tree[];
*/

//4.左子女-右兄弟表示法（二叉链表表示法）
//5.双亲孩子链表表示法	//1和3的结合
template <class T> class treenode {
	friend class tree<T>;
private:
	T m_value;
	treenode<T>* leftchild;
	treenode<T>* rightsibling;
public:
	treenode(const T&) {
		m_value = value;
		leftchild = rightsibling = null;
	}
	~treenode() {};
	bool isleaf() {
		if (null == leftchild)
			return true;
		else
			return false;
	}
	T getvalue() {
		return m_value;
	}
	void setvalue(T& value) {
		m_value = value;
	}
	treenode<T> *getleftchild() {
		return leftchild;
	}
	treenode<T> *getrightsibling() {
		return rightsibling;
	}
	void setleftchild(treenode<T> *pleftchild) {
		leftchild = pleftchild;
	}
	void setrightsibling(treenode<T> *prightsibling) {
		rightsibling = prightsibling;
	}
};
template <class T> class tree {
	treenode<T>* root, *parent;
	int getparent(treenode<T>* t, treenode<T>* p) {//深搜
		treenode<T>* q = t->getleftchild();
		while (q!=NULL&&q!=p)
		{
			if (getparent(q, p) != 0)
				return 2;
			q = q->getrightsibling();
		}
		if (q != NULL && q == p) {
			parent = t;
			return 1;
		}
		else
			return 0;
	}
public:
	tree() {
		root = NULL;
		parent = NULL;
	}
	tree(treenode<T>* rt) {
		root = rt;
		parent = NULL;
	}
	~tree() {};
	treenode<T>* getroot() {
		return root;
	}
	bool isempty() {
		if (root == NULL)
			return true;
		else
			return false;
	}
	treenode<T>* getparent(treenode<T>* current) {
		treenode<T>* pointer = current, *t;
		if (current == NULL || current == root)
			return NULL;
		t = root;
		getparent(t,pointer);
		return parent;
	}
	treenode<T>* getfirstchild(treenode<T> *t) {
		return t->getleftchild();
	}
	treenode<T>* getnextsibling(treenode<T> *t) {
		return t->getrightsibling();
	}
	void insertchild(treenode<T> *t, treenode<T> *n) {
		if (t->getleftchild() == NULL)
			t->setleftchild(n);
		else
		{
			treenode<T> *p = t->getleftchild();
			while (p->getrightsibling()!=NULL)
			{
				p = p->getrightsibling();
			}
			p->getrightsibling() = n;
		}
	}
};