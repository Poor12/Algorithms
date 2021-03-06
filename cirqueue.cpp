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

