#ifndef _MYGRAPH_H
#define _MYGRAPH_H

#define MAX_VERTEX_NUM 50

#define OK 1
#define ERROR -1

#define MAX_VERTEX_NUM 50


/***For Directed Graph***/
typedef struct
{
    int adj;
}ArcCell;

typedef struct
{
    int vexIndex;
    int vexValue;
}Vex;

typedef struct
{
    /*************
    list of vertex
    adjacent matrix
    vertex number
    arc number
    ***************/
    Vex vexs[MAX_VERTEX_NUM];
    ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum;
    int arcnum;
}Graph;

/***Queue Operation***/
typedef struct Gnode *PGNode;

typedef struct Gnode
{
    int data;
    PGNode next;
}GNode;

typedef struct Gqueue *PGQueue;

typedef struct Gqueue
{
    PGNode front;
    PGNode rear;
    int size;
}GQueue;

PGQueue GQueueCreate();

int GQueueIsEmpty(PGQueue pq);

PGQueue GQueueIn(PGQueue pq,int d);

int GQueueOut(PGQueue pq);
/******End Queue******/

int visited[MAX_VERTEX_NUM];

int LocateVex(Graph *G, int v);

int CreateGraph(Graph *G);

int DestroyGraph (Graph *G);

int GetVex(Graph *G, int v);

int PutVex (Graph *G, int v, int value);

int FirstAdjVex (Graph *G, int v);

int NextAdjVex (Graph *G, int v, int w);

int InsertVex (Graph *G, int v, int value);

int DeleteVex (Graph *G, int v);

int InsertArc (Graph *G,int v, int w,int weight);

int DeleteArc (Graph *G, int v, int w);

void DFS (Graph *G, int v);

void DFSTraverse (Graph *G);

void BFSTraverse (Graph *G);

void PrintAdjMatrix(Graph *G);

int GraphTest ();

#endif //_MYGRAPH_H
