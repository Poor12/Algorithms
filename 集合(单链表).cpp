//集合 单链表
template <class T> class listset;
template <class T> class listnode {
	friend class listset<T>;
	T data;
	listnode<T> *link;
public:
	listnode() :link(NULL) {}
	listnode(T value) :link(NULL), data(value) {}
};

template <class T> class listset {
	listnode<T> *head;
	listnode<T> *tail;
public:
	listset() {//创建空集合
		this->head = new listnode<T>();
		this->tail = this->head;
	}
	bool isempty() {
		return head == tail;
	}
	void makeempty() {
		listnode<T> *current = head->link;
		listnode<T> *del = NULL;
		while (head->link!=NULL)
		{
			head->link = current->link;
			del = current;
			current = current->link;
			delete del;
		}
		tail = head;
	}
	~listset() {
		makeempty();
		delete head;
	}
	void add(T value) {
		listnode<T> *add = new listnode<T>(value);
		listnode<T> *precurrent = head;
		listnode<T> *current = precurrent->link;//记录当前节点的前驱节点以及当前节点
		while (current!=NULL&&current->data<value)
		{
			precurrent = current;
			current = current->link;
		}
		if (head == tail && current == NULL)//向空链表插入
		{
			head->link = add;
			tail = add;
		}
		if (head != tail && current == NULL) {//向链表尾插入
			precurrent->link = add;
			//add->link = NULL;
			tail = add;
		}
		if (current != NULL && current->data == value)//链表中已存在
		{
			return;
		}
		if (current != NULL && current->data > value) {
			precurrent->link = add;
			add->link = current;
		}
	}
	void del(T del) {
		listnode<T>* precurrent = head;
		listnode<T>* current = head->link;
		while (current!=NULL&&current->data!=del)
		{
			precurrent = current;
			current = precurrent->link;
		}
		if (current != NULL) {
			precurrent->link = current->link;
			if (current->link == NULL) tail = precurrent;
			delete current;
		}
	}
	listnode<T> *gethead() {
		return head;
	}
	listnode<T>& operator+(listset<T>& another) {
		listset<T>* tmpset = new listset(another);
		listnode<T>* current = this->head->link;
		while (current!=NULL)
		{
			tmpset->add(current->data);
			current = current->link;
		}
		return *tmpset;
	}
	listnode<T>& operator-(listset<T>& another) {
		listset<T>* tmpset = new listset(*this);
		listnode<T>* current = this->head->link;
		while (current != NULL)
		{
			tmpset->del(current->data);
			current = current->link;
		}
		return *tmpset;
	}
	listnode<T>& operator*(listset<T>& another) {//a∩b=a-（a-b）
		listset<T>* tmpset = new listset(*this);
		*tmpset = *this - another;
		*tmpset = *this - *tmpset;
		return *tmpset;
	}
	bool operator==(listset<T>& another) {
		listnode<T>* current1 = head->link;
		listnode<T>* current2 = another.head->link;
		while (current1!=NULL)
		{
			if (current2 == NULL) return false;
			if (current1->data != current2->data) return false;
			current1 = current1->link;
			current2 = current2->link;
		}
		if (current2 != NULL) return false;
		return true;
	}
	void output() {};//省略
	listset(listset& lset) {
		this->head = new listnode<T>();
		this->tail = this->head;
		listnode<T> *current = lset.head->link;
		while (current!=NULL)
		{
			add(current->data);
			current = current->link;
		}
	}
};
