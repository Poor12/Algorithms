//史密斯沃特曼算法
//1.确定置换矩阵和空位罚分方法
//s(a,b):组成序列的元素间的相似性得分，匹配+3，不匹配-3
//wk：长度为k的空位罚分，wk=kw1，w1=2
//2.创建得分矩阵
//3.从左到右、从上到下填充得分矩阵
//Hij=max(H(i-1,j-1)+s(ai,aj),max(H(i-k,j)-wk),max(H(i,j-k)-wk),0)
//4.回溯	
#include <string>
#include <algorithm>
using namespace std;
#include <limits.h>
#include <stack>
stack<char> ii,jj;
struct node {
	int data;
	int parent;
	node() {
		data = 0;
		parent = -1;
	}
};
int min(int a, int b)
{
	return a < b ? a : b;
}
int edit(string str1, string str2)
{
	int max1 = str1.size();
	int max2 = str2.size();
	int s;
	node **ptr = new node*[max1 + 1];
	for (int i = 0;i < max1 + 1;++i)
		ptr[i] = new node[max2 + 1];
	for (int i = 0;i < max1 + 1;i++)
		ptr[i][0] = node();
	for (int i = 0;i < max2 + 1;++i)
		ptr[0][i] = node();
	for (int i = 1;i < max1 + 1;++i)
		for (int j = 1;j < max2 + 1;++j)
		{
			int MAXJ = INT32_MIN;
			for (int k = 1;k <= j;++k)
			{
				if (ptr[i][j - k].data-k*2 > MAXJ)
					MAXJ = ptr[i][j - k].data-k*2;
			}
			int MAXI = INT32_MIN;
			for (int l = 1;l <= i;++l)
			{
				if (ptr[i - l][j].data - l * 2 > MAXI)
					MAXI = ptr[i - l][j].data - l * 2;
			}
			if (str1[i - 1] == str2[j - 1])
				s = 3;
			else
				s = -3;
			ptr[i][j].data = max(max(max(ptr[i - 1][j - 1].data + s, MAXI),MAXJ),0);
			if (ptr[i][j].data == MAXI)
				ptr[i][j].parent = 1;
			else if (ptr[i][j].data == MAXJ)
				ptr[i][j].parent = 2;
			else if (ptr[i][j].data == ptr[i - 1][j - 1].data + s)
				ptr[i][j].parent = 0;
			else
				ptr[i][j].parent = 3;
		}
	cout << "**************************" << endl;
	for (int i = 0;i < max1 + 1;++i)
	{
		for (int j = 0;j < max2 + 1;++j)
		{
			cout << ptr[i][j].data << " ";
		}
		cout << endl;
	}
	cout << "****************************" << endl;
	int MAX = INT32_MIN,maxi,maxj;
	for(int i=0;i<max1+1;++i)
		for (int j = 0;j < max2 + 1;++j)
		{
			if (ptr[i][j].data > MAX)
			{
				MAX = ptr[i][j].data;
				maxi = i;
				maxj = j;
			}
		}
	node item = ptr[maxi][maxj];
	while (item.data!=0)
	{
		if (item.parent == 0)
		{
			ii.push(str1[maxi - 1]);
			jj.push(str2[maxj - 1]);
			item = ptr[--maxi][--maxj];
		}
		else if (item.parent == 1)
		{
			ii.push(str1[maxj - 1]);
			jj.push(' ');
			item = ptr[maxi][--maxj];
		}
		else if (item.parent == 2)
		{
			ii.push(' ');
			jj.push(str2[maxj - 1]);
			item = ptr[maxi][--maxj];
		}
	}
	for (int i = 0;i < max1 + 1;++i)
	{
		delete[] ptr[i];
		ptr[i] = NULL;
	}

	delete[] ptr;
	ptr = NULL;
	return MAX;
}
int main() {
	string str1 = "sailing";
	string str2 = "failing";
	int r = edit(str1, str2);
	cout << "the dis is " << r << endl;
	cout << "str1: ";
	while (!ii.empty())
	{
		char s = ii.top();
		ii.pop();
		cout << s;
	}
	cout << endl << "str2: ";
	while (!jj.empty())
	{
		char s = jj.top();
		jj.pop();
		cout << s;
	}
}
