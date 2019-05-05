

OBJ     = download.o
LDADD   = -lcurl

download: $(OBJ)
	${CC} ${OBJ} -o download ${LDADD}


.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f test *.o

