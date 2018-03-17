include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/prepdetail
TARGET2=../bin/auditdetail
TARGET3=../bin/prep_test
TARGET4=../bin/intable_a

OBJ_PREP_DETAIL=detail_intf.o detail_supp.o prepdetail.o
OBJ_AUDIT_DETAIL=detail_intf.o detail_supp.o auditdetail.o
OBJ_INTABLE=intable.o isselect.o

all:$(TARGET1) $(TARGET2) $(TARGET4)
test:$(TARGET3)

$(TARGET1): $(OBJ_PREP_DETAIL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_PREP_DETAIL)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_AUDIT_DETAIL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_AUDIT_DETAIL)" EXE=$@ build_libpd
$(TARGET3): prep_test.o
	$(MAKE) -f $(MAKEFILE) OBJS="prep_test.o" EXE=$@ build_libpd
$(TARGET4): $(OBJ_INTABLE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_INTABLE)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) isselect.c detail_supp.c *.o *.lis $(CLEANFILES)
cp:
	cp $(TARGET1) $(TARGET2) ../../bin/
	
