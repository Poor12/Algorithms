class node {
public:
	int element;
	node* left;
	node* right;
	node(int elem, node* lt, node* rt) :element(elem), left(lt), right(rt) {};
};
class BST {
public:
	node *root;
	node* find(int x, node* t) {
		while (t!=NULL)
		{
			if (x < t->element)
				t = t->left;
			else if (x > t->element)
				t = t->right;
			else
				return t;
		}
		return t;
	}
	node* findmax(node *t) {
		if (t != NULL) {
			while (t->right!=NULL)
			{
				t = t->right;
			}
		}
		return t;
	}
	node* findmin(node *t) {
		if (t != NULL) {
			while (t->left != NULL)
			{
				t = t->left;
			}
		}
		return t;
	}
	void insert(int x, node *&t) {
		if (t == NULL)
			t = new node(x, NULL, NULL);
		else if (x < t->element)
			insert(x, t->left);
		else if (x > t->element)
			insert(x, t->right);
		else {
			return;
		}
	}
	void removemin(node* &t) {
		if (t == NULL) {
			return;
		}
		else if (t->left != NULL)
			removemin(t->left);
		else if(t->left==NULL)
		{
			node* tmp = t;
			t = t->right;
			delete tmp;
		}
	}
	void remove(int x, node* &t) {
		if (t == NULL)
			return;
		if (x < t->element)
			remove(x, t->left);
		else if (x > t->element)
			remove(x, t->right);
		else if (t->left != NULL && t->right != NULL) {
			t->element = findmin(t->right)->element;
			removemin(t->right);
		}
		else
		{
			node* tmp = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete tmp;
		}
	}

};