//trie树，一棵度》2的树，每一层分支不是靠整个关键码的值来确定，而是由关键码的一个分量来确定的，即树的每个节点仅仅包含组成关键码的符号来确定
//关键码为英文单词时，每个节点只包含单独的字母；关键码为数值时，每个节点只包含一个数位
//trie树的基本性质：
//（1）第i层的节点存放关键码的第i个字符
//（2）根节点不包含字符，其他每个节点包含一个
//（3）从根节点到某一节点，路径上的字符连接起来，为该节点对应的字符串
//（4）每个节点的子节点包含的字符各不相同
const int num_chars = 26;
class trie {
protected:
	struct trienode
	{
		char* word;
		trienode* branch[num_chars];
		trienode() {
			word = NULL;
			for (int i = 0;i < num_chars;++i)
				branch[i] = NULL;
		}
	};
	trienode* root;
public:
	trie() {
		root = NULL;
	}
	int insert(const char* word) {
		cout << "插入" << word << endl;
		int result = 1;
		if (root == NULL) root = new trienode;
		char char_code;
		trienode *location = root;
		while (location!=NULL&&*word!=0) {
			if (*word >= 'A'&&*word <= 'Z')
				char_code = *word - 'A';
			else if (*word >= 'a'&&*word <= 'z')
				char_code = *word - 'a';
			else
				return 0;//没有找到合适位置
			if (location->branch[char_code] == NULL)
				location->branch[char_code] = new trienode;
			location = location->branch[char_code];
			word++;
		}
		if (location->word != NULL)
			result = 0;
		else {
			location->word = new char[strlen(word) + 1];
			strcpy(location->word, word);
		}
		return result;
	}
	int search(const char* word) const {
		char char_code;
		trienode *location = root;
		while (location!=NULL&&*word!=0)
		{
			if (*word >= 'A'&&*word <= 'Z') {
				char_code = *word - 'A';
			}
			else if (*word >= 'a'&&*word <= 'z') {
				char_code = *word - 'a';
			}
			else {
				return 0;
			}
			location = location->branch[char_code];
			word++;
		}
		if (location != NULL && location->word != NULL)
			return 1;
		else
			return 0;
	}
	int remove(const char* word) {
		cout << "删除" << word << endl;
		int result = 1;
		char char_code;
		trienode *location = root;
		while (location!=NULL&&*word!=0)
		{
			if (*word >= 'A'&&*word <= 'Z')
				char_code = *word - 'A';
			else if (*word >= 'a'&&*word <= 'z')
				char_code = *word - 'a';
			else
				return 0;
			location = location->branch[char_code];//删除前缀
			word++;
		}
		if (location) {
			delete location->word;
			location->word = NULL;
		}
		else
			result = 0;
		return result;
	}
	void printall(char* pre, trienode* p) {
		if (p->word != NULL) {
			cout << pre << endl;
		}
		for (int i = 0;i < num_chars;++i) {
			if (p->branch[i] != NULL) {
				char ch = 'a' + i;
				char *prestr = new char[strlen(pre) + 2];
				sprintf(prestr, "%s%c", pre, ch);
				printall(prestr, p->branch[i]);
				delete[] prestr;
			}
		}
	}
	void printpre(char* pre) {
		char char_code;
		char* p = pre;
		trienode *location = root;
		while (location != NULL && *pre != 0) {
			if (*pre >= 'A'&&*pre <= 'Z')
				char_code = *pre - 'A';
			else if (*pre >= 'a'&&*pre <= 'z')
				char_code = *pre - 'a';
			else
				return;
			location = location->branch[char_code];
			pre++;
		}
		if (location != NULL)
			printall(p, location);
		return;
	}
};

int main() {
	trie t;
	t.insert("Blue");
	t.insert("blur");
	t.insert("car");
	t.insert("cat");
	t.insert("caw");
	t.insert("coin");
	t.insert("coim");
	t.remove("coim");
	cout << endl;
	cout << "打印树中所有节点" << endl;
	t.printpre((char*)"");
	cout << endl;
	cout << "开始查找" << "cat" << endl;
	if (t.search("cat"))
		cout << "cat" << " was found" << endl;
	else
		cout << "cat" << " was not found" << endl;
	cout << "打印前缀为ca的单词:" << endl;
	t.printpre((char*)"ca");
}