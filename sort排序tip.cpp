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
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>

bool compare(int &a, int &b)
{
	return a > b;
}
struct node
{
	int time;
	friend bool operator <(const node &a, const node &b)
	{
		return a.time > b.time;
	}
};
int main() {
	vector<int> a = { 1,3,2 };
	//sort(a.begin(), a.end());
	//for (int i = 0;i < a.size();++i)
		//cout << a[i] << endl;
	//sort(a.begin(), a.end(),compare);
	//for (int i = 0;i < a.size();++i)
	//	cout << a[i] << endl
	/*
	sort(a.begin(), a.end(),less<int>());
	for (int i = 0;i < a.size();++i)
		cout << a[i] << endl;
	*/
	/*
	priority_queue<int > b ;//默认大顶堆,greater从小变大
	b.push(1);
	b.push(3);
	b.push(2);
	while (!b.empty())
	{
		int bb = b.top();
		b.pop();
		cout << bb << endl;
	}
	
	*/
	priority_queue<node> qqq;//默认重载<
	node c;
	c.time = 50;
	qqq.push(c);
	c.time = 100;
	qqq.push(c);
	while (!qqq.empty())
	{
		int bb = qqq.top().time;
		qqq.pop();
		cout << bb << endl;
	}
	
	vector<node> aa;//默认重载<
//	node c;
	c.time = 50;
	aa.push_back(c);
	c.time = 100;
	aa.push_back(c);
	sort(aa.begin(), aa.end());
	for (int i = 0;i < aa.size();++i)
		cout << aa[i].time << endl;

}