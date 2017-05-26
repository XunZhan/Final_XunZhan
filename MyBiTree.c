#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSSIZE 100
#define MAXQSIZE 100
#define INF 999999

typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
} BiNode , *BiTree;

typedef struct
{
	BiTree *base;
	BiTree *top;
	int stacksize;
} BStack;

int PrintElement(int e)
{
	printf("%d ",e);
	return OK;
}

typedef struct Biqnode *QPNode;

typedef struct Biqnode
{
    BiTree Data;
    QPNode next;
}QNode;

typedef struct queue *PBQueue;

typedef struct queue
{
    QPNode front;
    QPNode rear;
    int size;
}BQueue;

/******Stack******/
int InitBStack(BStack *s)
{
	s->base = (BiTree*)malloc(sizeof(BiTree)*MAXSSIZE);
	s->top = s->base;
	s->stacksize = MAXSSIZE;
	return OK;
}


int BStackEmpty(BStack *s)
{
	if (s->base == s->top)
		return OK;
	return ERROR;
}

int BGetTop(BStack *s, BiTree *c)
{
	if (BStackEmpty(s))
		return ERROR;
	*c = *(s->top - 1);
	return OK;
}


int BPush(BStack *s, BiTree c)
{
	*(s->top++) = c;
	return OK;
}


int BPop(BStack *s, BiTree *c)
{
	if (BStackEmpty(s))
		return ERROR;
	*c = *(--s->top);
	return OK;
}

/******Queue******/
PBQueue InitBQueue()
{
    PBQueue QP=(PBQueue)malloc(sizeof(BQueue));
    QP->rear=QP->front=(QPNode)malloc(sizeof(QNode));
    if(NULL==QP || NULL==QP->front)
    {
        printf("The queue is failed.\n");
        exit(1);
    }
    QP->front->next=NULL;
    QP->size=0;
    return QP;
}


int BQueueIsEmpty(PBQueue Q)
{
    if(Q->front==Q->rear || Q->size==0)
        return 1;
    else
        return 0;
}


void AddBQueue(PBQueue Q,BiTree Data)
{
    QPNode tp=(QPNode)malloc(sizeof(QNode));
    if(NULL==tp)
    {
        printf("The temp is failed.\n");
        exit(1);
    }
    tp->Data=Data;
    tp->next=NULL;
    if(BQueueIsEmpty(Q))
        Q->front->next=tp;
    else
        Q->rear->next=tp;
    Q->rear=tp;
    Q->size++;
}


BiTree DeleteBQueue(PBQueue Q,BiTree Data)
{
    if(BQueueIsEmpty(Q))
        exit(0);
    QPNode tep=Q->front->next;
    Data=tep->Data;
    Q->front->next=tep->next;
    if(0==Q->size)
        Q->rear=Q->front;
    Q->size--;
    free(tep);
    return Data;
}


