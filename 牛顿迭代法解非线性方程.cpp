//假设r是f（x）=0的根，选取x0作为r初始近似值，经过点(x0,f(x0))做一条曲线y=f(x)的切线L，L的方程是y=f(x0)+f'(x0)(x-x0)，求出L与x轴交点的横坐标x1=x0-f(x0)/f'(x0)，称x1为r的一次近似值，过(x1,f(x1)继续做切线，直到迭代到指定次数
double func(double x)//原函数
{
	return x*x*x*x - 3 *x*x*x + 1.5*x*x - 4;
}
double func1(double x)//导函数
{
	return 4 * x*x*x - 9 * x*x + 3 * x;
}
int newton(double *x, double precision, int maxcyc)
{
	double x1, x0;
	int k;
	x0 = *x;
	for (k = 0;k < maxcyc;++k)
	{
		if (func1(x0) == 0.0)
		{
			printf("导数为0！\n");
			return 0;
		}
		x1 = x0 - func(x0) / func1(x0);
		if (fabs(x1 - x0) < precision || fabs(func(x1)) < precision)
		{
			*x = x1;
			return 1;
		}
		else
			x0 = x1;
	}
	printf("迭代次数超过预期！\n");
	return 0;
}

int main() {
	double x, precision;
	int maxcyc;
	printf("输入初始迭代值x0：");
	scanf("%lf", &x);
	printf("输入最大迭代次数：");
	scanf("%d", &maxcyc);
	printf("输入迭代要求的精度：");
	scanf("%lf", &precision);
	if (newton(&x, precision, maxcyc) == 1)
		printf("该值附近的根为:%lf\n", x);
	else
		printf("迭代失败\n");
}