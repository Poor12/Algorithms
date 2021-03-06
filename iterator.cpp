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
template <class T> class iterator {
	listnode<T>* cur;
public:
	iterator() :cur(NULL) {};
	iterator(listnode<T>*point) :cur(point) {}
	listnode<T>*& getcur() {
		return cur;
	}
	friend T operator ++(iterator& it) {//前缀
		it.getcur() = it.getcur()->getlink();
		T data;
		data = it.getcur()->getdata();
		return data;
	}
	friend T operator ++(iterator& it, int) {
		T data;
		data = it.getcur()->getdata();
		it.getcur() = it.getcur()->getlink();
		return data;
	}
	friend bool operator ==(iterator& it, listnode<T>* point) {
		return it.getcur() == point;
	}
	friend bool operator !=(iterator& it, listnode<T>* point) {
		return it.getcur() != point;
	}
	friend ostream& operator<<(ostream& stream, iterator& it) {
		stream << it.getcur()->getdata();
		return stream;
	}
	void operator=(listnode<T>* point) {
		cur = point;
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
		while (current != NULL)
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
int main() {
	iterator<int> a;
	list<int> listfirst;
	a = listfirst.getnodeat(0);
	while (a!=listfirst.getnodeat(listfirst.getcount()-1))
	{
		++a;
		cout << a;
	}
	return 0;	
}