#
# Makefile for Menu Program
#

CC_PTHREAD_FLAGS	= -lpthread
CC_FLAGS			= -c
CC_OUTPUT_FLAGS		= -o
CC 					= gcc
RM 					= rm
RM_FLAGS 			= -f

TARGET = test
OBJS   = linkTable.o linkList.o attion.o test.o menu.o 

all:	$(OBJS)
	$(CC) $(OBJS) $(CC_PTHREAD_FLAGS) $(CC_OUTPUT_FLAGS) $(TARGET)

.c.o:
	$(CC) $(CC_FLAGS) $<

clean:
	$(RM) $(RM_FLAGS) $(OBJS) $(TARGET) *.bak
