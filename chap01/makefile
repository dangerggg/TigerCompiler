TARGET = main
CC = cc
C_FILES = $(shell ls *.c)
BASE = $(basename $(C_FILES))
OBJS = $(addsuffix .o, $(BASE))

$(TARGET): $(OBJS)
	-rm -rf $@
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	-rm -rf $(OBJS) $(TARGET)
	