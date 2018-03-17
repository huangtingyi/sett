include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/serv_supp
TARGET2=../bin/serv_test


OBJ_SERV_SUPP=serv_supp.o simple_serv.o 
OBJ_SERV_INTF=serv_test.o serv_intf.o

all:$(TARGET1) serv_intf.o $(TARGET2) 
CLEANFILES=simple_serv.c *.lis

$(TARGET1): $(OBJ_SERV_SUPP)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SERV_SUPP)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_SERV_INTF)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SERV_INTF)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) *.o $(CLEANFILES)
