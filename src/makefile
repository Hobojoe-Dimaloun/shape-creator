IDIR =../include
CC=gcc

CFLAGS= -std=c18 -Wall -Wextra -I$(IDIR)

ODIR=../obj
LDIR =../lib

LIBS= -lm -L$(LDIR)

_DEPS = sphere.h disc.h triangle.h chevron.h cuboid.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = shape.o sphere.o disc.o triangle.o chevron.o cuboid.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


../bin/shape: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean run

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

run:
	../bin/shape
