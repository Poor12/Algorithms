//无向图的邻接表中删去一条边
/*
	void deledge(algraph *g,int i,int j)
	{
		edgenode *p,*q;
		p=g->adjlist[i].firstedge;
		if(p->adjindex==j)
		{
			g->adjlist[i].firstedge=p->next;
			free(p);
		}
		else
		{
			while(p->next->adjindex!=j&&p->next)
				p=p->next;
			if(p->next!=null)
			{
				q=p->next;
				p->next=q->next;
				free(q);
			}
		}
		p=g->adjlis[j].firstedge;
		if(p->adjindex==i)
		{
			g->adjlist[j].firstedge=p->next;
			free(p);
		}
		else
		{
			while(p->next->adjindex!=i&&p->next)
				p=p->next;
			if(p->next!=null)
			{
				q=p->next;
				p->next=q->next;
				free(q);
			}
		}
	}
*/

//prim
/*
	const int maxint=int_max;
	const int n=6;
	typedef int adjmatrix[n][n];
	typedef struct{
		int fromvex,tovex;//起点、终点
		int weight;//权值
	}treeedgenode;
	typedef treeedgenode mst[n-1];
	void primmst(adjmatrix g,mst t,int rt){//从顶点rt出发构造最小生成树,rt成为树的根
		treeedgenode e;
		int i,k=0,min,minpos,v;
		for(i=0;i<n;++i)//初始化
		{
			if(i!=rt)
			{
				t[k].fromvex=rt;
				t[k].tovex=i;
				t[k++].weight=g[rt][i];
			}
		}
		for(k=0;k<n-1;k++)
		{
			min=maxint;
			for(i=k;i<n-1;++i)
				if(t[i].weight<min)
				{
					min=t[i].weight;
					minpos=i;
				}
			if(min==maxint)
			{
				cerr<<"graph is disconnected"<<endl;
				exit(0);
			}
			e=t[minpos];t[minpos]=t[k];t[k]=e;
			v=t[k].tovex;
			for(i=k+1;i<n-1;++i)
			{
				if(g[v][t[i].tovex]<t[i].weight)
				{
					t[i].weight=g[v][t[i].tovex];
					t[i].fromvex=v;
				}
			}
		}
	}
*/

//拓扑排序
/*
	crein(array,indegree,n)
	{
		for(i=0;i<n;++i)
		{
			indegree[i]=0;
		}
		for(i=0;i<n;++I)
		{
			for(j=0;j<n;j++)
				indegree[i]+=array[j][i];
		}
	}
	topsort(array,indegree,n)
	{
		count=0;
		for(i=0;i<n;++i)
			if(indegree[i]==0)
				push(i);
		while(check()))
		{
			vex=pop();
			printf(vex);
			count++;
			for(i=0;i<n;++i)
			{
				k=array[vex][i];
				if(k!=0）
				{
					indegree[i]--;
					if(indegree[i]==0)
						push(i);
				}
			}
		}
		if(count<n) printf("图有回路");
	}


*/

//邻接表存储
/*
	cin>>n>>m;
	for(i=0;i<n;++i)
	{
		cin>>g[i].vertex;
		g[i].firstarc=null;
	}
	for(k=0;k<m;++k)
	{
		cin>>v1>>v2;
		i=graphlocatevertex(g,v1);//节点定位
		j=graphlocatevertex(g,v2);
		p=new node();
		p->adjvex=j;p->next=g[i].firstarc;g[i].firstarc=p;
		p=new node();
		p->adjvex=i;p->next=g[j].firstarc;g[j].firstarc=p;
	}

*/

//建立邻接多重表
/*
	cin>>v1>>v2;
	i=graphlocatevertex(g,v1);
	j=graphlocatevertex(g,v2);
	p=new node();
	p->ivex=i;p->jvex=j;
	p->ilink=g[i].firstedge;
	p->jlink=g[j].firstedge;
	g[i].firstedge=p;
	g[j].firstedge=p;

*/

