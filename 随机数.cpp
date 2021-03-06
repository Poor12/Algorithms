//随机数类
#include <time.h>
#include <iomanip>

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



int TossCoins(int numberCoins)

{

	// 随机抛硬币

	static RandomNumber coinToss;

	int i, tosses = 0;

	for (i = 0; i < numberCoins; ++i)

		tosses += coinToss.Random(2);

	return tosses;

}



int main()

{

	// 模拟随机抛硬币事件

	const int NCOINS = 10;

	const long NTOSSES = 50000L;

	// heads[i]得到的i次正面的次数

	long i, heads[NCOINS + 1];

	int j, position;

	// 初始化数组heads

	for (j = 0; j < NCOINS + 1; ++j)

		heads[j] = 0;

	// 重复50,000次模拟事件

	for (i = 0; i < NTOSSES; ++i)

		heads[TossCoins(NCOINS)] ++;

	// 输出频率图

	for (i = 0; i <= NCOINS; ++i)

	{

		position = int(float(heads[i]) / NTOSSES * 72);

		cout << setw(6) << i << " ";

		for (j = 0; j < position - 1; ++j)

			cout << " ";

		cout << "*" << endl;

	}

	return 0;

}