*******Final Assignment for Linux*******<br>
My Data Structure Includes:
1. MyStack
2. MyQueue
3. MyBiTree
4. MyGraph

*******Test Data Examples*******
1. MyStack<br>
Follow the Instruction

2. MyQueue<br>
Follow the Instruction

3. MyBiTree<br>
INF = 999999 If the answer is INF, it means:<br>
[1. can not get the answer  2. error exits]<br>
Creating a new BiTree: -1 means null<br>
1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1 -1<br>
BiTreeCreate Finish!<br><br>
Recursive:<br>
PreOrderTraverse:1 2 4 5 7 3 6<br>
InOrderTraverse:4 2 7 5 1 6 3<br>
PostOrderTraverse4 7 5 2 6 3 1<br>
NonRecursive:<br>
PreOrderTraverse:1 2 4 5 7 3 6<br>
InOrderTraverse:4 2 7 5 1 6 3<br>
PostOrderTraverse4 7 5 2 6 3 1<br>
LevelOrder:1 2 3 4 5 6 7<br><br>
node assigned 20 succeed!<br>
LevelOrder:1 20 3 4 5 6 7<br><br>
LeftChild(T,T->lchild):4<br>
Node does not exits!<br>
RightChild(T,T->rchild):999999<br>
LeftSibling(T,T):Left Sibling: 6893800 (***the answer changes in different environmenmt)<br>
RightSibling(T,T):Right Sibling: 6893896 (***the answer changes in different environmenmt)<br>
Parent(T,T->lchild->lchild):Node Value: 4<br>
Parent(T,T->lchild->lchild->lchild):Not Found!<br><br>
Creating a new BiTree:9 10 -1 -1 21 -1 -1<br>
BiTreeCreate Finish!<br>
InsertChild(T,T->lchild->lchild,0,C):<br>
LevelOrder:1 20 3 4 5 6 9 7 10 21<br>
DeleteChild(T,T->lchild->lchild,0):<br>
LevelOrder:1 20 3 4 5 6 7<br><br>
Process returned 0 (0x0)   execution time : 65.123 s<br>
Press any key to continue.<br><br>

4. MyGraph<br>
Vertex Number:5<br>
Arc Number:5<br>
Enter the Vertex Info:<br>
Example: 111 1 means vertex index is 111, its value is 1<br>
111 1<br>
222 2<br>
333 3<br>
444 4<br>
555 5<br>
Enter the Arcs Info:<br>
Example: 3 2 13 means v3 to v2, arc weight is 13<br>
111 222 12<br>
111 333 13<br>
111 444 14<br>
222 555 25<br>
333 555 35<br>
GraphDFSTraverse:<br>
111 222 555 333 444<br>
GraphBFSTraverse:<br>
111 222 333 444 555<br><br>
Insert the vertex: 666 with value of 6<br>
Insert Vertex 666<br>
@@@ 111 222 333 444 555 666<br>
111 ### 12  13  14  ### ###<br>
222 ### ### ### ### 25  ###<br>
333 ### ### ### ### 35  ###<br>
444 ### ### ### ### ### ###<br>
555 ### ### ### ### ### ###<br>
666 ### ### ### ### ### ###<br><br>
Insert the arc: 444 to 666 weigh 46<br>
@@@ 111 222 333 444 555 666<br>
111 ### 12  13  14  ### ###<br>
222 ### ### ### ### 25  ###<br>
333 ### ### ### ### 35  ###<br>
444 ### ### ### ### ### 46<br>
555 ### ### ### ### ### ###<br>
666 ### ### ### ### ### ###<br><br>
Delete the vertex: 555<br>
Delete Vertex 555<br>
@@@ 111 222 333 444 666<br>
111 ### 12  13  14  ###<br>
222 ### ### ### ### ###<br>
333 ### ### ### ### ###<br>
444 ### ### ### ### 46<br>
666 ### ### ### ### ###<br><br>
Delete the arc: 444 to 666<br>
@@@ 111 222 333 444 666<br>
111 ### 12  13  14  ###<br>
222 ### ### ### ### ###<br>
333 ### ### ### ### ###<br>
444 ### ### ### ### ###<br>
666 ### ### ### ### ###<br><br>
Change the value of 333<br>
PutVex(G,333,213):213<br><br>
Get the value of 333<br>
GetVex(G, 333):213<br><br>
***Because I use the function:<br>
[1. FirstAdjVex(G,u)]<br>
[2. NextAdjVex(G,u,w)]<br>
in BFSTraverse(G) and the answer is correct.<br>
So I skip the testing of them :D<br><br>
Process returned 0 (0x0)   execution time : 37.395 s<br>
Press any key to continue.<br>
