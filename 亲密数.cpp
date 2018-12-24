//亲密数--如果整数a的全部因数之和等于b，此处的因数包括1，但不包括a本身，并且整数b的全部因数之和等于a，则a和b称为亲密数
int main() {
	int i, a, b1, b2, m, g1[100], g2[100], count;
	printf("输入最大范围：");
	scanf("%d", &m);
	for (a = 1;a < m;++a)
	{
		for (i = 0;i < 100;++i)
		{
			g1[i] = g2[i] = 0;
		}
		count = 0;
		b1 = 0;
		for (i = 1;i < a / 2 + 1;++i)
		{
			if (a%i == 0)
			{
				g1[count++] = i;
				b1+= i;
			}
		}
		count = 0;
		b2 = 0;
		for (i = 1;i < b1 / 2 + 1;++i)
		{
			if (b1%i == 0)
			{
				g2[count++] = i;
				b2 += i;
			}
		}
		if (b2 == a && a < b1)
		{
			printf("\n\n%d--%d是亲密数，各因数为：", a, b1);
			printf("\n%d=1", a);
			count = 1;
			while (g1[count]>0)
			{
				printf("+%d", g1[count]);
				count++;
			}
			printf("\n%d=1", b1);
			count = 1;
			while (g2[count] > 0)
			{
				printf("+%d", g2[count]);
				count++;
			}
		}
	}

}