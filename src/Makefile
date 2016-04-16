all:liblkfunc.a

OBJS = lkfunc.o
SRCS = lkfunc.c

liblkfunc.a:$(OBJS)
	ar crv liblkfunc.a lkfunc.o
	cp liblkfunc.a ./lib

$(OBJS):$(SRCS)
	gcc -c lkfunc.c -I./include/

clean:
	rm *.o a.out -rf
