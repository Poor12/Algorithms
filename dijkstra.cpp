﻿//dijkstra算法用于有向加权图的最短路径算法，该算法的条件是该图所有边的权值非负。
//算法设置了一节点集合s，从源节点r到集合s中节点的最终最短路径的权值均已确定，并设置了最小优先队列q，该队列包含所有属于v-s的节点，这些节点尚未确定最短路径，且以dist值递增的顺序排列。
//初始时，q包含除r外的其他节点，这些节点的dist值为∞，r进入集合s，dist[r]=0。算法反复从q中取出dist值最小的节点u属于v-s，把u插入s中，并对u所有出边进行松弛，直到q为空
/*
	void dijskra(int r)
	{
		for(i=0;i<n;++i)
		{
			dist[i]=∞;
			path[i]=nil;//表示i的先辈
		}
		dist[r]=0;
		s=empty;//用visited数组表示
		q=[0...n-1];
		while(q!=empty)
		{
			取出dist值最小的节点u
			s=s∪{u};
			for(v属于u相邻的节点集)
				if(dist[v]-w(uv)>dist[u])
				{
					dist[v]=dist[u]+w(uv);
					path[v]=u;
				}
			}
		}
	}
*/
//dijkstra使用贪心策略，需要n次从最小优先队列中取出d值最小的节点O（V），考察v的每条邻接边，因此考察时间为O（E）
//如果使用数组存储，从最小优先队列取出最小元素的时间为O（V），总时间为O（（V+E）*V）；如果使用二叉堆，从最小优先队列取出最小元素的时间为O（logV），总时间为O（（V+E）*logV）
//稠密图数组，稀疏图二叉堆

void dijkstra()
{
    memset(dis,127/3,sizeof(dis));//初始化
    v[1]=1;
    dis[1]=0;
    for(int i=1;i<=n;++i)
    {
        int k=0;
        for(int j=1;j<=n;++j)//找出距离最近的点
            if(!v[j]&&(k==0||dis[j]<dis[k]))
                k=j;
        v[k]=1;//加入集合
        for(int j=1;j<=n;++j)//松弛
            if(!v[j]&&dis[k]+a[k][j]<dis[j])
                dis[j]=dis[k]+a[k][j];
    }
}

while (!q.empty()) {
            auto f = q.top(); q.pop();
            visited[f.x][f.y]=1;
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1)) continue;
                if(visited[nx][ny])
                    continue;
                if (f.v + 1 < d[nx][ny]) {
                    d[nx][ny] = f.v + 1;
                    q.push({d[nx][ny], nx, ny});
                }
            }
        }
