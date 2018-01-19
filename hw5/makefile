OBJ=Polynomial.o anderson-bushkin-hw5.o
DEPS=Polynomial.h
CC=g++
CFLAGS=-I.
LIBS=

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Polynomial: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o *~
