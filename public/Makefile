include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/param_supp

all:libpa.a $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET6) $(TARGET7) $(TARGET8)
CLEANFILES=*.a *.lis *.o gen_supp.c

PARAM_SUPPOBJS=gen_supp.o base_supp.o param_supp.o param_intf.o
$(TARGET1): $(PARAM_SUPPOBJS)
	$(MAKE) -f $(MAKEFILE) OBJS="$(PARAM_SUPPOBJS)" EXE=$@ build_libdb

LIB_OBJS = param_intf.o ticket_field.o tariff_disct.o 

libpa.a:$(LIB_OBJS)
	$(RM) -rf libpa.a
	$(AR) libpa.a $(LIB_OBJS)
	$(CP) libpa.a $(LIB_PATH)

clean:
	$(RM) -f ../lib/libpa.a $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(CLEANFILES)
