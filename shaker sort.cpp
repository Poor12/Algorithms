/*
void swap(int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
*/
int main() {
	cin >> n;
	for (int i = 0;i <n;++i)
		cin >> a[i];
	int i, left = 0, right = n - 1, shift = 0;
	while (left<right)
	{
		for (i = left;i < right;++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				shift = i;
			}
		}
		right = shift;
		for (i = right;i > left;--i) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				shift = i;
			}
		}
		left = shift;
	}
	for (int i = 0;i < n;++i)
		cout<<a[i];
	//system("pause");
	return 0;
}