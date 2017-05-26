Final Assignment for Linux
My Data Structure Includes:
1. MyStack
2. MyQueue
3. MyBiTree
4. MyGraph

*******Test Data Examples*******
1. MyStack
Follow the Instruction

2. MyQueue
Follow the Instruction

3. MyBiTree
INF = 999999 If the answer is INF, it means:
[1. can not get the answer  2. error exits]
Creating a new BiTree: -1 means null
1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1 -1
BiTreeCreate Finish!

Recursive:
PreOrderTraverse:1 2 4 5 7 3 6
InOrderTraverse:4 2 7 5 1 6 3
PostOrderTraverse4 7 5 2 6 3 1
NonRecursive:
PreOrderTraverse:1 2 4 5 7 3 6
InOrderTraverse:4 2 7 5 1 6 3
PostOrderTraverse4 7 5 2 6 3 1
LevelOrder:1 2 3 4 5 6 7

node assigned 20 succeed!
LevelOrder:1 20 3 4 5 6 7

LeftChild(T,T->lchild):4
Node does not exits!
RightChild(T,T->rchild):999999
LeftSibling(T,T):Left Sibling: 6893800 (***the answer changes in different environmenmt)
RightSibling(T,T):Right Sibling: 6893896 (***the answer changes in different environmenmt)
Parent(T,T->lchild->lchild):Node Value: 4
Parent(T,T->lchild->lchild->lchild):Not Found!

Creating a new BiTree:9 10 -1 -1 21 -1 -1
BiTreeCreate Finish!
InsertChild(T,T->lchild->lchild,0,C):
LevelOrder:1 20 3 4 5 6 9 7 10 21
DeleteChild(T,T->lchild->lchild,0):
LevelOrder:1 20 3 4 5 6 7

Process returned 0 (0x0)   execution time : 65.123 s
Press any key to continue.

4. MyGraph
Vertex Number:5
Arc Number:5
Enter the Vertex Info:
Example: 111 1 means vertex index is 111, its value is 1
111 1
222 2
333 3
444 4
555 5
Enter the Arcs Info:
Example: 3 2 13 means v3 to v2, arc weight is 13
111 222 12
111 333 13
111 444 14
222 555 25
333 555 35
GraphDFSTraverse:
111 222 555 333 444
GraphBFSTraverse:
111 222 333 444 555

Insert the vertex: 666 with value of 6
Insert Vertex 666
@@@ 111 222 333 444 555 666
111 ### 12  13  14  ### ###
222 ### ### ### ### 25  ###
333 ### ### ### ### 35  ###
444 ### ### ### ### ### ###
555 ### ### ### ### ### ###
666 ### ### ### ### ### ###

Insert the arc: 444 to 666 weigh 46
@@@ 111 222 333 444 555 666
111 ### 12  13  14  ### ###
222 ### ### ### ### 25  ###
333 ### ### ### ### 35  ###
444 ### ### ### ### ### 46
555 ### ### ### ### ### ###
666 ### ### ### ### ### ###

Delete the vertex: 555
Delete Vertex 555
@@@ 111 222 333 444 666
111 ### 12  13  14  ###
222 ### ### ### ### ###
333 ### ### ### ### ###
444 ### ### ### ### 46
666 ### ### ### ### ###

Delete the arc: 444 to 666
@@@ 111 222 333 444 666
111 ### 12  13  14  ###
222 ### ### ### ### ###
333 ### ### ### ### ###
444 ### ### ### ### ###
666 ### ### ### ### ###

Change the value of 333
PutVex(G,333,213):213

Get the value of 333
GetVex(G, 333):213

***Because I use the function:
[1. FirstAdjVex(G,u)]
[2. NextAdjVex(G,u,w)]
in BFSTraverse(G) and the answer is correct.
So I skip the testing of them :D

Process returned 0 (0x0)   execution time : 37.395 s
Press any key to continue.
