//插入排序 扑克牌 O(n^2)
void insertsort(int a[],int len) {
	int insertNum;
	for (int i = 1;i < len;++i) {
		insertNum = a[i];
		int j = i;
		while (j>0&&insertNum<a[j-1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = insertNum;
	}
}