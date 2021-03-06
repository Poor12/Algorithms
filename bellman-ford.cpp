//Bellman-ford算法能在更一般的情况下解决单源点最短路径问题，在该算法下边的权可以为负
/*
bool bellman_ford(int r)
{
	for(i=0;i<n;++i)
	{
		dist[i]=∞;
		path[i]=nil;
	}
	dist[r]=0;
	for(i=1;i<n;++i)
		relaxed=false;
		for(each(u,v)属于E)
		{
			if(dist[v]-w(u,v)>dist[u])
			{
				dist[v]=dist[u]+w(u,v);
				path[v]=u;
				relaxed=true;
			}
			if(!relax) break;
		}
	for(each(u,v)属于E)//存在负权回路
		if(dist[v]-w(u,v)>dist[u])
			return false;
	return true;
}
*/
//进行n-1次迭代的原因：两点间如果有最短路，那么每个节点最多经过一次，也就是说这条路不超过n-1条边，如果经过两次，说明我们走了一个圈，若这个圈的权为正，显然不可能是最小路径；若是负权，则路径不存在；若是0权去掉不影响最优值
//执行初始化过程占用时间O（V），然后进行n-1次迭代，每次迭代的运行时间为O（E），花费O（E）的时间判断负值回路，总的时间复杂度为O（VE)
/*
#include<iostream>
#include<cstdio>
using namespace std;
 
#define MAX 0x3f3f3f3f
#define N 1010
int nodenum, edgenum, original; //点，边，起点
 
typedef struct Edge //边
{
	int u, v;
	int cost;
}Edge;
 
Edge edge[N];
int dis[N], pre[N];
 
bool Bellman_Ford()
{
	for(int i = 1; i <= nodenum; ++i) //初始化
		dis[i] = (i == original ? 0 : MAX);
	for(int i = 1; i <= nodenum - 1; ++i)
		for(int j = 1; j <= edgenum; ++j)
			if(dis[edge[j].v] > dis[edge[j].u] + edge[j].cost) //松弛
			{
				dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;
				pre[edge[j].v] = edge[j].u;
			}
			bool flag = 1; //判断是否含有负权回路
			for(int i = 1; i <= edgenum; ++i)
				if(dis[edge[i].v] > dis[edge[i].u] + edge[i].cost)
				{
					flag = 0;
					break;
				}
				return flag;
}
 
void print_path(int root) //打印最短路的路径（反向）
{
	while(root != pre[root]) //前驱
	{
		printf("%d-->", root);
		root = pre[root];
	}
	if(root == pre[root])
		printf("%d\n", root);
}
 
int main()
{
	scanf("%d%d%d", &nodenum, &edgenum, &original);
	pre[original] = original;
	for(int i = 1; i <= edgenum; ++i)
	{
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost);
	}
	if(Bellman_Ford())
		for(int i = 1; i <= nodenum; ++i) //每个点最短路
		{
			printf("%d\n", dis[i]);
			printf("Path:");
			print_path(i);
		}
	else
		printf("have negative circle\n");
	return 0;
}

*/