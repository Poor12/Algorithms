//模拟计算pi
#include <math.h>
#include <time.h>
double montePi(int n)
{
	double pi;
	double x, y;
	int i, sum;
	sum = 0;
	srand(time(0));//设随机种子
	for (i = 1;i < n;++i)
	{
		x = (double)rand() / RAND_MAX;//生成0-1的随机数
		y = (double)rand() / RAND_MAX;
		if (x*x + y * y <= 1)
			sum++;
	}
	pi = 4.0 * sum / n;
	return pi;
}
int main()
{
	cout<<montePi(6000);
}