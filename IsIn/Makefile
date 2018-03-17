include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/intable_a


OBJ_CALLBILL=intable.o isselect.o 

CLEANFILES=isselect.c *.o *.lis 

all:$(TARGET1) 

$(TARGET1): $(OBJ_CALLBILL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_CALLBILL)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(CLEANFILES)
