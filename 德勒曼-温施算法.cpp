//德勒曼-温施算法，字符串编辑距离
//编辑距离即指一个字串变成另一个字串所需的最少编辑次数，一次编辑可以是添加一个字符、删除一个字符和修改一个字符
//定义一个edit(i,j)，表示一个长度为i的字串到长度为j的字串所需的最少编辑次数
//显然，if i==j==0 edit(i,j)=0
//if i==0且j>0 edit(i,j)=j
//if i>0且j==0 edit(i,j)=i
//if i>=1且j>=1 edit(i,j)=min{edit(i-1,j)+1,edit(i,j-1)+1,edit(i-1,j-1)+f(i,j)},当第1个字符串的第i个字符不等于第2个字符串的第j个字符时，f(i,j)=1;否则，f(i,j)=0
#include <string>
using namespace std;
int min(int a, int b)
{
	return a < b ? a : b;
}
int edit(string str1, string str2)
{
	int max1 = str1.size();
	int max2 = str2.size();
	int **ptr = new int*[max1 + 1];
	for (int i = 0;i < max1 + 1;++i)
		ptr[i] = new int[max2 + 1];
	for (int i = 0;i < max1 + 1;i++)
		ptr[i][0] = i;
	for (int i = 0;i < max2 + 1;++i)
		ptr[0][i] = i;
	for(int i=1;i<max1+1;++i)
		for (int j = 1;j < max2 + 1;++j)
		{
			int d;
			int temp = min(ptr[i - 1][j] + 1, ptr[i][j - 1] + 1);
			if (str1[i - 1] == str2[j - 1])
				d = 0;
			else
			{
				d = 1;
			}
			ptr[i][j] = min(temp, ptr[i - 1][j - 1] + d);
		}
	cout << "**************************" << endl;
	for (int i = 0;i < max1 + 1;++i)
	{
		for (int j = 0;j < max2 + 1;++j)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "****************************" << endl;
	int dis = ptr[max1][max2];
	for (int i = 0;i < max1 + 1;++i)
	{
		delete[] ptr[i];
		ptr[i] = NULL;
	}

	delete[] ptr;
	ptr = NULL;
	return dis;
}
int main() {
	string str1 = "sailing";
	string str2 = "failing";
	int r = edit(str1, str2);
	cout << "the dis is " << r;
}