//建立十字链表
/*
	cin>>i>>j>>v;
	p=new node();
	p->headvex=j;
	p->tailvex=i;
	p->weight=v;
	p->headlink=g[j].firstin;g[j].firstin=p;
	p->taillink=g[i].firstout;g[i].firstout=p;

*/

//根据邻接表改成逆邻接表
/*
	for(i=0;i<n;++i)
	{
		gin[i].vertex=gout[i].vertex;
		gin[i].firstarc=null;
	}
	for(i=0;i<n;++i)
	{
		p=gout[i].firstarc;
		while(p)
		{
			j=p->adjvex;
			s=new node();
			s->adjvex=i;s->next=gin[j].firstarc;gin[j].firstarc=s;
			p=p->next;
		}
	}

*/

//邻接表转邻接矩阵
/*
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
			gm[i][j]=0;
	}
	for(i=0;i<n;++i)
	{
		p=gl[i].firstarc;
		while(p!=null)
		{
			gm[i][p->adjvex]=1;
			p=p->next;
		}
	}

*/

//邻接表中求入度
/*
	for(j=0;j<n;++j)//求i的入度
	{
		if(i!=j)
		{
			p=g[j].firstarc;
			while(p)
			{
				if(p->adjvex==i)
					num++;
				p=p->next;
			}
		}
	}

*/

//邻接表删除一点：
/*
	for(i=0;i<n;++i)
		if(g[i].vertex==key) break;
	p=g[i].firstarc;
	while(p)
	{
		u=p;p=p->next;
		delete(u);
	}
	for(j=0;j<n;++j)
		if(j!=i)
		{
			p=q=g[j].firstarc;//前驱q
			if(p->adjvex==i)
			{
				g[j].firstarc=p->next;
				delete(p);
			}
			else
				while(p)
				{
					if(p->adjvex==i)
					{
						q->next=p->next;
						delete(p);
						break;
					}
					if(p->adjvex>i)
						p->adjvex--;//下标减一
					q=p;
					p=p->next;
				}
		}
	for(j=i+1;j<n;++j) g[j-1]=g[j];

*/

//使用图的遍历求出图的连通分量
/*
	for(i=0;i<n;++i)
	{
		if(visited[i]==0)
		{
			++k;
			dfs(i);
		}
	}
*/

//十字链表求各顶点度的算法
/*
	for(i=0;i<n;++i)
	{
		p=g[i].firstout;
		while(p){d[i]++;p=p->tailink;}
		p=g[i].firstin;
		while(p){d[i]++;p=p->headlink;}
	}

*/

//删除以邻接矩阵存储结构的无向图的顶点i，要做三件事：1.将i行和i列的元素都变成0-删除顶点 2.将i+1列到n-1列的元素向左平移一列 3.将第i+1行到n-1行的元素向上平移一行 4.顶点个数-1
//删除一条边，对称的两个元素位置置0

//判断以邻接表存储的有向图是否存在i到j的有向路径
/*
//从vi深度优先遍历，若未退出深度优先遍历遍历到vj，说明vi到vj存在路径
	if(vi==vj) return 1;
	else
	{
		visited[vi]=1;
		for(p=g[vi].firstarc;p;p=p->next)
		{
			k=p->adjvex;
			if(!visited[k]&&pathitoj(g,k,vj)) return 1;
		}
		return 0;
	}

*/

//bfs判断以邻接矩阵存储的有向图是否存在由顶点vi到vj的路径，使用队列。
/*
	int visited[n];
	int pathitoj(adjmatrix g,vertype vi,vertype vj)
	{
		for(i=0;i<n;++i) visited[i]=0;
		queueinit(q);
		visited[i]=1;queuein(q,i);
		while(!queueempty(q))
		{
			v=queueout(q);
			for(w=0;i<n;++w)
			{
				if(g[v][w]==1&&w==j){cout<<"存在路径";return 1;}
				if(g[v][w]==1&&!visited[w]){visited[w]=1;queuein(q,w);}
			}
		}
		cout<<"不存在路径";
		return 0;
	}

*/

