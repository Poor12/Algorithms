//二分法求解非线性方程
double func(double x)
{
	return 2 * x*x*x - 5 * x - 1;
}
int main() {
	double a = 1.0, b = 2.0;
	double c;
	c = (a + b) / 2;
	while (fabs(func(c)) > 1e-5&&func(a - b) > 1e-5)
	{
		if (func(c)*func(b) < 0)
			a = c;
		if (func(c)*func(a) < 0)
			b = c;
		c = (a + b) / 2;
	}
	printf("二分法解方程：\n");
	printf("结果:%0.5f\n", c);
	return 0;
}