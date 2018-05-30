CC=gcc
CFLAGS=-Wall
SRC=./src
BIN=./bin
INC=-I./src/include

MODULES=err debug map main analyzer parser server storage vm

default: fooql

$(MODULES):
	$(CC) $(INC) -c $(SRC)/$@/$@.c -o $(BIN)/$@.o $(CFLAGS)

objects: $(MODULES)
	$(CC) -o $(BIN)/fooql $(BIN)/*.o

fooql: objects 

.Phony : clean

clean:
	rm -f $(BIN)/*.o *.o