//拓扑排序可以判断有向图是否有环。
/*
	for(i=0;i<n;++i)
		if(indegree[i]==0){indegree[i]=top;top=i;}//建立入度为0的栈，top初值=-1
	while(top!=-1)
	{
		m++;j=top;//m表示拓扑排序节点个数，j记住排序序号
		top=indegree[top];
		for(i=0;i<n;++i)
			if(g[j][i]==1)
			{
				indegree[i]--;
				if(indegree[i]==0){indegree[i]=top;top=i;}
			}
	}
	if(m<n) cout<<"环";

	//十字链表
	p=g[i].firstout;//删除从i发出的弧
	while(p)
	{
		if(p->tailvex==i) k=p->headvex;//可删去判断
		else k=p->tailvex;
		g[k].indegree--;
		if(g[k].indegree==0){g[k].indegree=top;top=k;}
		if(p->headvex==i) p=p->headlink;
		else p=p->tailink;
	}
*/

//如果r到g的每一点都可达，称r是根节点，判断有向图g是否有根节点
//使用dfs，从v开始进入dfs（v），若退出dfs（）前已访问完有向图的全部顶点，则为根，重复调用n次
/*
	void dfs(v)
	{
		visited[v]=1;num++;//num=0,全局变量
		if(num==n) {cout<<"根";num=0;}
		p=g[v].firstarc;
		while(p)
		{
			if(visited[p->adjvex]==0) dfs(p->adjvex);
			p=p->next;
		}
		visited[v]=0;num--;
	}

*/

//dfs 非递归
/*
	while(top>0||p!=null)//初值top=0;p=g[v].firstarc;stack[++top]=p;
	{
		while(p)
			if(p&&visited[p->adjvex]) p=p->next;
			else{
				cout<<p->adjvex;
				visited[p->adjvex]=1;
				stack[++top]=p;p=g[p->adjvex].firstarc;
				}
		if(top>0)
		{
			p=stack[top--];
			p=p->next;
		}
	}

	//递归
	void dfs(v)
	{
		visited[i]=1;cout<<v;
		p=g[i].firstarc;
		while(p)
		{
			if(visited[p->adjvex]==0) dfs(p->adjvex);
			p=p->next;
		}
	}

*/

//判断图中是否存在从v0出发到所有顶点的路径
/*
	visited[v0]=1;path[++num]=v0;//num点数
	if(num==nodes(g))
	{
		for(i=1;i<=num;++i) cout<<path[i];
		cout<<endl;
		return;
	}
	p=g[v0].firstarc;
	while(p)
	{
		if(visited[p->adjvex]==0) spathdfs(p->adjvex);
		p=p->next;
	}
	visited[v0]=0;num--;
	

	//非递归
	s[++top]=u;visited[u]=1;
	while(top>0||p)
	{
		p=g[s[top]].firstarc;
		while(p!=null&&visited[p->adjvex]==1) p=p->next;
		if(p==null) top--;
		else
		{
			i=p->adjvex;
			if(i==v)
			{
				for(k=1;k<=top;k++)
					cout<<s[k];
				cout<<v<<endl;
			}
			else{
				visited[i]=1;s[++top]=i;
			}
		}
	}
*/

//dijstra
/*
	p=g[v0].firstarc;s[v0]=1;
	while(p)
	{
		dist[p->adjvex]=p->weight;//其余为inf
		p=p->next;
	}
	for(i=1;i<n;++i)
	{
		mindis=infinity;
		for(j=1;j<=n;++j)
			if(s[j]==0&&dist[j]<mindis)
			{
				u=j;
				mindis=dist[j];
			}
		s[u]=1;
		p=g[u].firstarc;
		while(p)
		{
			j=p->adjvex;
			if(s[j]==0&&dist[j]>dist[u]+p->weight)
				dist[j]=dist[u]+p->weight;
			p=p->next;
		}
	}

*/

