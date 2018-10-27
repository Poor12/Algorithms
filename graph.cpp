//图的表示-邻接矩阵
typedef int vertex;
typedef int adjmatrix;
class graphmatrix {
	int n;
	vertex* vexes;
	adjmatrix* arcs[];
};

//图的表示-邻接表
class edgenode;
typedef edgenode* edgelist;
class edgenode {
	int vertexnum;//边节点在顶点表的下标
	int weight;//权值
	edgenode* nextedgenode;//指针字段，指向下一链节点
};
class vertex {
	char vertex;
	edgelist edgelist;
};
class graphlist {
	int n;
	vertex* ver;
};

/*
邻接矩阵 无向图一定是个对称矩阵，最少存n*n/2，有向图就是n*n，适合稠密图，求顶点的度扫描矩阵一行或一列O（n），判断某边存在与否O（1），求边的数目检测矩阵O（n*n），建立结构O（n*n）
邻接表 无向图2*e，有向图e，适合稀疏图，求顶点的度，扫描某个边表/判断某边是否存在 最坏O（n），求边的数目 检测每一个边表  O（n+2e),建立结构 O（n+e）
*/