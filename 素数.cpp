//求素数的总结,1不是素数也不是合数
//O(n*n)
bool judge1(int n) 
{ 
	int i;    
	if (n == 1)
		return false;
	for (i = 2;i < n;i++)        
		if (n%i == 0) { 
			return false;            
			break; 
		}    
	return true; 
}

//O(n*sqrt(n))
bool judge2(int n)
{
	int i;
	if (n == 1)
		return false;
	for (i = 2;i <= sqrt(n);i++)
		if (n%i == 0)
		{
			return false;
			break;
		}
	return true;
}

//普通筛——埃拉托斯特尼(Eratosthenes)筛法 O(nloglogn)

void judge3(int N)
{
	bool* number=new bool[N+1];
	int i, j;
	memset(number, true, sizeof(number));//假设均为素数
	for (i = 2;i <= sqrt(N);i++)
	{
		if (number[i] == true)//如果i是素数
		{
			for (j = 2;j*i <= N;j++)
			{
				number[i*j] = false;//如果i是素数，则i*j不是素数
			}
			//for (j = i * i;j <= N;j += i)
			//{
			//	number[j] = false;//二次筛选法:i是素数，则下一个起点是i*i,把后面的所有的i*i+2*n*i筛掉
			//}

		}
	}//所有非素数都标记为false，素数都标记为true
	for (i = 2;i < N + 1;i++)
		if (number[i] == true)
			printf("%d ", i);//输出所有素数
	delete[]number;
}

//线性筛 O(N)
#define N 100
int main(void)
{
	bool number[N + 1];
	int prime[N + 1];
	int i, j, count = 0;
	memset(number, true, sizeof(number));
	for (i = 2;i <= N;i++)
	{
		if (number[i])
			prime[count++] = i;
		for (j = 0;j < count&&prime[j] * i <= N;j++)
		{
			number[prime[j] * i] = false;
			if (i%prime[j] == 0)//精华就在于此：它保证每个合数只会被它的最小质因数筛去，因此每个数只会被标记一次，所以时间复杂度是O(n)
				break;
		}
	}
	for (i = 2;i < N + 1;i++)
		if (number[i] == true)
			printf("%d ", i);
	return 0;
}
