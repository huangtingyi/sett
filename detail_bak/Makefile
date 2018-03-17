include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/prepdetail
TARGET2=../bin/auditdetail

OBJ_PREP_DETAIL=detail_intf.o detail_supp.o prepdetail.o
OBJ_AUDIT_DETAIL=detail_intf.o detail_supp.o auditdetail.o

all:$(TARGET1) $(TARGET2) 

$(TARGET1): $(OBJ_PREP_DETAIL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_PREP_DETAIL)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_AUDIT_DETAIL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_AUDIT_DETAIL)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET1) detail_supp.c *.o *.lis $(CLEANFILES)
cp:
	cp $(TARGET1) $(TARGET2) ../../bin/
	
