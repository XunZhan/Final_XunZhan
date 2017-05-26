#include <stdio.h>
#include <stdlib.h>

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

//1.QueueCreate
PQueue QueueCreate()
{
    PQueue pq=(PQueue)malloc(sizeof(qNode));
    pq->rear=pq->front=(PqNode)malloc(sizeof(PqNode));
    if(pq==NULL || pq->front==NULL)
    {
        printf("Queue Create Failed!\n");
        exit(1);
    }
    pq->front->next=NULL;
    pq->size=0;
    return pq;
}

//2.QueueIsEmpty
int QueueIsEmpty(PQueue pq)
{
    if(pq->rear->next==pq->front->next)
        return 1;
    return 0;
}

//3.QueueIn
PQueue QueueIn(PQueue pq,int d)
{
    PqNode temp=(PqNode)malloc(sizeof(PqNode));
    temp->data=d;
    temp->next=NULL;
    if(QueueIsEmpty(pq))
        pq->front->next=temp;
    else
        pq->rear->next=temp;
    pq->rear=temp;
    pq->size++;
    printf("QueueIn:%d\n",d);
    return pq;
}


//4.QueueOut
int QueueOut(PQueue pq)
{
        int d;
        if(QueueIsEmpty(pq))
                return 0;
        PqNode temp=pq->front->next;
        d=temp->data;
        pq->front->next=temp->next;
        if(pq->size==0)
        {
            pq->rear->next=pq->front->next;
            pq->size=0;
        }
        pq->size--;
        free(temp);
        printf("QueueOut:%d\n",d);
        return d;
}

//5.QueueTraverse
void QueueTraverse(PQueue pq)
{
    if(QueueIsEmpty(pq))
        printf("The queue is empty!\n");
    else
    {
        PqNode pn=pq->front->next;
        int i=1;
        while(pn)
        {
            printf("NO.%-3.d: %d\n",i,pn->data);
            pn=pn->next;
            i++;
        }
    }
    return ;
}

//6.QueueDestroy
void QueueDestroy(PQueue pq)
{
    PqNode temp=pq->front->next;
    while(temp)
    {
        PqNode t=temp;
        temp=temp->next;
        free(t);
    }
    temp=pq->front;
    pq->front=pq->rear=NULL;
    free(temp);
    printf("Queue Destroy!\n");
    return ;
}


//7.QueueTest
void QueueTest()
{
    PQueue PQ;
    int d,func;

    PQ=QueueCreate();
    printf("QueueCreate Finish!\n");

    if(QueueIsEmpty(PQ))
        printf("QueueIsEmpty: True!\n");

    printf("What to do next?\n");
    printf("0 ExitProcess\n1 QueueIn\n2 QueueOut\n3 QueueTraverse\n4 QueueIsEmpty\n5 QueueDestroy\n");
    scanf("%d",&func);
    while(func)
    {
        switch(func)
        {
            case 1:printf("Your Data:");scanf("%d",&d);QueueIn(PQ,d);break;
            case 2:QueueOut(PQ);break;
            case 3:QueueTraverse(PQ);break;
            case 4:if(QueueIsEmpty(PQ)) printf("IsEmpty: True\n"); else printf("IsEmpty: False\n");break;
            case 5:QueueDestroy(PQ);break;
            default:printf("Enter number error!\n");break;
        }
        scanf("%d",&func);
    }
    printf("Process Exit!\n");
}
