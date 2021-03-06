// MP算法 : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
  f(j)失效函数 定义域为0-len(p)-1 值域属于{x|0<=x<j},且k是满足条件p0…pk=pj-k…pj的最大正整数
  例如j=0时，由于k不存在，k=-1;j=1时,p0!=p1,k=-1.....j=4时，p0=p4,p0p1!=p3p4,p0p1p2!=p2p3p4,p0p1p2p3!=p1p2p3p4,k=0.....
  当模式字符串在第j位失配时，将模式字符串的首字符指针指向目标字符串失配的那一位，且下次匹配从p[f(j-1)+1]开始匹配
  mpnext存储的是失配发生时进行下一轮比较过程中的模式p的起始比较地址。
  mpnext[i]=f[i-1]+1,mpnext递增只能以1为单位
  *j=7是有意义的
   模式字符串p的长度为m，目标字符串T的长度为n，时间复杂度为O(m+n)
*/
void preMp(const char *x, int m, int mpNext[]) {
	int i, j;
	i = 0;
	j = mpNext[0] = -1;
	while (i<m)
	{
		while (j>-1&&x[i]!=x[j])
		{
			j = mpNext[j];
		}
		mpNext[++i] = ++j;
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
	int *mpNext = new int[m+1];
	preMp(x, m, mpNext);
	while (j<n)
	{
		while (i>-1&&x[i]!=y[j])
		{
			i = mpNext[i];
		}
		i++;
		j++;
		if (i >= m) {
			cout << "Matching index found at: " << j - i << endl;
			i = mpNext[i];//确保找到多组解
		}
	}
	delete[]mpNext;
}
int main() {
	mp("caatcat", "ctcaatcacaatcat");//例
}
