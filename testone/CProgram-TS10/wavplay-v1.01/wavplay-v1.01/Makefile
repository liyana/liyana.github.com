PROG = wavplay
OBJS = wavplay.o play.o
SRCS = wavplay.c play.c

CC = gcc
CFLAGS = -Wall -O2 -DDEBUG
LDFLAGS = 
LIBS =

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROG) $(LIBS)

clean:
	rm -f wavplay *.o
