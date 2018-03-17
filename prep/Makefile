include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/chkdup
TARGET2=../bin/prep
TARGET3=../bin/abc

all:$(TARGET1) $(TARGET2) 

$(TARGET1): chkdup.o dupsupp.o chkdup_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkdup.o dupsupp.o chkdup_supp.o" EXE=$@ build_libpd
$(TARGET2): prep.o
	$(MAKE) -f $(MAKEFILE) OBJS="prep.o" EXE=$@ build_libpa
clean:
	$(RM) -f $(TARGET1) $(TARGET2) dupsupp.c *.o *.lis $(CLEANFILES)

