#include <iostream>
using namespace std;
int main(){
	//长整数取每一位,逆序
	int a = 132123123;
	for (int i = 10, j = 1;a / j != 0;i *= 10, j *= 10)
	{
		int x = a % i / j;
		cout << x << " ";
	}

	int r1 = 0,c=5;
	for (int i = 0;i < c;++i)
	{
		r1 = r1 * 10 + c;
	}
	cout << r1;
}