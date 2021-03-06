#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	BF算法-简单回溯
*/

void postfixBfMatch(const string & text, const string & pat)
{

	//patAt指向了当前pat和text对齐的位置
	int patAt = 0;
	int cmp;
	const size_t PATLAST = pat.length() - 1;
	while (patAt + pat.length() <= text.length())
	{
		cmp = PATLAST;
		//如果匹配成功，cmp就会来到-1的位置上
		for (cmp = PATLAST; cmp >= 0 && pat[cmp] == text[patAt + cmp]; --cmp);

		if (cmp == -1)
			cout << "index at: " << patAt<<endl;
		
		++patAt;
	}

	//return patAt;
}
int main()
{
	postfixBfMatch("GCATCGCAGAGAGTATACAGTACG", "AG");
	//cout << "index at: " << index;
	return 0;
}