#ifndef _MYQUEUE_H
#define _MYQUEUE_H

typedef struct qnode *PqNode;

typedef struct qnode
{
    int data;
    PqNode next;
}qNode;

typedef struct queue *PQueue;

typedef struct queue
{
    PqNode front;
    PqNode rear;
    int size;
}Queue;

PQueue QueueCreate();

int QueueIsEmpty(PQueue pq);

PQueue QueueIn(PQueue pq,int d);

int QueueOut(PQueue pq);

void QueueTraverse(PQueue pq);

void QueueDestroy(PQueue pq);

void QueueTest();

#endif //_MYQUEUE_H
