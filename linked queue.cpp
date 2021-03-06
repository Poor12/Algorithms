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