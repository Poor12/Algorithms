#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//最大公约数问题

//递归中单向递归与尾递归可以直接用迭代，其他需使用栈
int gcd(int a, int b) {	//尾递归，即递归调用结束后程序就结束，返回上一个递归调用的下一句，也是程序的结束，因此可使用迭代
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
int main()
{
	return 0;
}