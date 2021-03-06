//拉斯维加斯算法 它所作的随机性决策有可能导致算法找不到所需的解
/*
void Obstinate(InputType x, OutputType &y)
{

	// 反复调用拉斯维加斯算法LV(x, y)，直到找到问题的一个解
	bool success= false;
	while (!success)
		 success = LV(x,y);
}
*/
#include <time.h>
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

//解八皇后问题
class Queen
{
	friend bool nQueen(int);
private:
	bool Place(int k);             // 测试皇后k置于第x[k]列的合法性
	bool Backtrack(int t);         // 解n后问题的回溯法
	bool QueensLV(int stopVegas);  // 随机放置n个皇后拉斯维加斯算法
	int n, *x, *y;
};
bool Queen::Place(int k)
{
	// 测试皇后k置于第x[k]列的合法性
	for (int j = 1; j < k; ++j)
		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
			return false;
	return true;
}

bool Queen::Backtrack(int t)
{
	// 解n后问题的回溯法
	if (t > n)
	{
		for (int i = 1; i <= n; ++i)
			y[i] = x[i];
		return true;
	}
	else
		for (int i = 1; i <= n; ++i)
		{
			x[t] = i;
			if (Place(t) && Backtrack(t + 1))
				return true;
		}
	return false;
}

/*
* QueensLV是整个Las Vegas解n皇后的精髓。而且这个函数不好理解，我在这里具体分析下。
* k是第k行，x[k]表示第k行的皇后放在x[k]列
* 下面这两点解析请认真看了，我个人就是卡在这里半天了，但是理解后很简单。
* 标号①处：这里是遍历第k行所有可以放置的列号，用y保存下来，并用count记录有多少个位置可以放置
* 标号②处：这里利用上面保存的可以放置的列，然后随机取其中一列来放置第k行的皇后。这就是Las Vegas的精髓！
*/
bool Queen::QueensLV(int stopVegas)
{
	// 随机放置n个皇后的拉斯维加斯算法
	RandomNumber rnd;    // 随机数产生器
	int k = 1;           // 下一个放置的皇后编号
	int count = 1;
	// 1 <= stopVegas <= n 表示允许随机放置的皇后数
	while ((k <= stopVegas) && (count > 0))
	{
		count = 0;
		for (int i = 1; i <= n; ++i)      // ----------- ①
		{
			x[k] = i;
			if (Place(k))
				y[count++] = i;
		}
		if (count > 0)                   // -------------②
			x[k++] = y[rnd.Random(count)];   // 随机位置
	}
	return (count > 0);   // count > 0表示放置位置成功
}
bool nQueen(int n)
{
	// 与回溯法结合的解n后问题的拉斯维加斯算法
	Queen X;
	// 初始化X
	X.n = n;
	int *p = new int[n + 1];
	int *q = new int[n + 1];
	for (int i = 0; i <= n; ++i)
	{
		p[i] = 0;
		q[i] = 0;
	}
	X.y = q;
	X.x = p;
	// 设置随机放置皇后的个数
	int stop = 8;
	if (n > 15)
		stop = n - 15;
	bool found = false;
	while (!X.QueensLV(stop));
	// 算法的回溯搜索部分
	if (X.Backtrack(stop + 1))
	{
		for (int i = 1; i <= n; ++i)
			cout << p[i] << " ";
		found = true;
	}
	cout << endl;
	delete[] p;
	delete[] q;
	return found;
}

int main()
{
	nQueen(8);
}
