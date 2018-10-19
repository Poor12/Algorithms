//quicksort O(nlog2n) 最坏O(n^2) 最大递归层数log2(n+1) 不稳定
//（1）确定递归结束条件
//（2）从数组中选择一个基准项
//（3）创建两个子数组，小于基准项的放入第一个子数组，大于基准项的放入第二个子数组
//（4）分别对子数组递归调用
int p[10];
void qsort(int st, int ed) {//st 0 ed n-1
	if (st >= ed)
		return;
	int i, j, k = p[(st + ed) / 2];
	i = st - 1, j = ed + 1;
	do {
		do {
			++i;
		} while (p[i] < k);//不能是<=
		do
			--j;
		while (p[j]> k);
		if (i < j) {
			swap(p[i], p[j]);
		}
	} while (i < j);
	qsort(st, j);
	qsort(j + 1,ed);
}
