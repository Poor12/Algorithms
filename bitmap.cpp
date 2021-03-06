//5TB的硬盘上放满了数据，请写一个算法将这些数据进行排重。如果这些数据是一些32bit大小的数据该如何解决？如果是64bit的呢？
//bitmap
//缺点：（1）对每个元素只能记录1bit信息（2）空间复杂度不随集合元素个数而增加，但随集合内最大元素增加而增加
/*不考虑数据量的去重
#include <map>
#include <algorithm>
#define maxn 50000
int* removeDuplicates(int a[], int len) {
	int index = 0;
	map<int, bool> maps;
	int* newarray = new int[maxn];
	for (int i = 0;i < len;++i) {
		if (maps.find(a[i])==maps.end()) {
			newarray[index] = a[i];
			index++;
			maps[a[i]] = 1;	
		}
	}
	return newarray;
}
*/
//核心需求 集合中每个元素（示例中是int）有一个独享的空间 找到一个到这个空间的映射方法
//如果这个空间仅为1bit，即1表示出现，0表示未出现，我们可以把0x01...0x08的空间映射到一个byte
//32位的int的所有可能值所需要的内存空间为2^32bit=2^29byte=512MB
const int mb = 1024 * 1024;
char flags[512*mb+1];
void setflags(int num) {
	//使用每个数的第三位作为byte内的映射
	//255=0x11111111
	//低三位 num&(0x07)为7，则byte的第7位为1，表示255已存在
	flags[num >> 3] |= 0x01 << (num & (0x07));
}
bool getflags(int num) {
	return (flags[num >> 3] >> (num & (0x07)) & 0x01) == 0x01;
}
int main() {
	int array[] = { 255,1024,0,65535,255 };
	int index = 0;
	for (int i = 0;i < 5;++i) {
		if (!getflags(array[i]) ){
			array[index]=array[i];
			index++;
			setflags(array[i]);
			cout << "set " << array[i]<<endl;
		}
		else {
			cout << array[i] << " already exists";
		}
	}
}