//自守数--平方的末尾等于这个数
//n+1位自守数和n位自守数密切相关；两个n位自守数，它们的和等于10^n+1
int main() {
	long faciend, num, mod, n_mod, p_mod;//mod表示被乘数的系数，n_mod表示乘数的系数，p_mod表示部分乘积的系数
	long i, t, n;//临时变量
	printf("设置最大数:");
	scanf("%ld", &num);
	printf("1-%ld之间有以下自守数:\n", num);
	for (i = 1;i < num;++i)
	{
		faciend = i;//被乘数
		mod = 1;
		do {
			mod *= 10;//被乘数的系数
			faciend /= 10;
		} while (faciend > 0);
		p_mod = mod;
		faciend = 0;
		n_mod = 10;
		while (mod > 0)
		{
			t = i % (mod * 10);
			n = i % n_mod - i % (n_mod / 10);
			t = t * n;
			faciend = (faciend + t) % p_mod;
			mod /= 10;
			n_mod *= 10;
		}
		if (i == faciend)
			printf("%ld ", i);
		/*
		faciend = i;//被乘数
		result = i * i;
		mod = 1;
		do {
			mod *= 10;
			faciend /= 10;
		} while (faciend > 0);
		if (result%mod == i)
			printf("%ld ", i);
		*/
	}
}