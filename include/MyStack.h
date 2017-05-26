#ifndef _MYSTACK_H
#define _MYSTACK_H

typedef struct snode* PsNode;
typedef struct snode
{
	int data;
	PsNode next;
}sNode;

typedef struct stack* PStack;
typedef struct stack
{
	int size;
	PsNode top;
}Stack;

PStack StackCreate();

int StackIsEmpty(PStack ps);

PStack StackPush(PStack ps,int d);

int StackPop(PStack ps);

void StackTraverse(PStack ps);

void StackDestroy(PStack ps);

void StackTest();

#endif //_MYSTACK_H
