all:liblkfunc.a

liblkfunc.a:lkfunc.o
	ar crv liblkfunc.a lkfunc.o
	cp liblkfunc.a ./lib

lkfunc.o:lkfunc.c
	gcc -c lkfunc.c

clean:
	rm *.o -rf
