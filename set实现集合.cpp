//使用set实现集合
#include <set>
#include <algorithm>
#include <iterator>
int main() {
	set<int> myset2;
	set<int> myset3;
	int a[] = { 1,2,3,4,5 };
	set<int> myset1(a, a + 5);
	cout << myset1.size() << endl;
	auto i = myset1.begin();
	cout << "myset1: ";
	while (i != myset1.end()) {
		cout << *i << " ";
		++i;
	}
	myset2.insert(2);
	myset2.insert(3);
	myset2.insert(5);
	myset2.insert(7);
	cout << endl;
	i = myset2.begin();
	cout << "myset2: ";
	while (i != myset2.end()) {
		cout << *i << " ";
		++i;
	}
	ostream_iterator<int> out(cout, " ");
	cout << "\nmyset1与myset2的交集：";
	set_intersection(myset1.begin(), myset1.end(), myset2.begin(), myset2.end(), out);
	cout << "\nmyset1与myset2的并集：";
	set_union(myset1.begin(), myset1.end(), myset2.begin(), myset2.end(), out);
	cout << "\nmyset1与myset2的差：";
	set_difference(myset1.begin(), myset1.end(), myset2.begin(), myset2.end(), out);
	cout << "\nmyset1与myset2的对称差：";
	set_symmetric_difference(myset1.begin(), myset1.end(), myset2.begin(), myset2.end(), out);
	//set_symmetric_difference(myset1.begin(), myset1.end(), myset2.begin(), myset2.end(), inserter(myset3, myset3.begin()));
	//将对称差赋给myset3
}