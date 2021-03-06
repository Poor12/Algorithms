//集合的表示方法之一：位向量(一维数组)
const int defaultsize = 100;
class VecSet {
	int *contain=NULL;
	int size;
public:
	VecSet(int maxsize = defaultsize){
		assert(maxsize > 0);
		size = maxsize;
		contain = new int[size];
		assert(contain != NULL);
		makeempty();
	}
	~VecSet() {
		if (contain != NULL)
			delete[]contain;
	}
	void add(int add) {
		assert(add >= 0 && add < size);
		contain[add] = 1;
	}
	void del(int del) {
		assert(del >= 0 && del < size);
		contain[del] = 0;
	}
	void makeempty() {
		for (int i = 0;i < size;i++)
			contain[i] = 0;
	}
	int getsize() {
		return size;
	}
	bool ismember(const int x) {
		assert(x >= 0 && x < size);
		return contain[x] != 0;
	}
	VecSet& operator+(VecSet& another) {
		assert(this->getsize() == another.getsize());
		VecSet* tmp = new VecSet(this->getsize());
		for (int i = 0;i < size;++i) {
			(*tmp).contain[i] = contain[i] || another.contain[i];
		}
		return *tmp;
	}
	VecSet& operator-(VecSet& another) {
		assert(this->getsize() == another.getsize());
		VecSet* tmp = new VecSet(this->getsize());
		for (int i = 0;i < size;++i) {
			(*tmp).contain[i] = contain[i] && (!another.contain[i]);
		}
		return *tmp;
	}
	VecSet& operator*(VecSet& another) {
		assert(this->getsize() == another.getsize());
		VecSet* tmp = new VecSet(this->getsize());
		for (int i = 0;i < size;++i) {
			(*tmp).contain[i] = contain[i] && (another.contain[i]);
		}
		return *tmp;
	}
	VecSet& operator=(VecSet& another) {
		assert(this->getsize() == another.getsize());
		for (int i = 0;i < size;++i) {
			contain[i] = another.contain[i];
		}
		return *this;
	}
	bool operator==(VecSet& another) {
		assert(this->getsize() == another.getsize());
		for (int i = 0;i < size;++i) {
			if (contain[i] != another.contain[i])
				return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream& stream, VecSet& set) {
		for (int i = 0;i < set.getsize();++i) {
			if (set.ismember(i))
				cout << i << " ";
		}
		cout << endl;
		return stream;
	}
};