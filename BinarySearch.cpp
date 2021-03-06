#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
	二分查找
*/
int binarySearch(const vector<int> &a, const int &x, int low, int high) {
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (a[mid] < x)
		return binarySearch(a, x, mid + 1, high);
	else if (a[mid] > x)
		return binarySearch(a, x, low, mid - 1);
	else
		return mid;
}
int binarySearch3(const vector<int> &a, const int &x, int low, int high) {//low、high取不到
	if (low +1>= high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (a[mid] < x)
		return binarySearch(a, x, mid , high);
	else if (a[mid] > x)
		return binarySearch(a, x, low, mid );
	else
		return mid;
}
int binarySearch1(const vector<int> &a, const int &x, int low, int high) {//low、high取的到
	while (low<=high)
	{
		int mid = (low + high) / 2;
		if (a[mid] < x)
			low = mid + 1;
		else if (a[mid] > x)
			high = mid - 1;
		else
		{
			return mid;
		}
	}
	return -1;
}
int binarySearch2(const vector<int> &a, const int &x, int low, int high) {
	while (low +1< high)
	{
		int mid = (low + high) / 2;
		if (a[mid] < x)
			low = mid;
		else if (a[mid] > x)
			high = mid;
		else
		{
			return mid;
		}
	}
	return -1;

}
int main() {
	vector<int> a = { 1,2,3,4 };
	cout<<binarySearch3(a, 2, 0-1, a.size());
}