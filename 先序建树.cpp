struct node
{
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = 0;
		right = 0;
	}
};
int num = 0;
int s[] = { 5,7,-1,6,-1,-1,3,-1,-1 };
void precreate(node* &root)
{
	if (s[num] == -1)
	{
		num++;
		return;
	}
	if (root ==0)
	{
		root = new node(s[num++]);
	}
	precreate(root->left);
	precreate(root->right);
}
void precreate(node* &root,int &num)
{
	if (s[num] == -1)
	{
		return;
	}
	if (root == 0)
	{
		root = new node(s[num]);
	}
	precreate(root->left,++num);
	precreate(root->right,++num);
}