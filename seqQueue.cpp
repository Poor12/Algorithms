#define queuemax 15
typedef struct
{
	int data[queuemax];
	int head;//队头
	int tail;//队尾
}seqQueue;
seqQueue* seqQueueinit() {
	seqQueue *q;
	if (q = (seqQueue*)malloc(sizeof(seqQueue)))
	{
		q->head = 0;
		q->tail = 0;
		return q;
	}
	else
		return NULL;
}
void seqQueueFree(seqQueue *q)
{
	if (q != NULL)
		free(q);
}
int seqQueueisEmpty(seqQueue *q)
{
	return (q->head == q->tail);
}
int seqQueueisFull(seqQueue *q)
{
	return (q->tail == queuemax);
}
int seqQueuelen(seqQueue *q)
{
	return (q->tail - q->head);
}
int seqQueuein(seqQueue *q, int data)
{
	if (q->tail == queuemax)
	{
		printf("full\n");
		return 0;
	}
	else
	{
		q->data[q->tail++] = data;
		return 1;
	}

}
int* seqQueueout(seqQueue *q)
{
	if (q->head == q->tail)
	{
		printf("empty\n");
		return NULL;
	}
	else
	{
		return &(q->data[q->head++]);
	}
}
int* seqQueuepeek(seqQueue *q)
{
	if (seqQueueisEmpty(q))
	{
		return NULL;
	}
	else
	{
		return &(q->data[q->head]);
	}
}