#define list_init_size 10
#define listincrement 10
typedef struct {
	int *elem;
	int length;
	int listsize;
}sqlist;
int init(sqlist* l)
{
	int i;
	l->elem = (int*)malloc(list_init_size * sizeof(int));
	if (!l->elem) exit(-2);//overflow
	l->length = 10;
	l->listsize = list_init_size;
	for (i = 0;i < l->length;++i)
	{
		l->elem[i] = i;
	}
	return 1;
}

int get_length(sqlist* l)
{
	return l->length;
}

int destroy(sqlist* l)
{
	delete l;
	return 1;
}

int listsert(sqlist* l, int i, int e)
//在顺序表的第i个位置前插入新的元素
{
	int *newbase, *q, *p;
	if (i<1 || i>l->length + 1) return -1;
	if (l->length >= l->listsize)
	{
		newbase = (int*)realloc(l->elem, (l->listsize + listincrement) * sizeof(int));//realloc则对malloc申请的内存进行大小的调整.
		if (!newbase)
			exit(-2);
		l->elem = newbase;
		l->listsize += listincrement;
	}
	q = &(l->elem[i - 1]);
	for (p = &(l->elem[l->length - 1]);p >= q;--p)
		*(p + 1) = *p;
	*q = e;
	++l->length;
	return 1;
}

int listdelete(sqlist* l, int i, int e)
{
	int *p, *q;
	if (i<1 || i>l->length)
		return -1;
	p = &(l->elem[i-1]);
	e = *p;
	q = l->elem+l->length - 1;
	for (++p;p <= q;++p)
		*(p - 1) = *p;
	--l->length;
	return 1;
}

int display(sqlist* l)
{
	for (int i = 0;i < l->length;++i)
	{
		printf("%d", l->elem[i]);
		printf(" ");
	}
	return 1;
}