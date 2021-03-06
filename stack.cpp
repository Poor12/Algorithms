//顺序栈
template <class T> class arraystack {
	int size;
	int tos;
	T* contain;
public:
	arraystack() :size(0), tos(-1), contain(NULL) {}
	arraystack(int maxsize) {
		size = maxsize;
		tos = -1;
		contain = new T[size];
	}
	void push(T& element) {
		assert(tos != size - 1);
		contain[++tos] = element;
	}
	T& gettop() {
		assert(tos != -1);
		return contain[tos];
	}
	T& pop() {
		assert(tos != -1);
		return contain[tos--];
	}
	bool isempty() {
		return tos ==-1;
	}
	void makeempty() {
		tos = -1;
	}
};

//链式栈
template <class T> class linkstacknode {
public:
	T data;
	linkstacknode<T>* link;
	linkstacknode(T& value) :link(NULL), data(value) {}
};
template <class T> class linkstack {
	linkstacknode<T> *tos;
public:
	linkstack() :tos(NULL) {}
	void push(T& value) {
		linkstacknode<T>*add = new linkstacknode<T>(value);
		add->link = tos;
		tos = add;
	}
	T& gettop() {
		return tos->data;
	}
	T pop() {
		assert(tos != NULL);
		linkstacknode<T>*old = tos;
		tos = tos->link;
		T data = old->data;
		delete old;
		return data;
	}
	bool isempty() {
		return tos == null;
	}
	void makeempty() {
		while (!this->isempty()) {
			this->pop();
		}
	}
};