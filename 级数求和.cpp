//级数求和
	int n = 0, k = 0;
	double sn = 0;
	scanf("%d", &k);
	while (sn <= k)
	{
		n++;
		sn += 1.0 / n;
	}
	printf("%d\n", n);
	return 0;