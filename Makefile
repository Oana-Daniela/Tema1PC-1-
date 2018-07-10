CC = gcc
CFLAGS = -Wall -lm
SRC = ip.c
EXE = ip
 

build:
	$(CC) $(SRC)  $(CFLAGS) -o $(EXE) 
run:$(EXE)
	./$(EXE)
clean:
	rm -f $(EXE) 
