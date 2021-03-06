#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
using namespace std;

struct node
{
	int x;       //记录下当前的序号
	int next;   //记录下下一个节点的地址
	int index;   //记录下当前的地址
};
node list_ans[100000];
int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	 //以数组来作为数据结构承载链表
	int first_add = 0, N = 0, K = 0, temp_address = 0;
	int i = 0, j = 0, k = 0;
	stack<node> sta;
	cin >> first_add >> N >> K;
	for (i = 0; i < N; i++)                         //输入数据
	{
		cin >> temp_address;
		list_ans[temp_address].index = temp_address;
		cin >> list_ans[temp_address].x;
		cin >> list_ans[temp_address].next;
	}
	int  pre = first_add;  //检查数据长度，链表的总长度（坑点不一定为N）
	while (pre != -1)
	{
		k++;
		pre = list_ans[pre].next;
	}
	N = k;       //更新N
	pre = first_add;
	int res = N % K, iter = N / K;   //计算需要翻转的次数，以及最后会剩下多少数
	bool first = true;
	node temp_node;
	for (i = 0; i < iter; i++)    //需要进行翻转次数的计数
	{
		for (j = 0; j < K; j++)   //从起始地址开始进行入栈操作，进入K个
		{
			sta.push(list_ans[pre]);
			pre = list_ans[pre].next;
		}
		while (!sta.empty())
		{
			temp_node = sta.top();    //出栈操作，第一个出栈的与后序出栈的操作不同，分开处理
			sta.pop();
			if (first)
			{
				cout << setfill('0') << setw(5) << temp_node.index << " " << temp_node.x;
				first = false;
			}
			else
			{
				cout << " " << setfill('0') << setw(5) << temp_node.index << endl;
				cout << setfill('0') << setw(5) << temp_node.index << " " << temp_node.x;
			}
		}
	}
	//非翻转的数据进行如下的顺序输出即可
	for (j = 0; j < res; j++)
	{
		temp_node = list_ans[pre];
		pre = list_ans[pre].next;
		if (first)
		{
			cout << setfill('0') << setw(5) << temp_node.index << " " << temp_node.x;
			first = false;
		}
		else
		{
			cout << " " << setfill('0') << setw(5) << temp_node.index << endl;
			cout << setfill('0') << setw(5) << temp_node.index << " " << temp_node.x;
		}
	}
	//最后补上空格和 -1 的操作
	cout << " " << -1;
	return 0;
}


