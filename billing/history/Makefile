include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/billing
TARGET2=../ext/rateo
TARGET4=../bin/rate

TARGET5=../bin/raterecy
TARGET6=../bin/billrecy

TARGET8=../bin/billroll
TARGET9=../bin/rateroll


OBJ_BILLING=billing.o ticket.o bill_supp.o split_supp.o
OBJ_RATEO=rateo.o ticket.o split_supp.o
OBJ_RATE=rate.o ticket.o bill_supp.o split_supp.o
OBJ_RATERECY=raterecy.o ticket.o ../case/get_impl.o ../case/get_supp.o split_supp.o
OBJ_BILLRECY=billrecy.o ticket.o bill_supp.o ../case/get_impl.o ../case/get_supp.o split_supp.o
OBJ_BILLROLL=billroll.o ticket.o upd_test.o ../case/get_impl.o ../case/get_supp.o split_supp.o bill_supp.o
OBJ_RATEROLL=rateroll.o ticket.o upd_supp.o ../case/get_impl.o ../case/get_supp.o \
	../case/ins_impl.o ../case/ins_supp.o split_supp.o roll_supp.o

CLEANFILES=roll_supp.c

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
$(TARGET7) $(TARGET8) $(TARGET9)

$(TARGET1): $(OBJ_BILLING)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILLING)" EXE=$@ build_libpa
$(TARGET2): $(OBJ_RATEO)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATEO)" EXE=$@ build_libpa
$(TARGET4): $(OBJ_RATE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATE)" EXE=$@ build_libpa
$(TARGET5): $(OBJ_RATERECY)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATERECY)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_BILLRECY)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILLRECY)" EXE=$@ build_libpd
$(TARGET8): $(OBJ_BILLROLL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILLROLL)" EXE=$@ build_libpd
$(TARGET9): $(OBJ_RATEROLL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATEROLL)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) *.o *.lis $(CLEANFILES)
