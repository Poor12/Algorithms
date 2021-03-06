//并查集
//每个节点p设一个指针set[p],记录它所在树的根节点序号，如果set[p]<0,则表明p为根节点
//初始时建立一个集合，set[x]=-1
//对于查找操作，采用边查边路径压缩的方法，减少树的深度，即将x至f（树的根节点）的路径上经过的每个节点的set指针都指向f
/*
int set_find(int p) {
	if(set[p]<0)
		return p;
	return set[p]=set_find(set[p]); //return 根节点
}
*/

//合并操作只需将两棵树的根节点相连即可，即计算x的树根fx和y的树根fy，如果fx==fy，则说明x和y在同一并查集;否则将x所在的集合并入y所在的集合
//按秩归并，程序记录每棵树的高度，执行并操作时令更浅的树成为更深的树的子树
/*
void join(int p,int q){
	p=set_find(p);
	q=set_find(q);
	if(p==q) return;
	if(set[p]<set[q])
		set[q]=p;
	else{
		if(set[q]==set[p])
			set[q]-=1;
		set[p]=q;
	}
}
*/