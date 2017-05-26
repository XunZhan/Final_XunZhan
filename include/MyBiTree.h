#ifndef _MYBITREE_H
#define _MYBITREE_H

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

int PrintElement(int e);

typedef struct Biqnode *QPNode;

typedef struct Biqnode
{
    BiTree Data;
    QPNode next;
}QNode;

typedef struct Bqueue *PBQueue;

typedef struct Bqueue
{
    QPNode front;
    QPNode rear;
    int size;
}BQueue;

/******Stack******/
int InitBStack(BStack *s);

int BStackEmpty(BStack *s);

int BGetTop(BStack *s, BiTree *c);

int BPush(BStack *s, BiTree c);

int BPop(BStack *s, BiTree *c);

/******Queue******/
PBQueue InitBQueue();

int BQueueIsEmpty(PBQueue Q);

void AddBQueue(PBQueue Q,BiTree Data);

BiTree DeleteBQueue(PBQueue Q,BiTree Data);

int CreatBiTree(BiTree *T);

int Recursive_PreOrderTraverse(BiTree T, int(*Visit)(int e));

int Recursive_InOrderTraverse(BiTree T, int(*Visit)(int e));

int Recursive_PostOrderTraverse(BiTree T, int(*Visit)(int e));

int NonRecursive_PreOrderTraverse(BiTree T, int(*Visit)(int e));

int NonRecursive_InOrderTraverse(BiTree T, int(*Visit)(int e));

int NonRecursive_PostOrderTraverse(BiTree T, int(*Visit)(int e));

int LevelOrderTraverse(BiTree T,int(*Visit)(int e));

int BiTreeIsEmpty (BiTree T);

int LeftChild (BiTree t, BiNode *e);

int RightChild (BiTree t, BiNode *e);

BiNode* LeftSibling (BiTree t, BiNode *e);

BiNode* RightSibling (BiTree t, BiNode *e);

void Assign (BiTree T, BiNode *e, int value);

BiTree Parent (BiTree T, BiNode *e);

int InsertChild (BiTree T, BiNode* p,int LR, BiTree C);

int DeleteChild (BiTree T, BiNode* p,int LR);

void BiTreeTest ();

#endif //_MYBITREE_H

