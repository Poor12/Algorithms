// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  KMP算法

#include "pch.h"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
/*
	j    0  1  2  3  4  5  6  7 
	p(j) c  a  a  t  c  a  t
	f(j) -1 -1 -1 -1 0  1  -1
  mpnext -1 0  0  0  0  1  2  0
 kmpnext -1 0  0  0  -1 0  2  0
	kmpnext规则的四种情况：
	(1)如果mpnext[j]=0且pj=p0，则令kmpnext[j]=-1
	(2)如果mpnext[j]=0且pj!=p0，则令kmpnext[j]=0
	(3)如果mpnext[j]!=0且pj!=pmpnext[j]，则令kmpnext[j]=mpnext[j]
	(4)如果mpnext[j]!=0且pj=pmpnext[j]，则用mpnext[j]的值替换原来mpnext[j]中的j值，直到情况转换成前三种情况中的一种
	Tips:
	(1)对于kmpnext[j]=-1,表示模式字符串P中，字符pj与首字符相同，且pj前面k个字符与模式字符串开头k个字符不相等，或者相等但pk!=pj,其中j!=0
	(2)对于kmpnext[j]=k,表示模式字符串P中，字符pj前面k个字符与模式字符串开头的k个字符相等，且pj!=pk
	(3)其他情况都为0
	*关键的提升在于保证失配字符与相同前缀之后的那个字符是否相等
	O(m+n)
*/
void preKmp(const char *x, int m, int kmpNext[]) {
	int i, j;
	i = 0;
	j = kmpNext[0] = -1;
	while (i<m)
	{
		while (j>-1&&x[i]!=x[j])
		{
			j = kmpNext[j];
		}
		i++;
		j++;
		if (x[i] == x[j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;//这一步同mp算法
	}
}
void mp(string p, string t) {
	int m = p.length();
	int n = t.length();
	if (m > n) {	
		cerr << "Unsuccessful match!" << endl;
		return;
	}
	const char *x = p.c_str();//返回指向C字符数组的指针常量
	const char *y = t.c_str();
	int i = 0, j = 0;
	int *kmpNext = new int[m+1];
	preKmp(x, m, kmpNext);
	i = j = 0;
	while (j<n)
	{
		while (i>-1&&x[i]!=y[j])
		{
			i = kmpNext[i];
		}
		i++;
		j++;
		if (i >= m) {
			cout << "Matching index found at: " << j - i << endl;
			i = kmpNext[i];//确保找到多组解
		}
	}
	delete[]kmpNext;
}
int main() {
	mp("caatcat", "ctcaatcacaatcat");//例
}

