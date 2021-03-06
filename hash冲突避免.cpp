//处理散列冲突 闭散列法（开放定址法）和开散列法（分离链接法）
//开放定址法：当冲突发生时，使用某种探查技术在散列表中形成一个探查序列。沿此序列逐个单元地查找下去，直到找到空地址为止。查找时若查到空地址则表明表中无待查的关键字。
//1.线性探查法 将散列表看作是一个循环向量，若插入时出现冲突，则探查后一个，直到发现为空为止，但容易发生堆积
//2.二次探查法 改变探查移动的步长为search的平方（<=(m-1)/2） 例如1，-1，4，-4
//3.双重散列法 使用hash计算所在位置，使用rehash计算移位量（rehash的值必须与m散列表长互为素数）
//（待补充代码）
//分离链接法 将关键词为同义词的节点链接在同一个单链表中，可采用指针数组的形式（初始化为空），也可以采用如下的形式。
#define maxn 2000007
int Hash[maxn], Next[maxn], index;
//将要进行条件判断的值存入一个一维数组，下标为index 例如sum[maxn]
void init() {
	memset(Hash, 0, sizeof(Hash));
	memset(Next, 0, sizeof(Next));
	index = 1;
}
void insert() {
	int h;//计算哈希值
	Next[index] = Hash[h];//上一个哈希值为h的点的位置
	Hash[h] = index++;//最后一个插入的哈希值为h点的位置
}
int is_find() {
	//输入一个要进行比较的值 例如num
	int h;//计算哈希值
	int u = Hash[h];//找到最新的节点位置
	while (u) {//u==0说明找完了
		//进行条件的判断 if(sum[u]==num) break;
		u = Next[u];
	}
	//return 找到的地址 return u;
}