int CreatBiTree(BiTree *T)
{
	int ch;
	scanf("%d", &ch);
	if (ch == -1)
	{
		(*T) = NULL;
	}
	else
	{
		if (!((*T) = (BiTree)malloc(sizeof(BiNode))))
			return ERROR;
		(*T)->data = ch;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
	return OK;
}


int Recursive_PreOrderTraverse(BiTree T, int(*Visit)(int e))
{
	if (T)
	{
		if (Visit(T->data))
			if (Recursive_PreOrderTraverse(T->lchild, Visit))
				if (Recursive_PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

int Recursive_InOrderTraverse(BiTree T, int(*Visit)(int e))
{
	if (T)
	{
		if (Recursive_InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (Recursive_InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

int Recursive_PostOrderTraverse(BiTree T, int(*Visit)(int e))
{
	if (T)
	{
		if (Recursive_PostOrderTraverse(T->lchild, Visit))
			if (Recursive_PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}


int NonRecursive_PreOrderTraverse(BiTree T, int(*Visit)(int e))
{
	BStack *S;
	BiTree p;
	S = (BStack*)malloc(sizeof(BStack));
	InitBStack(S);
	//push root
	BPush(S, T);
	while (!BStackEmpty(S))
	{
		if (BGetTop(S, &p) && p)
		{
			if (!Visit(p->data))
				return ERROR;
			BPush(S, p->lchild);
		}
		else
		{
			BPop(S, &p);
			if (!BStackEmpty(S))
			{
				BPop(S, &p);
				BPush(S, p->rchild);
			}
		}
	}
	return OK;
}


int NonRecursive_InOrderTraverse(BiTree T, int(*Visit)(int e))
{
	BStack *S;
	BiTree p = T;
	S = (BStack *)malloc(sizeof(BStack));
	InitBStack(S);

	while (p || !BStackEmpty(S))
	{
		//left tree
		if (p)
		{
			BPush(S, p);
			p = p->lchild;
		}
		//right tree
		else
		{
			BPop(S, &p);
			if (!Visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return OK;
}


int NonRecursive_PostOrderTraverse(BiTree T, int(*Visit)(int e))
{
	BStack *S;
	BiTree p, pre=NULL;
	S = (BStack*)malloc(sizeof(BStack));
	InitBStack(S);
	BPush(S, T);

	while (!BStackEmpty(S))
	{
		if (BGetTop(S, &p) && p->lchild && pre != p->lchild && !(p->rchild && pre == p->rchild))
			BPush(S, p->lchild);
		else if (p->rchild && pre != p->rchild)
			BPush(S, p->rchild);
		else
		{
			BPop(S, &p);
			if (!Visit(p->data))
				return ERROR;
			pre = p;
		}
	}
	return OK;
}

int LevelOrderTraverse(BiTree T,int(*Visit)(int e))
{
    PBQueue QP;
    QP=InitBQueue();
    BiTree temp=NULL;
    if(T)
    {
        AddBQueue(QP,T);
        while(!BQueueIsEmpty(QP))
        {
            temp=DeleteBQueue(QP,temp);
            if (!Visit(temp->data))
				return ERROR;
            if(temp->lchild != NULL) AddBQueue(QP,temp->lchild);
            if(temp->rchild != NULL) AddBQueue(QP,temp->rchild);
        }
        printf("\n");
    }
    return OK;
}


int BiTreeIsEmpty (BiTree T)
{
    if(T == NULL)
        return 1;
    return 0;
}

BiTree Root (BiTree T)
{
    return T;
}


int LeftChild (BiTree t, BiNode *e)
{
    if (t==NULL)
    {
        printf("BiTree is Empty!\n");
        return (INF);
    }
    if (e->lchild !=NULL)
        return (e->lchild->data);

    return (INF);
}

int RightChild (BiTree t, BiNode *e)
{
    if (t==NULL)
    {
        printf("BiTree is Empty!\n");
        return (INF);
    }
    if (e->rchild !=NULL)
        return (e->rchild->data);

    return (INF);
}

BiNode* LeftSibling (BiTree t, BiNode *e)
{
    if (t==NULL && e->lchild==NULL)
    {
        printf("BiTree or Node is Empty!\n");
        return (BiNode*) NULL;
    }
    printf("Left Sibling: %p\n",e->lchild);
    return (e->lchild);
}

BiNode* RightSibling (BiTree t, BiNode *e)
{
    if (t==NULL && e->rchild==NULL)
    {
        printf("BiTree or Node is Empty!\n");
        return (BiNode*) NULL;
    }
    printf("Right Sibling: %p\n",e->rchild);
    return (e->rchild);
}


void Assign (BiTree T, BiNode *e, int value)
{
    if (T == NULL || e == NULL)
    {
        printf("BiTree or Node is Empty!\n");
        exit(0);
    }
    e->data = value;
    printf("e->data:%d\n",e->data);
    printf("node assigned %d succeed!\n",e->data);
}

BiTree Parent (BiTree T, BiNode *e)
{
    PBQueue QP;
    QP=InitBQueue();
    BiTree temp=NULL;
    if(T)
    {
        AddBQueue(QP,T);
        while(!BQueueIsEmpty(QP))
        {
            temp=DeleteBQueue(QP,temp);
            if (temp == e)
            {
                printf("Node Value: %d\n",temp->data);
                return temp;
            }
            if(temp->lchild != NULL) AddBQueue(QP,temp->lchild);
            if(temp->rchild != NULL) AddBQueue(QP,temp->rchild);
        }
    }
    printf("Not Found!\n");
    return (BiTree)NULL;
}

int InsertChild (BiTree T, BiNode* p,int LR, BiTree C)
{
    //LR=0 c then is left child of p
    //LR=1 c then is right child of p
    if (LR == 0)
    {
        if (p->lchild != NULL)
        {
            BiNode *fp = C->rchild;
            C->rchild = p->lchild;
            p->lchild = C;
            free(fp);
        }
        else
            p->lchild = C;
        return OK;
    }
    else if (LR == 1)
    {
        if (p->rchild != NULL)
        {
            BiNode *fp = C->rchild;
            C->rchild = p->rchild;
            p->rchild = C;
            free (fp);
        }
        else
            p->rchild = C;
        return OK;
    }
    return ERROR;
}

int DeleteChild (BiTree T, BiNode* p,int LR)
{
    //LR=0 c then is delete left child of p
    //LR=1 c then is delete right child of p
    if(LR == 0)
    {
        if (p->lchild == NULL)
            return OK;
        else
        {
            BiNode *fp = p->lchild;
            p->lchild = NULL;
            free(fp);
            return OK;
        }
    }
    else if (LR == 1)
    {
        if (p->rchild == NULL)
            return OK;
        else
        {
            BiNode *fp = p->rchild;
            p->rchild = NULL;
            free(fp);
            return OK;
        }
    }
    return ERROR;
}


void BiTreeTest ()
{
    printf("Creating a new BiTree: -1 means null\n");
    BiTree T=NULL;
    CreatBiTree(&T);
    printf("BiTreeCreate Finish!\n\n");

    if(BiTreeIsEmpty(T))
        printf("BiTreeIsEmpty: True!\n");

    printf("Recursive:\n");
	printf("PreOrderTraverse:");
	Recursive_PreOrderTraverse(T,PrintElement);
	putchar('\n');
	printf("InOrderTraverse:");
	Recursive_InOrderTraverse(T,PrintElement);
	putchar('\n');
	printf("PostOrderTraverse");
	Recursive_PostOrderTraverse(T,PrintElement);
	putchar('\n');

	printf("NonRecursive:\n");
	printf("PreOrderTraverse:");
	NonRecursive_PreOrderTraverse(T,PrintElement);
	putchar('\n');
	printf("InOrderTraverse:");
	NonRecursive_InOrderTraverse(T,PrintElement);
	putchar('\n');
	printf("PostOrderTraverse");
	NonRecursive_PostOrderTraverse(T,PrintElement);
	putchar('\n');
	printf("LevelOrder:");
	LevelOrderTraverse(T,PrintElement);
    printf("\n");

    Assign(T,T->lchild,20);
    printf("LevelOrder:");
	LevelOrderTraverse(T,PrintElement);
    printf("\n");

    printf("LeftChild(T,T->lchild):%d\n",LeftChild(T,T->lchild));
    printf("RightChild(T,T->rchild):%d\n",RightChild(T,T->rchild));
    printf("LeftSibling(T,T):");
    LeftSibling(T,T);
    printf("RightSibling(T,T):");
    RightSibling(T,T);

    printf("Parent(T,T->lchild->lchild):");
    Parent(T,T->lchild->lchild);
    printf("Parent(T,T->lchild->lchild->lchild):");
    Parent(T,T->lchild->lchild->lchild);

    printf("\nCreating a new BiTree:");
    BiTree C=NULL;
    CreatBiTree(&C);
    printf("BiTreeCreate Finish!\n");
    InsertChild(T,T->lchild->lchild,0,C);
    printf("InsertChild(T,T->lchild->lchild,0,C):\n");
    printf("LevelOrder:");
    LevelOrderTraverse(T,PrintElement);

    printf("DeleteChild(T,T->lchild->lchild,0)");
    DeleteChild(T,T->lchild->lchild,0);
    printf("LevelOrder:");
    LevelOrderTraverse(T,PrintElement);

}

