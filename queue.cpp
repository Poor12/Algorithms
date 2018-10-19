//循环队列
template <class T> class cirqueue {
	int size;
	int front;
	int back;
	T* contain;
public:
	cirqueue() :size(0), front(0), back(0), contain(NULL) {}
	cirqueue(int maxsize) :size(maxsize + 1), front(0), back(0) {
		contain = new T[maxsize + 1];
	}
	bool isfull() {
		return (back + 1) % size == front;
	}
	void enqueue(T& element) {
		assert(!isfull());
		contain[back] = element;
		back = (back + 1) % size;
	}
	T& delqueue() {
		int old = front;
		front = (front + 1) % size;
		return contain[old];
	}
	bool isempty() {
		return front == back;
	}
	T& getfront() {
		assert(!isempty());
		return contain[front];
	}
	void makeempty() {
		front = back = 0;
	}
};

//链式队列
template <class T> class linkqueue {
	struct  linkqueuenode
	{
		T data;
		linkqueuenode *link;
		linkqueuenode(T& thedata, linkqueuenode* n = NULL) :data(thedata), link(n) {}
	};
	linkqueuenode* front;
	linkqueuenode* back;
public:
	linkqueue() {
		front = back = NULL;
	}
	~linkqueue()
	{
		this->makeempty();
	}
	void enqueue(T& value) {
		if (this->isempty())
			front = back = new linkqueuenode(value);
		else
			back = back->link = new linkqueuenode(value);
	}
	T delqueue() {
		linkqueuenode* old = front;
		T data = old->data;
		front = front->link;
		delete old;
		return data;
	}
	T& getfront() {
		assert(!isempty());
		return front->data;
	}
	bool isempty() {
		return front == NULL;
	}
	void makeempty() {
		while (!this->isempty()) {
			this->delqueue();
		}
	}
};