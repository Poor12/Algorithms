//Miller_Rabin方法
/*
	int64 qpow(int64 a,int64 b,int64 M)
	{
		int64 ans=1;
		while(b)
		{
			if(b&1) ans*=a,ans%=M;
			a*=a;a%=M;b>>1;
		}
		return ans;
	}
	bool millerRabintest(int64 x,int64 n)
	{
		int64 y=n-1;
		while(!(y&1)) y>>=1;
		x=qpow(x,y,n);
		while(y<n-1&&x!=1&&x!=n-1)
			x=(x*x)%n,y<<=(int64)1;
		return x==n-1||y&1==1;
	}
	bool isprime32(int64 n)
	{
		if(n==2||n==7||n==61) return 1;
		if(n==1||(n&1)==0) return 0;
		return millerRabintest(2,n)&&millerRabintest(7,n)&&millerRabintest(61,n);
	}
*/