//floyd
/*
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			length[i][j]==g[i][j];
		}
	}
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++J)
				if(length[i][k]+length[k][j]<length[i][j])
					length[i][j]=length[i][k]+length[k][j];

*/

//建一个使离医院最远的村庄到医院路程最近的医院
//floyd求最短路径，每个顶点到其他顶点的最短路径选出最长的一条，得到n条路径，在n条路径中最短的一条的出发点
/*
	for(i=1;i<=n;++i)
	{
		s=0;
		for(j=1;j<=n;++j)
		{
			if(w[i][j]>s) s=w[i][j];
		}
		if(s<=m){m=s;k=i;}
	}

*/

//设计算法求距离顶点v0的最短路径长度为k的所有顶点
//bfs
/*
	q[++r]=v0;t=r;level=1;visited[v0]=1;//设v0为根，入队，r初值为0
	while(f<r&&level<=k+1)
	{
		v=q[++f];
		w=graphfirstadj(g,v);
		while(w!=0)
		{
			if(visited[w]==0)
			{
				q[++r]=w;visited[w]=1;
				if(level==k+1){cout<<w;flag=1;}
			}
			w=graphnextadj(g,v,w);
		}
		if(f==t){level++;t=r;}
	}
	if(flag==0) cout<<"无";
	

	//dfs,找到i的第1个邻接点adj，再从adj出发递归地是否存在adj到j地k-1的路径
	if(i==j&&k==0) return 1;
	else if(k>0)
	{
		visited[i]=1;
		for(p=g[i].firstarc;p;p=p->next;
		{
			adj=p->adjvex;
			if(!visited[adj])
			{
				if(path(g,adj,j,k-1)) return 1;
			}
		}
		visited[i]=0;
	}
*/

//bfs求最长路径时，即是队列为空前，最后一个节点的层次减1即是最大路径长度
//拓扑排序求最长路径，求出每个入度为0的顶点所产生的所有路径（拓扑排序序列），取出最大的即可

//最短路径求最小生成树。前者是源点到各顶点的路径最短，后者以源点为根，各顶点间路径上的权值之和最小的生成树
//修改求最短路径中dist向量的定义：定义每个向量元素是三元组（u，w，v），其中u是已确定为生成树的一个顶点，v是u的具有最短最短路径w且尚不在生成树上的顶点
/*
	struct{int u,w,v;}dist[],q[];
	int s[];
	for(i=0;i<n;++I)
	{
		dist[i].u=v0;
		dist[i].w=g[v0][i];
		s[i]=0;
	}
	s[v0]=1;dist[v0].w=0;dist[v0].v=v0;
	queuein(q,dist);
	v=v-{v0};
	for(i=1;i<n;++i)
	{
		mindis=maxint;
		for(j=0;j<n;++j)
		{
			if(s[j]==0&&dist[j].w<mindis&&dist[j].v属于v)
			{
				u=j;
				mindis=dist[j].w;
			}
		}
		s[u]=1;v=v-{u};
		for(j=0;j<n;++j)
			if(s[j]==0&&dist[j].w>g[u][j])
				dist[j].w=g[u][j];
	}

*/

