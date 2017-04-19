# Include c flags and compiler
#include ../global_constants

all: build

build: libcomponent.so

libcomponent.so: libcomponent.o
	${CC} ${BASIC_CFLAGS} -shared -fPIC -o libcomponent.so libcomponent.o 

libcomponent.o: libcomponent.c
	${CC} ${BASIC_CFLAGS} -c -fPIC libcomponent.c

# -rm (with hyphen) ignores errors
clean:
	-rm *.o *.so

