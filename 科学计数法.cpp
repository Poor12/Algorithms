#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
using namespace std;

//科学计数法
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	string inStr, subStr1, subStr2;
	char flag;   // 指数的符号
	int pos;   // 记录'E'字符的位置
	cin >> inStr;
	if ('-' == inStr[0])
		cout << "-";  // 小数符号位
	pos = inStr.find('E', 0);//从第0个位置开始找，包含第0个
	subStr1 = inStr.substr(1, pos - 1);//包含1和pos-1
	flag = inStr[pos + 1];
	//cout<<pos + 2<<" " <<subStr1.size() - 2 - pos<<endl;
	subStr2 = inStr.substr(pos + 2, subStr1.size() - 2 - pos);
	//cout << subStr2 << endl;
	int n = atoi(subStr2.c_str());
	subStr1.erase(subStr1.find('.'), 1);
	int len = subStr1.size();
	if ('+' == flag) {
		if (n >= 0 && n < len - 1)
			subStr1.insert(n + 1, 1, '.');
		else
			subStr1.insert(len, n - len + 1, '0');
		cout << subStr1;
	}
	else {
		if (0 == n) {
			subStr1.insert(1, 1, '.');
			cout << subStr1;
		}
		else {
			cout << "0." << setfill('0') << setw(len + n - 1) << subStr1;
		}
	}

	return 0;
}