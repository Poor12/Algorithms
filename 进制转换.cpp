//进制转换
int calc(int k, int b)//b为转换进制
{
	int x;
	while (k)
	{
		x = k % b;
		//加入数组等存储x
		k = k / b;
	}
}