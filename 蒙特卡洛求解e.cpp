//蒙特卡洛求解e
#include <time.h>
#include <iomanip>
#define MAX_ITERS 10000000

using namespace std;

struct Point
{
	double x, y;
};

double Rand(double L, double R)//在区间内随机取值
{
	return L + (R - L) * rand() * 1.0 / RAND_MAX;
}

Point getPoint()
{
	Point t;
	t.x = Rand(1.0, 2.0);
	t.y = Rand(0.0, 1.0);
	return t;
}

double getResult()
{
	int m = 0;
	int n = MAX_ITERS;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		Point t = getPoint();
		double res = t.x * t.y;
		if (res <= 1.0)
			m++;
	}
	return pow(2.0, 1.0 * n / m);
}

int main()
{
	for (int i = 0; i < 20; i++)
		cout << fixed << setprecision(6) << getResult() << endl;
	return 0;
}