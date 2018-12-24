//哥德巴赫猜想，是指任何一个大于2的偶数都可以写为两个素数的和
//一个正偶数a一定可以表示成a/2种正整数相加的形式，因为a=1+（a-1）...a=a/2+a/2，共a/2种。在这a/2种表示形式中只要存在一种形式a=i+j，其中i和j为素数，结论即成立
int isprime(int i)
{
	int n, flag = 1;
	if (1 == i) flag = 0;
	for(n=2;n<i;++n)
		if (i%n == 0)
		{
			flag = 0;
			break;
		}
	if (flag == 1)
		return 1;
	else
		return 0;
}
int isgoldbach(int a)
{
	int i, flag = 0;
	for (i = 1;i <= a / 2;++i)
	{
		if (isprime(i) && isprime(a - i))
		{
			flag = 1;
			printf("%d=%d+%d ", a, i, a - i);
			break;
		}
	}
	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int testifyGB_guess(int low, int high)
{
	int i, j = 0;
	int flag = 0;
	for(i=low;i<=high;++i)
		if(i%2==0&&i>2)
			if (isgoldbach(i))
			{
				j++;
				if (j == 5)
				{
					printf("\n");
					j = 0;
				}
			}
			else {
				flag = 1;
				break;
			}
	if (flag == 0)
		return 1;
	else
		return 0;

}
int main() {
	if (testifyGB_guess(1, 100))
		printf("the range of 1-100,goldbach guess is right\n");
	else
		printf("the range of 1-100,goldbach guess is wrong\n");
}