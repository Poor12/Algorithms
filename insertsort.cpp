//插入排序 扑克牌 O(n^2)
void insertsort(int a[],int len) {
	int insertNum;
	for (int i = 1;i < len;++i) {
		insertNum = a[i];
		int j = i;
		while (j>0&&insertNum<a[j-1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = insertNum;
	}
}

//双向链表实现插入排序
void insertsort(bnode *l)
{
	p=l->next;
	q=p->next;
	r=q->next;
	while(q!=l)
	{
		while(p!=l&&p->data>q->data) p=p->prior;
		q->prior->next=r;r->prior=q->prior;
		q->next=p->next;q->prior=p;
		p->next->prior=q;p->next=q;
		q=r;p=q->prior;
		r=r->next;
	}
}