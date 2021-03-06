//二分插入排序 扑克牌
void insertsort(int a[],int len) {
	int middle;
	for (int i = 1;i < len;++i) {
		int insertNum = a[i];
		int left = 0;
		int right = i - 1;
		while (left<=right)
		{
			middle = (left + right) / 2;
			if (insertNum > a[middle]) left = middle + 1;
			else right = middle - 1;
		}
		for (int j = i;j > left;j--)
			a[j] = a[j - 1];
		a[left] = insertNum;
	}
}