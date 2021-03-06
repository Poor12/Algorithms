#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
using namespace std;
/*
	BM算法--坏字符与好后缀
	坏字符分为两种情况
	（1）当坏字符不存在于模式字符串中时，直接将字符串移到该坏字符所在位置之后即可
	（2）当坏字符出现在模式字符串中时，从右向左在模式串中找到第一个然后将它与坏字符对齐
	具体偏移函数的定义：
		char属于P时，bmbc[char]=min{i:1<=i<m-1,P[m-i-1]=char}
		char不属于P时，bmbc[char]=m
		模式字符串 i 0 1 2 3 4 5 6 7 
		        P[i] G C A G A G A G
		char       A C G T
		bmbc[char] 1 6 2 8
		偏移量等于bmbc[坏字符]-m+cmp+1;
		现在把bmbc表置为：
		char	   A C G T
		bmbc[char] 6 1 5 -1
		偏移量等于cmp-bmbc[坏字符]
	好后缀由两个因素决定：
	（1）该后缀在模式中除去自身外，从最右端开始再次出现的位置
	（2）在第一个因素不成立的情况下，该后缀的某个后缀同时又是模式的前缀
	（3）一二都不满足，直接全部移走
	suffixes：满足P[i-s, i] == P[m-s, m]的最大长度s。suffix[i] = s 表示以i为边界，与模式串后缀匹配的最大长度。
	构建gs表：为了防止回溯，我们应该尽量让一次移动的距离少一点。所以如果有多种匹配情况：优先匹配串中子串，其次是最大前缀，最后再是移动整个模式串。
		模式字符串 i 0 1 2 3 4 5 6 7 
		        P[i] G C A G A G A G
		   suffix[i] 1 0 0 2 0 4 0 8
		     bmgs[i] 7 7 7 2 7 4 7 1
		bmgs[i]表示好后缀为i+1-lastindex时偏移的距离，重点理解lastindex-suffix[i]

*/
int * suffixes(const string & pat)
{
	const int len = pat.length();
	int num;
	int *suff = new int[len];
	suff[len - 1] = len;
	for (int i = len - 2; i >= 0; --i)
	{
		for (num = 0; num <= i && pat[i - num] == pat[len - num - 1]; ++num);
		suff[i] = num;
	}
	return suff;
}
int * getBc(const string & pattern)
{
	//256是字符表的规模大小(ACSII)
	int *bc = new int[256];
	int len = pattern.length();

	for (int i = 0; i < 256; ++i)
		bc[i] = -1;

	for (int i = 0; i < len-1; ++i)
	{
		bc[pattern[i]] = i;
	}
	return bc;
}

int * getGs(const string & pat)
{
	const int len = pat.length();
	const int lastIndex = len - 1;
	int *suffix = suffixes(pat);
	int *gs = new int[len];
	//找不到对应的子串和前缀
	for (int i = 0; i < len; ++i)
		gs[i] = len;
	//找前缀
	for (int i = lastIndex; i >= 0; --i)
	{
		//存在我们想要的前缀
		if (suffix[i] == i + 1)
		{
			for (int j = 0; j < lastIndex - i; ++j)
			{
				if (gs[j] == len)
					gs[j] = lastIndex - i;
			}
		}
	}
	//for (int i = 0;i < len;++i)
	//		cout << gs[i];
	//找中间的匹配子串
	for (int i = 0; i < lastIndex; ++i)
	{
		//cout << lastIndex - suffix[i] << endl;
		gs[lastIndex - suffix[i]] = lastIndex - i;
	}
	
	delete[] suffix;
	return gs;
}
int bmMatch(const string & text, const string & pat)
{
	int *bc = getBc(pat);
	int *gs = getGs(pat);
	//patAt指向了当前pat和text对齐的位置
	int patAt = 0;
	//cmp指向了当前比较的位置
	int cmp;
	const size_t PATLASTID = pat.length() - 1;
	const size_t patLen = pat.length();
	const size_t textLen = text.length();
	while (patAt + patLen <= textLen)
	{
		//如果匹配成功，cmp就会来到-1的位置上
		//patAt + cmp 指向了text上当前比较的字符
		for (cmp = PATLASTID; cmp >= 0 && pat[cmp] == text[patAt + cmp]; --cmp);

		if (cmp == -1)
			break;
		else
		{
			patAt += max(gs[cmp], cmp - bc[text[patAt + cmp]]);
		}

	}
	delete[] bc;
	delete[] gs;
	return (patAt + patLen <= textLen) ? patAt : -1;
}



int main()
{
	cout << bmMatch("GCATCGCAGAGAGTATACAGTACG", "GCAGAGAG");
	return 0;
}