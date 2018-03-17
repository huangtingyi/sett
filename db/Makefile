include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/highcharge

OBJ_STT=../case/get_impl.o ../case/get_supp.o ../case/ins_impl.o ../case/ins_supp.o
OBJ_HIGHCHARGE=highcharge.o $(OBJ_STT)

all:$(TARGET1)

CLEANFILES=highcharge.c *.lis

$(TARGET1): $(OBJ_HIGHCHARGE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_HIGHCHARGE)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) *.o *.lis $(CLEANFILES)
