include ../makebss/Make.defines
MAKEFILE = ./Makefile

TARGET1=../bin/settnbrstat
TARGET2=../bin/settstat


all: $(TARGET1) $(TARGET2)
CLEANFILES=*.a *.lis *.o 


OBJ_SETTNBRSTAT=settnbrstat.o ausett_supp.o ausett_intf.o ../case/get_impl.o ../case/get_supp.o
OBJ_SETTSTAT=settstat.o ausett_supp.o ausett_intf.o ../case/get_impl.o ../case/get_supp.o

$(TARGET1): $(OBJ_SETTNBRSTAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETTNBRSTAT)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_SETTSTAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETTSTAT)" EXE=$@ build_libpd
clean:
	$(RM) -f $(CLEANFILES) $(TARGET1) $(TARGET2) ausett_supp.c
