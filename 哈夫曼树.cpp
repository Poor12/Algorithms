#include <string>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>
typedef vector<bool> huffcode;
typedef map<char, huffcode> huffcodemap;
class inode {
public:
	const int f;
	virtual ~inode() {}
protected:
	inode(int f) :f(f) {}
};
class internalnode :public inode {
public:
	inode* const left;
	inode* const right;
	internalnode(inode* c0, inode* c1) :inode(c0->f + c1->f), left(c0), right(c1) {}
	~internalnode() {
		delete left;
		delete right;
	}
};
class leafnode :public inode {
public:
	const char c;
	leafnode(int f, char c) :inode(f), c(c) {}
};
struct nodecmp {
	bool operator()(const inode* lhs, const inode* rhs) const {
		return lhs->f > rhs->f;
	}
};
inode* buildtree(map<char, int>frequs) {
	priority_queue<inode*, vector<inode*>, nodecmp> trees;
	map<char, int>::iterator it = frequs.begin();
	for (;it != frequs.end();it++) {
		trees.push(new leafnode(it->second, it->first));
	}
	while (trees.size()>1)
	{
		inode* childr = trees.top();
		trees.pop();
		inode* childl = trees.top();
		trees.pop();
		inode* parent = new internalnode(childr, childl);
		trees.push(parent);
	}
	return trees.top();
}
void generatecodes(const inode* node, const huffcode& prefix, huffcodemap& outcodes) {
	if (const leafnode* lf = dynamic_cast<const leafnode*>(node)) {
		outcodes[lf->c] = prefix;
	}
	else if (const internalnode* in = dynamic_cast<const internalnode*>(node)) {
		huffcode leftprefix = prefix;
		leftprefix.push_back(false);
		generatecodes(in->left, leftprefix, outcodes);
		huffcode rightprefix = prefix;
		rightprefix.push_back(true);
		generatecodes(in->right, rightprefix, outcodes);
	}
}

int main() {
	map<char, int> frequs;//创建频率表
	cout << "请输入一行文本数据：" << endl;
	string str;
	getline(cin, str);
	const char* ptr = str.c_str();
	while (*ptr != '\0') {
		if (frequs.find(*ptr) != frequs.end())
			frequs[*ptr] = frequs[*ptr] + 1;
		else
			frequs[*ptr] = 1;
		*ptr++;
	}
	inode* root = buildtree(frequs);
	huffcodemap codes;
	generatecodes(root, huffcode(), codes);
	delete root;
	for (auto it = codes.begin();it != codes.end();it++) {
		cout << it->first << " ";
		copy(it->second.begin(), it->second.end(), ostream_iterator<bool>(cout));
		cout << endl;
	}
	return 0;
}