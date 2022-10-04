linked_stack: postFix.o
	g++ -o linked_stack postFix.o

postFix.o: postFix.cpp linkedStack.h node.h
	g++ -c postFix.cpp

clean:
	del *.o *.h.gch linked_stack.exe 