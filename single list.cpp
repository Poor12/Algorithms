template <class T> class listnode {
	T data;
	listnode<T> *link;
public:
	listnode() :link(NULL) {}
	listnode(T value) :link(NULL), data(value) {}
	~listnode() {};
	void setlink(listnode<T> *next) {
		link = next;
	}
	void setdata(T value) {
		data = value;
	}
	listnode<T> *getlink() {
		return link;
	}
	T& getdata() {
		return data;
	}
};
template <class T> class list {
	listnode<T> *head;
	listnode<T> *tail;
public:
	list() {
		head = new listnode<T>();
		tail = head;
		tail->setlink(NULL);
	}
	~list() {
		removeall();
		delete head;
	}
	bool isempty() {
		return head->getlink() == NULL;
	}
	void removeall() {
		listnode<T> *cur;
		while (head->getlink() != NULL)
		{
			cur = head->getlink();
			head->setlink(cur->getlink());
			delete cur;
		}
		tail = head;
	}
	
	listnode<T> *getnodeat(int index) {
		if (index > this->getcount() - 1 || index < 0) {
			cout << "a wrong position";
		}
		listnode<T> *handle = head->getlink();
		while (index)
		{
			handle = handle->getlink();
			--index;
		}
		return handle;
	}
	
	bool addtail(T value) {
		listnode<T> *add = new listnode<T>(value);
		tail->setlink(add);
		tail = tail->getlink();
		tail->setlink(NULL);
		if (tail != NULL)
			return true;
		else
			return false;
	}
	
	int getcount() {
		int count = 0;
		listnode<T> *current = head->getlink();
		while (current!=NULL)
		{
			++count;
			current = current->getlink();
		}
		return count;
	}
	
	bool removetail() {
		return removeat(this->getcount() - 1);
	}
	bool insertat(int index, T value) {
		if (index > this->getcount() - 1 || index < 0) {
			cout << "A wrong postion!\n";
			return false;
		}
		listnode<T> *current = head;
		while (index)
		{
			current = current->getlink();
			--index;
		}
		listnode<T> *add = new listnode<T>(value);
		add->setlink(current->getlink());
		current->setlink(add);
		if (current->getlink() != NULL)
			return true;
		else
			return false;
	}
	T& getat(int index) {
		if (index > this->getcount() - 1 || index < 0) {
			cout << "a wrong position";
		}
		listnode<T> *cur;
		cur = head->getlink();
		while (index)
		{
			cur = cur->getlink();
			--index;
		}
		return cur->getdata();
	}
	
	bool removeat(int index) {
		if (index > this->getcount() - 1 || index < 0) {
			cout << "A wrong position!\n";
			return false;
		}
		listnode<T> *cur, *curPre;
		cur = head;
		curPre = cur->getlink();
		while (index)
		{
			cur = cur->getlink();
			curPre = curPre->getlink();
			--index;
		}
		if (tail == curPre)
			tail = cur;
		cur->setlink(curPre->getlink());
		delete curPre;
		if (curPre != NULL)
			return true;
		else
			return false;
	};
	
};

//有序链表的合并
int main() {
	
	list<int> listfirst;
	list<int> listsecond;
	listfirst.addtail(1);
	listfirst.addtail(6);
	listfirst.addtail(8);
	listfirst.addtail(9);
	listfirst.addtail(13);
	listsecond.addtail(0);
	listsecond.addtail(3);
	listsecond.addtail(4);
	listsecond.addtail(6);
	listsecond.addtail(7);
	while (listsecond.getcount()!=0)//listsecond非空时持续循环
	{
		int indexfirst = 0;
		while (listsecond.getat(0)>listfirst.getat(indexfirst))
		{
			++indexfirst;
			if (indexfirst == listfirst.getcount()) {
				break;
			}
		}
		if (indexfirst == listfirst.getcount()) {
			listfirst.addtail(listsecond.getat(0));
			listsecond.removeat(0);
		}
		else {
			listfirst.insertat(indexfirst, listsecond.getat(0));
			listsecond.removeat(0);
		}
	}
	for (int i = 0;i < listfirst.getcount();++i)
		cout << listfirst.getat(i) << " ";
	return 0;
	
}