﻿//线性表排序 冒泡排序
#include <string>
#include <algorithm>
const int maxn = 1100;
int n, a[maxn];
int main() {
	cin >> n;
	for (int i = 0;i <n;++i)
		cin >> a[i];
	/*
	bool flag = 1;//数据交换标志
	while (flag)
	{
		flag = 0;
		for (int i = 1;i < n;++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				flag = 1;
			}
		}
	}
	*/
	/*
	bool flag;
	for (int i = 0;i < n;++i) {
		flag = 0;
		for (int j = 0 ;j < n-i-1;++j) {
			if (a[j] > a[j + 1])
			{
				flag = 1;
				swap(a[j], a[j + 1]);
			}
		}
		if (flag == 0)
			break;
	}
	*/
	
	//system("pause");
	return 0;
}
