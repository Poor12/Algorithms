//shell排序 不稳定
void shellsort(int a[],int len) {
	int insertnum;
	int gap = len / 2;
	while (gap)
	{
		for (int i = gap;i < len;++i) {
			insertnum = a[i];
			int j = i;
			while (j>=gap&&insertnum<a[j-gap])
			{
				a[j] = a[j - gap];
				j -= gap;
			}
			a[j] = insertnum;
		}
		gap /= 2;
	}
}