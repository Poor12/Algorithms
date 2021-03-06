//优先队列
template <class T> class priqueuenode {
public:
	T data;
	priqueuenode<T> *link;
	priqueuenode(T& value) :data(value), link(NULL) {}
};
template <class T> class priqueue {
	priqueuenode<T>* front;
	priqueuenode<T>* back;
public:
	priqueue() :front(NULL), back(NULL) {}
	void enqueue(T& element) {
		priqueuenode<T>* add = new priqueuenode<T>(value);
		if (front == NULL)
			front = back = add;
		else {
			back->link = add;
			back = back->link;
		}
	}
	T delqueue() {
		priqueuenode<T>* seek = front->link;//遍历队列，寻找最小元素的指针
		priqueuenode<T>* min = front;//指向最小元素的指针
		T mindata;
		while (seek != NULL) {
			if (seek->data < min->data)
				min = seek;
			seek = seek->link;
		}
		seek = front;
		while (seek != NULL&&seek->link!=min)//寻找最小元素的前驱节点
		{
			seek = seek->link;
		}
		if (seek == NULL)
		{
			mindata = front->data;
			front = front->link;
			delete min;
		}
		if (min->link == NULL)
			back = seek;
		if (seek != NULL) {
			mindata = min->data;
			seek->link = min->link;
			delete min;
		}
		return mindata;
	}
	bool isempty() {
		return front == NULL;
	}
	T& getfront() {
		assert(!this->isempty());
		return front->data;
	}
	void makeempty() {
		while (!isempty())
		{
			this->delqueue();
		}
	}
};