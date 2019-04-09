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
using namespace std;

int main()
{
	
	//freopen("D:\\data.txt", "r", stdin);
	/*
	string str1(5, 'c');
	string str2("now is the time....");
	string str3(str2, 11, 4);//从str2开始4位
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	string	str = "hello world";
	str.append(10, '!');//10个'!'
	cout << str << endl;

	string str1, str2 = "war and peace";
	str1.assign(str2, 4, 3);
	cout << str1 << endl;
	
	string text = "abcdef";
	string text1 = "abcdee";
	string text3 = "abcdeg";
	char ch = text.at(2);
	cout << ch;
	
	const char *text2 = text.c_str();
	cout << text2;

	cout << text.compare(text2)<<" "<<text.compare(text1)<<text.compare(text3);//大于1，小于-1
	const char *da = text.data();//第一个字符的指针

	cout << text.empty();

	string s("So, you like donuts, eh? Well, have all the donuts in the world!");
	cout << "The original string is '" << s << "'" << endl;

	s.erase(50, 14);//从50开始14个
	cout << "Now the string is '" << s << "'" << endl;

	s.erase(24);//从24开始所有
	cout << "Now the string is '" << s << "'" << endl;

	s.erase();//删除所有
	cout << "Now the string is '" << s << "'" << endl;
	
	string str1("Alpha Beta Gamma Delta");
	unsigned int loc = str1.find("Omega", 0);
	cout << loc << endl;
	if (loc != string::npos)
		cout << "Found Omega at " << loc << endl;
	else
		cout << "Didn't find Omega" << endl;

	//用str中的num个字符替换本字符串中的字符,从index开始
	string s = "They say he carved it himself...from a BIGGER spoon";
	string s2 = "find your soul-mate, Homer.";

	s.replace(32, s2.length(), s2);

	cout << s << endl;

	//返回最后一个与str中的字符匹配的字符
	int loc;
	string s = "My cat's breath smells like cat food.";

	loc = s.rfind("breath", 8);
	cout << "The word breath is at index " << loc << endl;

	loc = s.rfind("breath", 20);
	cout << "The word breath is at index " << loc << endl;

	//子串
	string s("What we have here is a failure to communicate");

	string sub = s.substr(21);

	cout << "The original string is " << s << endl;
	cout << "The substring is " << sub << endl;
	*/
	string first("This comes first");
	string second("And this is second");
	first.swap(second);
	cout << first << endl;
	cout << second << endl;
	//first.insert(0, second);//first的0位置插入second
	auto it=first.insert(first.begin(), 'A');//迭代器前插入A
	cout << first << endl;;
	return 0;
	
}

