//贪婪最佳优先搜索
//试图扩展离目标最近的节点，f(n)=h(n)
//A*搜索
//f(n)=g(n)+h(n)，g(n)到达该节点已经花费的代价，h(n)从节点n到目标节点的最小代价路径的估计值
//保障最优性的条件：可采纳性和一致性
//可采纳性：两点之间直线最短，所以用直线距离作为h(n)肯定不会高估，因此f(n)永远不会超过经过节点n的实际代价
//一致性：如果对于每个节点n和通过n生成的后继节点，从节点n到目标节点的代价不大于从n到n'的单步代价与从n'到目标节点的距离之和
//如果h(n)是可采纳的，则a*的树搜索是最优的；如果h(n)是一致的，则a*的图搜索是最优的
//a*中第一个被选择扩展的目标节点一定是最优解，后面扩展的任何目标节点代价都不会低于它
//通常采用一个open优先队列和一个closed集，open优先队列用来储存还没有遍历将要遍历的节点，而closed集用来储存已经被遍历过的节点
/*最佳优先搜索的过程可以被描述为：
将根节点放入优先队列open中。
从优先队列中取出优先级最高的节点X。
根据节点X生成子节点Y :
3.1.X的子节点Y不在open队列或者closed中，由估价函数计算出估价值，放入open队列中。
3.2.X的子节点Y在open队列中，且估价值优于open队列中的子节点Y，将open队列中的子节点Y的估价值替换成新的估价值并按优先值排序。
3.3.X的子节点Y在closed集中，且估价值优于closed集中的子节点Y，将closed集中的子节点Y移除，并将子节点Y加入open优先队列。
将节点X放入closed集中。
重复过程2, 3, 4直到目标节点找到，或者open为空，程序结束。
*/
//我们有一串字符串[CBAD]，将其转换为[ABCD]，而每次相邻的字母只能转换一次
//astar：g(n)实际代价，h(n)为字母不在自己目标位置上的数目
#include <iostream>
using namespace std;

#define N 4
class Node {
private:
	int g;
	int h;
	char *data;
public:
	Node(char *data, int g = 0, int h = 0) :data(data), g(g), h(h) {}
	~Node() { delete[] data; }
	int getF() const { return g + h; }
	int getG() const {
		return g;
	}
	int getH() const {
		return h;
	}
	char *getData() const {
		return data;
	}
	void setG(int g)
	{
		this->g = g;
	}
	void setH(int h)
	{
		this->h = h;
	}
	void setData(char *data)
	{
		this->data = data;
	}
	bool operator==(const Node& node)
	{
		for(int i=0;i<N;++i)
			if (this->data[i] != node.getData()[i]) {
				return false;
			}
		return true;
	}
	bool operator!=(const Node& node)
	{
		for (int i = 0;i < N;++i)
			if (this->data[i] != node.getData()[i]) {
				return true;
			}
		return false;
	}
};
int heuristic(Node* current, Node* goal)
{
	int h = 0;
	for (int i = 0;i < N;++i)
	{
		if (current->getData()[i] != goal->getData()[i])
			h++;
	}
	return h;
}
struct listnode {
	listnode* next;
	Node* data;
};
void freelistnode(listnode* node) {
	delete node->data;
	node->next = nullptr;
	delete node;
	node = nullptr;
}
class list {
private:
	listnode *head = nullptr;
public:
	~list()
	{
		listnode *p = head;
		while (p!=nullptr)
		{
			p = head->next;
			freelistnode(head);
			head = p;
		}
	}
	listnode *gethead() { return head; }
	void insert(listnode *node)
	{
		if (head == nullptr)
		{
			head = node;
			node->next = nullptr;
		}
		else
		{
			if (node->data->getF() < head->data->getF())
			{
				node->next = head;
				head = node;
			}
			else
			{
				listnode *p = head;
				listnode *q = p->next;
				while (q&&q->data->getF()<node->data->getF())
				{
					p = p->next;
					q = q->next;
				}
				p->next = node;
				node->next = q;
			}
		}
	}
	void remove(listnode *node)
	{
		if (head->data == node->data)
			head = head->next;
		else {
			listnode *p = head;
			listnode *q = head->next;
			while (q!=nullptr&&q->data!=node->data)
			{
				p = q;
				q = q->next;
			}
			if (q != NULL)
			{
				p->next = q->next;
				freelistnode(q);
			}
		}
	}
	listnode *findnode(listnode *node)
	{
		listnode *p = head;
		while (p!=nullptr)
		{
			if (*node->data == *p->data)
			{
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}
	void pop() {
		listnode *p = head;
		head = head->next;
	}
	bool empty()
	{
		if (head == nullptr)
		{
			return true;
		}
		else
			return false;
	}
};

void swapchar(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

int main()
{
	list open;
	list closed;
	Node *goal = new Node(new char[4]{ 'A','B','C','D' });
	listnode *start_list_node = new listnode();
	start_list_node->data = new Node(new char[4]{ 'C','B','A','D' });
	start_list_node->data->setH(heuristic(start_list_node->data, goal));
	open.insert(start_list_node);
	while (!open.empty())
	{
		listnode *top = open.gethead();
		open.pop();
		cout << "[";
		for (int i = 0;i < N;++i)
		{
			cout << top->data->getData()[i];
		}
		cout << "] " << top->data->getG() << "+" << top->data->getH() << endl;
		if (*top->data == *goal)
			break;
		//生成子状态
		for (int i = N - 1;i > 0;--i)
		{
			char *temp = new char[N];
			for (int j = 0;j < N;++j)
			{
				temp[j] = top->data->getData()[j];
			}
			swap(temp[i], temp[i - 1]);
			listnode* child = new listnode();
			child->data = new Node(temp, top->data->getG() + 1);
			child->data->setH(heuristic(child->data, goal));
			if (open.findnode(child) == NULL && closed.findnode(child) == NULL)
				open.insert(child);
			else if (open.findnode(child) != NULL)
			{
				listnode *old = open.findnode(child);
				if (child->data->getF() < old->data->getF())
				{
					open.remove(old);
					open.insert(child);
				}
			}
			else if (closed.findnode(child) != NULL)
			{
				listnode *old = closed.findnode(child);
				if (child->data->getF() < old->data->getF())
				{
					closed.remove(old);
					open.insert(child);
				}
			}
		}
		closed.insert(top);
	}
	delete goal;
}