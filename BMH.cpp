#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
using namespace std;
/*
	BMH算法 改进算法之一，只使用坏字符，当坏字符出现时，偏移本次匹配中模式字符串最右的字符的偏移量
	BMHS略
	
*/
const int maxchar = 256;
void PreProcess(const char *patt, int m, int bmbc[]) {
	int k = 0;
	for (k = 0;k < maxchar;++k)
		bmbc[k] = m;
	for (k = 0;k < m - 1;++k)
		bmbc[patt[k]] = m - k - 1;
}

int BMS(string t, string p) {
	int bmbc[maxchar];
	int m = p.length();
	int n = t.length();
	if (m > n)
		return -1;
	const char *patt = p.c_str();
	const char *text = t.c_str();
	PreProcess(patt, m, bmbc);
	int k = m - 1;
	while (k<n)
	{
		int j = m - 1;
		int i = k;
		while (j>=0&&text[i]==patt[j])
		{
			j--;
			i--;
		}
		if (j == -1)
			return i + 1;
		k += bmbc[text[k]];

	}
	return -1;
}

int main()
{
	cout << BMS("GCATCGCAGAGAGTATACAGTACG", "GCAGAGAG");
	return 0;
}