//若生成树的根有多于或等于两棵子树，则根节点是关节节点；若生成树某非叶子顶点v，其子树中的节点没有指向v的祖先回边，则v是关节节点
//定义low（v）=min（visited[k]，low[w]，visited[k]）,(v,w),(v,k)右边，w是v在深度优先生成树上的孩子节点，k是v的祖先节点，若low[w]>=visited[v]，则v是根节点，因w及其子孙无指向v的祖先的回边
/*
	int visited[],low[];
	int count;
	adjlist g;
	void dfs_articul(vertype v0)
	{
		count++;
		visited[v0]=count;//访问顺序节点号放入visited
		min=visited[v0];
		p=g[v0].firstarc;
		while(p)
		{
			w=p->adjvex;
			if(visited[w]==0)//w未访问，w是v0的孩子
			{
				dfs_articul(g,w);
				if(low[w]<min) min=low[w];
				if(low[w]>=visited[v0]) printf(g[v0].vertex)//v0是关键节点
			}
			else//w是v的祖先
				if(visited[w]<min) min=visited[w];
			p=p->next;
		}
		low[v0]=min;
	}
	void get_articul()
	{
		for(vi=1;vi<=n;++I)
			visited[vi]=0;
		count=1;visited[1]=1;
		p=g[1].firstarc;v=p->adjvex;dfs_articul(v);
		if(count<n)
		{
			printf(g[1].vertex);//根是关节点
			while(p->next!=null)
			{
				p=p->next;
				v=p->adjvex;
				if(visited[v]==0)
					dfs_articul(v);
			}
		}
	}
		


*/

//dfs检测环
/*
	int visited[]=0;finished[]=0;flag=1;
	arcnode *final=null;
	void dfs(adjlist g,vertype v)
	{
		cout<<v;visited[v]=1;p=g[v].firstarc;
		while(p)
		{
			j=p->adjvex;
			if(visited[j]==1&&finished[j]==0) flag=0;
			else if(visited[j]==0){dfs(g,j);finished[j]=1;}
			p=p->next;
		}
		t=new node();
		t->adjvex=v;
		t->next=final;
		final=t;
	}
	int dfs-topsort(adjlist g)
	{
		i=1;
		while(flag&&i<=n)
			if(visited[i]==0)
			{
				dfs(g,i);
				finished[i]=1;
			}
		return flag;
	}
*/

//地图用四种颜色染色，相邻国家不能染同一个颜色，对每一个区域依次用1色...4色依次试探，若当前所取颜色与周围已涂色区域不重色，则退栈回溯，修改栈顶区域的颜色。用邻接矩阵描述国家间的关系，相邻表示1，否则为0
/*
	s[1]=1;i=2;j=1;//编号01的国家涂1色，i为国家色，j为涂色号
	while(i<=n)
	{
		while(j<=4&&i<=n)
		{
			k=1;//k指已涂色区域
			while(k<i&&s[k]*c[i][k]!=j) k++;
			if(k<i) j=j+1;
			else{ s[i]=j;i++j=1;}
		}
		if(j>4){i--;j=s[i]+1;}
	}
*/

//平方图
/*
	for(i=0;i<n;++i)
	{
		p=g[i].firstarc;
		while(p)
		{
			j=p->adjvex;q=g[j].firstarc;
			while(q)
			{
				k=q->adjvex;s=new node(k);
				s->next=g2[i].firstarc;g2[i].firstarc=s;q=q->next;
			}
			p=p->next;
		}
	}

*/

//六桥问题，只有所有顶点的度都为偶数才有解
/*
	visited[1..n]=0;adjlist g;
	void dfs(int v0)
	{
		p=g[v0].firstarc;
		while(p)
		{
			j=p->num;
			if(visited[j]==0){
				visited[j]=1;
				dfs(j);
			}
			p=p->next;
		}
	}


*/

//从根到树叶的最大距离成为树的半径，写一个半径最小的生成树
/*
	int miniradius(adjlist g,int v)
	{
		typedef struct{
			int v,level;
		}node;
		int max=100;
		int visited[max]=0;
		node r,q[];
		r.v=v;r.level=1;
		queueinit(q);
		queuein(q,r);
		while(!empty(q))
		{
			r.queuedel(q);
			v=r.v;
			l=r.level;
			p=g[v].firstarc;
			flag=0;
			while(p)
			{
				w=p->adjvex;
				if(visited[w]==0)
				{
					flag=1;R.level=l+1;queuein(q,r);
				}
				p=p->next;
			}
			if(flag==0)
			{
				if(l<max) max=l;
			}
		}
		return max;
	}

*/