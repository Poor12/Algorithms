#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//手算除法
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	string a;
	int q;//商
	int b, r = 0;//r为余数
	int current;
	cin >> a >> b;
	for (int i = 0;i < a.length();i++)
	{
		current =r*10+ a[i] - '0';
		q = current / b ;
		r = current % b;
		if (i == 0 && q==0 )
			continue;
		else
		{
			cout << q;
		}
	}
	cout << " ";
	cout << r;
	return 0;
}