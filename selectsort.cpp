//选择排序，最小的元素置于首位 O(n^2)
void selectsort(int a[], int n) {
	int k;
	for (int i = 0;i < n;++i) {
		k = i;
		for (int j = j + 1;j < n;++j) {
			if (a[j] > a[i])
				swap(a[j], a[i]);
		}
	}
}