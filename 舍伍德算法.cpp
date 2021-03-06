//舍伍德算法 在一般输入数据的程序里，输入多多少少会影响到算法的计算复杂度。这时可用舍伍德算法消除算法所需计算时间与输入实例间的这种联系。
#include <iostream>

#include <iomanip>

#include <time.h>

using namespace std;

const int INF = 9999;

const unsigned long maxshort = 65535L;

const unsigned long multiplier = 1194211693L;

const unsigned long adder = 12345L;



class RandomNumber {

private:

	// 当前种子

	unsigned long randSeed;

public:

	// 构造函数,默认值0表示由系统自动产生种子

	RandomNumber(unsigned long s = 0);

	// 产生0 ~ n-1之间的随机整数

	unsigned short Random(unsigned long n);

	// 产生[0, 1) 之间的随机实数

	double fRandom();

};



// 产生种子

RandomNumber::RandomNumber(unsigned long s)

{

	if (s == 0)

		randSeed = time(0);    //用系统时间产生种子

	else

		randSeed = s;

}



// 产生0 ~ n-1 之间的随机整数

unsigned short RandomNumber::Random(unsigned long n)

{

	randSeed = multiplier * randSeed + adder;

	return (unsigned short)((randSeed >> 16) % n);

}



// 产生[0, 1)之间的随机实数

double RandomNumber::fRandom()

{

	return Random(maxshort) / double(maxshort);

}


/*优化快速排序

// 交换a, b的值

template <typename Type>

void Swap(Type &a, Type &b)

{

	Type temp;

	temp = a;

	a = b;

	b = temp;

}



template <typename Type>

Type select(Type a[], int lt, int rt, int k)

{

	// 计算a[lt:rt]中第k小元素

	static RandomNumber rnd;

	while (true)

	{

		if (lt > rt)

			return a[lt];

		int i = lt, j = lt + rnd.Random(rt - lt + 1);   // 随机选择的划分基准

		Swap(a[i], a[j]);

		j = rt + 1;

		Type pivot = a[lt];

		//以划分基准为轴作元素交换

		while (true)

		{

			while (a[++i] < pivot);

			while (a[--j] > pivot);

			if (i > j)

				break;

			Swap(a[i], a[j]);

		}

		if (j - lt + 1 == k)

			return pivot;

		a[lt] = a[j];

		a[j] = pivot;

		// 对子数组重复划分过程

		if (j - lt + 1 < k)

		{

			k = k - j + lt - 1;

			lt = j + 1;

		}

		else

			rt = j - 1;

	}

}



template <typename Type>

Type Select(Type a[], int n, int k)

{

	// 计算a[0: n-1]中第k小元素

	// 假设a[n]是一个键值无穷大的元素

	if (k < 1 || k > n)

		cerr << "Wrong!" << endl;

	return select(a, 0, n - 1, k);

}



int main()

{

	int arr[6] = { 3, 2, 5, 7, 10, INF };

	cout << Select(arr, 6, 3) << endl;

	for (int i = 0;i < 6;++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

*/
// 交换a, b的值
template <typename Type>
void Swap(Type &a, Type &b)
{
	Type temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename Type>
void Shuffle(Type a[], int len)
{
	// 随机洗牌算法
	static RandomNumber rnd;
	for (int i = 0; i < len; ++i)
	{
		int j = rnd.Random(len - i) + i;
		Swap(a[i], a[j]);
	}
}

template <typename Type>
void Print(Type a[], int len)
{
	for (int i = 0; i < len; ++i)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int arr[10];
	// 原先次序
	for (int i = 0; i < 10; ++i)
		arr[i] = i + 1;
	Print(arr, 10);


	// 第一次洗牌
	Shuffle(arr, 10);
	Print(arr, 10);

	// 第二次洗牌
	Shuffle(arr, 10);
	Print(arr, 10);

	return 0;
}