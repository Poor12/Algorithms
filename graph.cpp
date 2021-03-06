//graph的存储结构

//邻接矩阵
#define maxv 20
typedef char infotype;
typedef struct {
	int no;//顶点编号
	infotype data;//顶点其他信息
}vertextype;
typedef struct {
	int edges[maxv][maxv];//邻接矩阵
	int vexnum, edgenum;
	vertextype vexs[maxv];
}mgraph;

//邻接表，计算入度较难，需要建立逆邻接表
#define max_vertex_num 20
typedef enum{DG,DN,UDG,UDN}graphkind;
typedef struct arcnode {
	int adjvex;
	infotype *info;//权值
	struct arcnode *nextarc;
};
typedef struct vnode {//顶点数组
	vertextype data;
	arcnode *firstarc;
}vnode,adjlist[max_vertex_num];
typedef struct graphs {
	adjlist vertices;
	int vexnum, arcnum;
	graphkind kind;
}algraph;

//十字链表
typedef struct anode {
	int tailvex, headvex;//弧的弧尾和弧头
	struct anode *hlink, *tlink;//弧头相同和弧尾相同的弧的链域，还可以设置其他类似的指针
	infotype info;
}arcnode;
typedef struct vnode {
	vertextype data;
	arcnode *firstin, *firstout;//分别指向第一条入弧和出弧
}vnode;
typedef struct {
	vnode xlist[maxv];//表头向量
	int n, e;//有向图的顶点数n和弧数e
}olgraph;

//邻接多重表,无向图
typedef struct anode {
	int ivex;//边的左点号
	int jvex;
	anode *ilink, *jlink;//ilink指向下一条以ivex为点的边
	int mark;//访问标志
};
typedef struct {
	int vertexnum;
	anode *firstedge;//指向链接的第一条边
};

/*
邻接矩阵 无向图一定是个对称矩阵，最少存n*n/2，有向图就是n*n，适合稠密图，求顶点的度扫描矩阵一行或一列O（n），判断某边存在与否O（1），求边的数目检测矩阵O（n*n），建立结构O（n*n）
邻接表 无向图2*e，有向图e，适合稀疏图，求顶点的度，扫描某个边表/判断某边是否存在 最坏O（n），求边的数目 检测每一个边表  O（n+2e),建立结构 O（n+e）
*/