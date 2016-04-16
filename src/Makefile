all:libtoolhub.a

OBJS = getfiled.o kmp.o
SRCS = getfiled.c kmp.c

libtoolhub.a:$(OBJS)
	ar crv libtoolhub.a $(OBJS)
	cp libtoolhub.a ../lib/

$(OBJS):$(SRCS)
	gcc -c $^ 

clean:
	rm *.o a.out -rf
