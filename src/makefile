IDIR =../include
CC=gcc
CFLAGS=-Wall -I$(IDIR)


ODIR=../obj
LDIR =../lib

LIBS=-lm -L$(LDIR)

_DEPS = sphere.h disc.h triangle.h tetrahedron.h

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = shape.o sphere.o disc.o triangle.o tetrahedron.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) ${args}

../bin/shape: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) ${args}

.PHONY: clean run

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

run:
	../bin/shape.exe
