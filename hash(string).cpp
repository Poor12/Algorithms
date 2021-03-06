//散列 address=hash(record.key)
//散列函数 用一个函数将键值映射到一定整数范围内，然后用整数值来访问数据
//构造散列函数的事项：（1）定义域必须包括需要存储的全部关键码；（2）如果允许有m个地址，其值域必须在0到m-1之间；（3）地址尽量分布均匀
//1.直接定址法 hash(key)=a*key+b key范围较大时效率较低
//2.除留余数法 设散列表中允许的地址数为m，取一个不大于m，但最接近或等于m的质数k，或选取一个不含有小于20的质因子的合数作为除数
//hash(key)=key%k
//3.平方取中法
//4.乘余取整法 hash(key)=[Z*(a*key%1)] 0<a<1 Z为一个整数 a一般取黄金分割点
//5.折叠法 此方法把关键码从左至右分为位数相等的几部分，每一个部分的位数与散列地址位数相等
//折叠法有两种：移位法和分界法。移位法采取的具体方法是把各部分的最后一位对齐相加，分界法各部分不折断，而沿各部分的分界来回折叠，然后对齐相加
//例：987654321 移位法 9876+5432+1=15309 舍去1即可 分界法 9876+2345+1=12222 舍去1即可
//字符串散列：BKDR散列、RS散列、FNV散列
//BKDR
const unsigned long Hashsize= 1000000;
unsigned long BKDR(const string& str) {
	unsigned long seed = 31;//固定基数
	unsigned long hashval = 0;
	for (int i = 0;i < str.length();i++)
		hashval = hashval * seed + str[i];
	return hashval % Hashsize;
}
//RS
unsigned long RS(const string& str) {
	unsigned long a = 31415, b = 27183;
	unsigned long hashval = 0;
	for (int i = 0;i < str.length();++i) {
		hashval = (hashval*a + str[i]) % Hashsize;
		a = a * b % (Hashsize - 1);//伪随机系数
	}
	return hashval;
}
//FNV 分为FNA-1和FNV-1a 将结果映射到一个定长的大整数（n位无符号，n通常取2的整数次幂，n为二进制位），通常以十六进制数表示
/*
伪码 FNA-1 1a与1在乘法与异或的顺序上不同
hash=offset_basis //初始哈希值，例如n=32时，值为2166136261
for each octet_of_data to be hashed//octet_of_data为1字节
	hash=hash*FNV_PRIME//FNV_PRIME为一个质数，例如n=32时，值为16777619
	hash=hash xor octet_of_data
return hash
*/

//const long offsetbasis32=2166136261
#define FNV_32_INIT ((uint32_t)0x811c9dc5)
//const long fnvprime32=16777619
#define FNV_32_PRIME ((uint32_t)0x01000193)
unsigned long FNV1A(const string& str) {
	unsigned long hashval = FNV_32_INIT;
	for (int i = 0;i < str.length();++i) {
		hashval = hashval ^ str[i];
		hashval = hashval * FNV_32_PRIME;
		//上式等同于下列位操作,位操作效率更高
		//hashval+=(hashval<<1)+(hashval<<4)+(hashval<<7)+(hashval<<8)+(hashval<<24);
	}
	return hashval;
}