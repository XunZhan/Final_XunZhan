main:main.o MyStack.o MyQueue.o MyGraph.o MyBiTree.o 
	gcc  main.o MyStack.o MyQueue.o MyGraph.o MyBiTree.o -o a.out

main.o:main.c
	gcc -c  main.c

MyQueue.o:MyQueue.c
	gcc -c  MyQueue.c
	ar -q libpmmethod.a MyQueue.o

MyStack.o:MyStack.c
	gcc -c  MyStack.c
	ar -q libpmmethod.a MyStack.o


MyGraph.o:MyGraph.c
	gcc -c  MyGraph.c
	ar -q libpmmethod.a MyGraph.o


MyBiTree.o:MyBiTree.c
	gcc -c  MyBiTree.c
	ar -q libpmmethod.a MyBiTree.o


clean:
	rm main *.o
