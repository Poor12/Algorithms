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
template <class T> class cirlist {
	listnode<T> *head;
	listnode<T> *tail;
	listnode<T> *cur;
public:
	cirlist() {
		head = new listnode<T>();
		tail = head;
		head->setlink(head);
	}
	~cirlist() {
		removeall();
		delete head;
	}
	bool isempty() {
		return head==tail;
	}
	void setbegin() {
		cur = head;
	}
	void removeall() {
		setbegin();
		int length = getcount();
		for (int i = 0;i < length;++i) {
			removethis();
		}
		cur = head;
	}
	void removethis() {
		if (cur == head)
			cur = cur->getlink();
		listnode<T>* precur = cur;
		listnode<T>* node_del = cur;
		for (int i = 0;i < this->getcount();++i) {
			precur = precur->getlink();
		}
	}

	bool addtail(T value) {
		listnode<T> *add = new listnode<T>(value);
		tail->setlink(add);
		tail = tail->getlink();
		tail->setlink(head);
		if (tail != NULL)
			return true;
		else
			return false;
	}
	
	int getcount() {
		int count = 0;
		if (cur == NULL)
			this->setbegin();
		listnode<T>*here = cur;
		while (cur->getlink()!=here)
		{
			cur = cur->getlink();
			++count;
		}
		cur = cur->getlink();
		return count;
	}
	T getnext() {
		if (cur == head) {
			cur = cur->getlink();
		}
		T num = cur->getdata();
		cur = cur->getlink();
		return num;
	}
	
	
	
};

int main() {
	
	return 0;	
}