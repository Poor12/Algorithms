//计数排序 O(n)
//首先建立临时表T，初始化为0，扫描每一个元素，将每个元素出现的次数填入T
//根据临时表建立定位表K
//K(i)=T(i) i=1;K(i)=T(i)+K(i-1) k>=i>1
/*
	V 4 5 3 3 1 4
	T 1 0 2 2 1
	K 1 1 3 5 6
*/
//从后往前遍历V，顺序得到vi，根据定位表得到对应的K(vi),即为输出位置，输出后将K(vi)--
void countsort(int a[], int len, int max) {
	int *mark = new int[max];
	int *result = new int[len];
	memset(result, 0, sizeof(result));
	memset(mark, 0, sizeof(mark));
	for (int i = 0;i < len;++i)
		mark[a[i]]++;
	for (int i = 1;i < max;++i)
		mark[i] += mark[i - 1];
	for (int i = len - 1;i >= 0;--i) {
		result[mark[a[i]] - 1] = a[i];
		mark[a[i]]--;
	}
	delete[] mark;
}