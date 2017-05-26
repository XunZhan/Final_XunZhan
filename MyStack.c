#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

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

//1.StackCreate
PStack StackCreate()
{
	PStack ps=(PStack)malloc(sizeof(Stack));
	if (ps==NULL)
    {
        printf("Stack Create Failed!\n");
        exit(1);
    }
		ps->top=NULL;
		ps->size=0;
	return ps;
}

//2.StackIsEmpty
int StackIsEmpty(PStack ps)
{
	if(ps->size==0 && ps->top==NULL)
		return 1;
	else
		return 0;
}

//3.StackPush
PStack StackPush(PStack ps,int d)
{
	PsNode pn=(PsNode)malloc(sizeof(PsNode));
	if (pn==NULL)
	{
		printf("Push Failed!\n");
		exit(0);
	}
	else
	{
		pn->data=d;
		pn->next=ps->top;
		ps->top=pn;
		ps->size++;
	}
	printf("StackPush:%d\n",d);
	return ps;
}

//4.StackPop
int StackPop(PStack ps)
{
	if(ps->top==NULL)
	{
		printf("Stack Empty!\n");
		exit(0);
	}
	int tempData=ps->top->data;
	PsNode tempP=ps->top;
	ps->top=ps->top->next;
	ps->size--;
	free(tempP);
	printf("StackPop:%d\n",tempData);
	return tempData;
}


//5.StackTraverse
void StackTraverse(PStack ps)
{
	PsNode pn=ps->top;
	int i=ps->size;
	while(i>=0 && pn!=NULL)
	{
		printf("NO.%-3.d: %d\n",i,pn->data);
		pn=pn->next;
		i--;
	}
}

//6.StackDestroy
void StackDestroy(PStack ps)
{
	if(StackIsEmpty(ps))
		printf("The stack is empty!\n");
	PsNode pn=ps->top;
	int i=ps->size;
	while(i>0)
	{
		ps->top=pn->next;
		free(pn);
		pn=ps->top;
		ps->size--;
		i--;
	}
	printf("Stack Destroy!\n");
}

//7.StackTest
void StackTest()
{
    PStack PS;
    int d,func;

    PS=StackCreate();
    printf("StackCreate Finish!\n");

    if(StackIsEmpty(PS))
        printf("StackIsEmpty: True!\n");

    printf("What to do next?\n");
    printf("0 ExitProcess\n1 StackPush\n2 StackPop\n3 StackTraverse\n4 StackIsEmpty\n5 StackDestroy\n");
    scanf("%d",&func);
    while(func)
    {
        switch(func)
        {
            case 1:printf("Your Data:");scanf("%d",&d);StackPush(PS,d);break;
            case 2:StackPop(PS);break;
            case 3:StackTraverse(PS);break;
            case 4:if(StackIsEmpty(PS)) printf("IsEmpty: True\n"); else printf("IsEmpty: False\n");break;
            case 5:StackDestroy(PS);break;
            default:printf("Enter number error!\n");break;
        }
        scanf("%d",&func);
    }
    printf("Process Exit!\n");
}

