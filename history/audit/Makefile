include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/auditlog

OBJ_AUDITLOG=auditlog.o auditlog_supp.o auditlog_biz.o ../case/get_impl.o ../case/get_supp.o

all:$(TARGET1)
CLEANFILES=auditlog_supp.c

$(TARGET1): $(OBJ_AUDITLOG)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_AUDITLOG)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) *.o *.lis $(CLEANFILES)
