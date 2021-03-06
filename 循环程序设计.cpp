#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
#include <queue>
using namespace std;

#define LOCAL

int main()
{
#ifdef DEBUG
	freopen("D:\\data.txt", "r", stdin);
#endif // DEBUG
	int x, n = 0, s = 0;
	int min, max;
	scanf("%d", &x);
	min = max = x;
	while (scanf("%d", &x) == 1)
	{
		s += x;
		if (x < min)
			min = x;
		if (x > max)
			max = x;
		n++;
	}
	printf("%d %d %.3f\n", min, max, (double)s / n);
	return 0;
	
}