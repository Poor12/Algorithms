int fact(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}

int fact1(int n)
{
	int result=1;
	for (int i = 1;i <= n;++i)
	{
		result *= i;
	}
	return result;
}