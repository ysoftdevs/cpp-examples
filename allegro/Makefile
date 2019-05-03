
EXAMPLE_OBJECTS_01 = example-01.o
EXAMPLE_OBJECTS_02 = example-02.o
EXAMPLE_OBJECTS_03 = example-03.o

CFLAGS  = `pkg-config --cflags allegro-5 allegro_image-5`
LDADD   = `pkg-config --libs allegro-5 allegro_image-5`

all: example-01 example-02 example-03

example-01: $(EXAMPLE_OBJECTS_01)
	${CC} -o example-01 ${EXAMPLE_OBJECTS_01} ${LDADD}

example-02: $(EXAMPLE_OBJECTS_02)
	${CC} -o example-02 ${EXAMPLE_OBJECTS_02} ${LDADD}

example-03: $(EXAMPLE_OBJECTS_03)
	${CC} -o example-03 ${EXAMPLE_OBJECTS_03} ${LDADD}

.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f example-01 example-02 example-03 *.o

