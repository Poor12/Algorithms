﻿void Sort(int l, int r) {//归并算法 0到n
	if (l == r)
		return;
	int mid = (l + r) / 2;
	Sort(l, mid);
	Sort(mid + 1, r);
	int i = l, j = mid + 1, now = 0;//左右区间和合并区间指针初始化
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) {
			//ans += mid - i + 1;
			t[now++] = a[j++];
		}
		else
		{
			t[now++] = a[i++];
		}
	}
	while (i <= mid) t[now++] = a[i++];
	while (j <= r) t[now++] = a[j++];
	now = 0;
	for (int k = l;k <= r;++k) a[k] = t[now++];
}

ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *p=head,*q=head->next;
        while(q&&q->next)
        {
            p=p->next;
            q=q->next->next;
        }
        ListNode *left=sortList(p->next);
        p->next=NULL;
        ListNode *right=sortList(head);
        return merge(left,right);
    }
    
    ListNode *merge(ListNode *left,ListNode *right)
    {
        ListNode dummy(0);//申请一个假节点
        ListNode *p= &dummy;
        while(left&&right){
            if(left->val < right->val)
            {
                p->next=left;
                left = left->next;
            }
            else{
                p->next=right;
                right=right->next;
            }
            p=p->next;
        }
        if(left)
            p->next=left;
        if(right)
            p->next=right;
        return dummy.next;
    }
