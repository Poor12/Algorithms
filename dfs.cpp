//dfs 从左至右、依次访问由u出发的每条路径
/*
	void dfs(vlink g[],int v){
		int w;
		处理节点v;
		visited[v]=1;//置访问标志
		取v的第1个邻接点w（若v无邻接点，w为-1）;
		while(w!=-1){
			if(visited[w]==0)
			{
				处理节点w;
				visited[w]=1;
				dfs(g,w);
			}
			取v的下一个邻接点w，若无下一个可访问置-1
		}
	}
	void travel_dfs(vlink g[],int visited[],int n)
	{
		int i;
		for(i=0;i<n;++i)
			visited[i]=0;
		for(i=0;i<n;++i)
			if(visited[i]==0)
				dfs(g,i);
	}
	在一个具有n个节点，e条边的图上进行深度优先遍历时，为所有节点的访问标志赋初值用O（n），调用dfs O（e）

*/