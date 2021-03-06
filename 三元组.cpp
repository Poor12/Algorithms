//三元组--稀疏矩阵表示
//将非零元素所在的行、列、值组成三元组
#define SMAX 1000  
typedef struct
{
	int i, j;          //储存非零元素的行和列信息
	int v; //非零元素的值    
}SPNode;        //定义三元组类型
typedef struct
{
	int mu, nu, tu; //矩阵的行、列和非零元素的个数  
	SPNode data[SMAX]; //三元组表  
}SPMatrix;

SPMatrix * TransM1(SPMatrix *A)

{
	SPMatrix *B;
	int p, q, col;
	B = (SPMatrix *)malloc(sizeof(SPMatrix)); /*申请存储空间*/
	B->mu = A->nu; B->nu = A->mu; B->tu = A->tu;
	/*稀疏矩阵的行、列、元素个数*/
	if (B->tu != 0) /*有非零元素则转换*/
	{
		q = 0;
		for (col = 1; col <= (A->nu); col++)
		{ /*按A 的列序转换*/
			for (p = 1; p <= (A->tu); p++) /*扫描整个三元组表*/
				if (A->data[p].j == col)
				{
					B->data[q].i = A->data[p].j;
					B->data[q].j = A->data[p].i;
					B->data[q].v = A->data[p].v;
					q++;
				}/*if*/
		}

	} /*if(B->tu>0)*/
	return B; /*返回的是转置矩阵的指针*/
} /*TransM1*/