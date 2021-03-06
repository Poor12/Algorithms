#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
vector<int> level = { 1,2,3,4,5,6,7 };
vector<int> inorder = { 4,2,5,1,6,3,7 };
struct node
{
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data = d;
		left = 0;
		right = 0;
	}
};
node* create(vector<int> level, vector<int> in, int l1, int r1, int l2, int r2)
{
	node *bt = new node(level[l1]);
	vector<int> levell, levelr;
	int i;
	for (i = l2;i <= r2;++i)
	{
		if (level[l1] == in[i])
			break;
	}
	if (i == l2)
		bt->left = 0;
	else
	{
		for(int k=l1+1;k<=r1;++k)
			for (int j = l2;j < i;++j)
			{
				if (level[k] == inorder[j])
					levell.push_back(level[k]);
			}
		bt->left = create(levell, in, 0, levell.size() - 1, l2, i - 1);
	}
	if (i == r2)
		bt->right = 0;
	else
	{
		for(int k=l1+1;k<=r1;++k)
			for (int j = i + 1;j <=r2;++j)
			{
				if (level[k] == inorder[j])
				{
					levelr.push_back(level[k]);
				}
			}
		bt->right = create(levelr, in, 0, levelr.size() - 1, i + 1, r2);
	}
	return bt;
}
void in(node* root)
{
	if (root == 0)
		return;
	in(root->left);
	cout << root->data;
	in(root->right);
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	node* root = create(level, inorder, 0, level.size() - 1, 0, inorder.size() - 1);
	in(root);
	return 0;
}
