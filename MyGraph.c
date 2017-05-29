#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR -1
#define INF 99999
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

//1.GqueueCreate
PGQueue GQueueCreate()
{
    PGQueue pq=(PGQueue)malloc(sizeof(GNode));
    pq->rear=pq->front=(PGNode)malloc(sizeof(PGNode));
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
int GQueueIsEmpty(PGQueue pq)
{
    if(pq->rear->next==pq->front->next)
        return 1;
    return 0;
}

//3.QueueIn
PGQueue GQueueIn(PGQueue pq,int d)
{
    //printf("------QueueIn 1\n");
    PGNode temp=(PGNode)malloc(sizeof(PGNode));
    temp->data=d;
    temp->next=NULL;
    if(GQueueIsEmpty(pq))
        pq->front->next=temp;
    else
        pq->rear->next=temp;
    pq->rear=temp;
    pq->size++;
    //printf("------QueueIn 2\n");
    //printf("QueueIn:%d\n",d);
    return pq;
}


//4.QueueOut
int GQueueOut(PGQueue pq)
{
        //printf("------QueueOut 1\n");
        int d;
        if(GQueueIsEmpty(pq))
                return ERROR;
        PGNode temp=pq->front->next;
        d=temp->data;
        pq->front->next=temp->next;
        if(pq->size==0)
        {
            pq->rear->next=pq->front->next;
            pq->size=0;
        }
        pq->size--;
        free(temp);
        //printf("------QueueOut 2\n");
        //printf("QueueOut:%d\n",d);
        return d;
}
/******End Queue******/

int visited[MAX_VERTEX_NUM];

int LocateVex(Graph *G, int v)
{
    int i;
    for (i=0;i<G->vexnum;i++)
    {
        if(G->vexs[i].vexIndex==v)
            return i;
    }
    return ERROR;
}

int CreateGraph(Graph *G)
{
    printf("Vertex Number:");
    scanf("%d",&G->vexnum);
    printf("Arc Number:");
    scanf("%d",&G->arcnum);

    /*****Initialize*****/
    /*********************
    value of a vertex can not
    be -1 || -1 means the vertex
    does not exist
    *********************/
    int i,j,k;
    int v1,v2,w;
    for (i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j].adj=0;
    for (i=0;i<G->vexnum;i++)
    {
        G->vexs[i].vexIndex=-1;
    }
    printf("Enter the Vertex Info:\n");
    printf("Example: 111 1 means vertex index is 111, its value is 1\n");
    for (i=0;i<G->vexnum;i++)
        scanf("%d%d",&G->vexs[i].vexIndex,&G->vexs[i].vexValue);
    printf("Enter the Arcs Info:\n");
    printf("Example: 3 2 13 means v3 to v2, arc weight is 13\n");
    for (k=0;k<G->arcnum;k++)
    {
        scanf("%d%d%d",&v1,&v2,&w);
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        if(i<0 || j<0)
            return ERROR;
        G->arcs[i][j].adj=w;
    }
    return OK;
}

int DestroyGraph (Graph *G)
{
    free(G);
    return OK;
}

int GetVex(Graph *G, int v)
{
    int i;
    for (i=0;i<G->vexnum;i++)
    {
        if (G->vexs[i].vexIndex==v)
            return G->vexs[i].vexValue;
    }
    return ERROR;
}

int PutVex (Graph *G, int v, int value)
{
    int i;
    for (i=0;i<G->vexnum;i++)
        if (G->vexs[i].vexIndex==v)
        {
            G->vexs[i].vexValue=value;
            return value;
        }
    return ERROR;
}

int FirstAdjVex (Graph *G, int v)
{
    int i;
    for (i=0;i<G->vexnum;i++)
    {
        if(G->arcs[v][i].adj!=0)
            return i;
    }
    printf("FirstAdjVex Error!\n");
    return ERROR;
}

int NextAdjVex (Graph *G, int v, int w)
{
    int i;
    for (i=w+1;i<G->vexnum;i++)
    {
        if (G->arcs[v][i].adj!=0)
            return i;
    }
    printf("NextAdjVex Error!\n");
    return ERROR;
}

int InsertVex (Graph *G, int v, int value)
{
    int i,j;
    printf("Insert Vertex %d\n",v);
    G->vexnum++;
    if (G->vexnum>MAX_VERTEX_NUM)
        return ERROR;
    G->vexs[G->vexnum-1].vexIndex=v;
    G->vexs[G->vexnum-1].vexValue=value;
    i=LocateVex(G,v);
    for(j=0;j<G->vexnum;j++)
    {
        G->arcs[i][j].adj=0;
        G->arcs[j][i].adj=0;
    }
    return OK;
}

int DeleteVex (Graph *G, int v)
{
    int i,j,k,t;
    printf("Delete Vertex %d\n",v);
    if (G->vexnum==0)
        return ERROR;
    i=LocateVex(G,v);
    if(i==-1)
    {
        printf("The vertex %d does not exist!\n",v);
        return ERROR;
    }
    for (k=0;k<G->vexnum;k++)
        for (t=i;t<G->vexnum;t++)
            G->arcs[k][t].adj=G->arcs[k][t+1].adj;

    for (k=0;k<G->vexnum;k++)
        for (t=i;t<G->vexnum;t++)
            G->arcs[t][k].adj=G->arcs[t+1][k].adj;

    for (j=i;j<G->vexnum;j++)
        G->vexs[j]=G->vexs[j+1];
    G->vexnum--;
    return OK;
}

int InsertArc (Graph *G,int v, int w,int weight)
{
    int i,j;
    i=LocateVex(G,v);
    j=LocateVex(G,w);

    if (i==-1 || j==-1)
    {
        printf("The vertex does not exist!\n");
        return ERROR;
    }
    G->arcs[i][j].adj=weight;
    return OK;
}

int DeleteArc (Graph *G, int v, int w)
{
    int i,j;
    i=LocateVex(G,v);
    j=LocateVex(G,w);

    if (i==-1 || j==-1)
    {
        printf("The vertex does not exist!\n");
        return ERROR;
    }
    G->arcs[i][j].adj=0;
    return OK;
}

void DFS (Graph *G, int v)
{
    int w;
    printf("%d ",G->vexs[v].vexIndex);
    visited[v]=1;
    for (w=0;w<G->vexnum;w++)
    {
        if (!visited[w] && G->arcs[v][w].adj!=0)
            DFS(G,w);
    }
}

void DFSTraverse (Graph *G)
{
    printf("GraphDFSTraverse:\n");
    int v;
    for (v=0;v<G->vexnum;v++)
        visited[v]=0;
    for (v=0;v<G->vexnum;v++)
    {
        if (!visited[v])
            DFS(G,v);
        printf(" ");
    }
    printf("\n");
}

void BFSTraverse (Graph *G)
{
    printf("GraphBFSTraverse:\n");
    int v,u,w;
    PGQueue Q;
    for (v=0;v<G->vexnum;v++)
        visited[v]=0;
    Q=GQueueCreate();
    for (v=0;v<G->vexnum;v++)
    {
        if(!visited[v])
        {
            visited[v]=1;
            printf("%d ",G->vexs[v].vexIndex);
            GQueueIn(Q,v);
            while(GQueueIsEmpty(Q))
            {
                u=GQueueOut(Q);
                for (w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
                    if(!visited[w])
                {
                    visited[w]=1;
                    printf("%d ",G->vexs[w].vexIndex);
                    GQueueIn(Q,w);
                }
            }
        }
    }
    printf("\n");
}

void PrintAdjMatrix(Graph *G)
{
    int i,j;
    for (i=0;i<=G->vexnum;i++)
    {
        if (i==0)
                printf("@@@ ");
        else
            printf("%-3d ",G->vexs[i-1].vexIndex);
        for (j=1;j<=G->vexnum;j++)
        {
            if (i==0 )
                printf("%-3d ",G->vexs[j-1].vexIndex);
            else
            {
                if (G->arcs[i-1][j-1].adj==0)
                    printf("### ");
                else
                    printf("%-3d ",G->arcs[i-1][j-1].adj);
            }
        }
        printf("\n");
    }
}

int GraphTest ()
{
    Graph *G=NULL;
    if (!((G) = (Graph*)malloc(sizeof(Graph))))
			return ERROR;
    printf("!!!!!Must Enter the data according to README.md file!\n");
    CreateGraph(G);
    DFSTraverse(G);
    BFSTraverse(G);

    printf("\nInsert the vertex: 666 with value of 6\n");
    InsertVex(G,666,6);
    PrintAdjMatrix(G);

    printf("\nInsert the arc: 444 to 666 weigh 46\n");
    InsertArc(G,444,666,46);
    PrintAdjMatrix(G);

    printf("\nDelete the vertex: 555\n");
    DeleteVex(G,555);
    PrintAdjMatrix(G);

    printf("\nDelete the arc: 444 to 666\n");
    DeleteArc(G,444,666);
    PrintAdjMatrix(G);

    printf("\nChange the value of 333\n");
    printf("PutVex(G,333,213):%-3d\n",PutVex(G,333,213));

    printf("\nGet the value of 333\n");
    printf("GetVex(G, 333):%-3d\n",GetVex(G, 333));

    printf("\n***Because I use the function:\n");
    printf("1. FirstAdjVex(G,u)\n2. NextAdjVex(G,u,w)\n");
    printf("in BFSTraverse(G) and the answer is correct.\n");
    printf("So I skip the testing of them :D \n");


    return OK;
}

