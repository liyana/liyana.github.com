CROSS	= 
CC	= $(CROSS)gcc
LD	= $(CROSS)ld
AR	= $(CROSS)ar
RANLIB  = $(CROSS)ranlib
STRIP   = $(CROSS)strip

CFLAGS  = -Wall -Wshadow -Wno-trigraphs -pipe
LDFLAGS = -lm 

BIN		  = thread
SRCS		= $(BIN).c
OBJS		= $(SRCS:.c=.o)

all: $(BIN)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(BIN): $(OBJS)
	$(CC) -lm -lpthread $(OBJS) $(LDLIBS) -o thread
	$(STRIP) thread	

clean:
	rm -rf *.o
	rm -rf $(BIN)
	rm -rf *.o *.bak *.c.bak
