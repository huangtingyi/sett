include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/billing
TARGET4=../bin/rate

TARGET5=../bin/ratercyl
TARGET6=../bin/billrcyl

TARGET8=../bin/billroll
TARGET9=../bin/rateroll

TARGET10=../bin/billrollx

TARGET11=../bin/preprcyl

OBJ_BILLING=billing.o bill_supp.o
OBJ_RATE=rate.o bill_supp.o
OBJ_BILLRCYL=billrcyl.o fileout.o ../case/get_impl.o ../case/get_supp.o bill_supp.o 
OBJ_RATERCYL=ratercyl.o fileout.o ../case/get_impl.o ../case/get_supp.o
OBJ_PREPRCYL=preprcyl.o fileout.o ../case/get_impl.o ../case/get_supp.o
OBJ_BILLROLL=billroll.o ../case/get_impl.o ../case/get_supp.o
OBJ_RATEROLL=rateroll.o ../case/get_impl.o ../case/get_supp.o upd_supp.o
OBJ_BILLROLLX=billrollx.o ../case/get_impl.o ../case/get_supp.o


all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET11)

$(TARGET1): $(OBJ_BILLING)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILLING)" EXE=$@ build_libpa
$(TARGET4): $(OBJ_RATE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATE)" EXE=$@ build_libpa
$(TARGET5): $(OBJ_RATERCYL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATERCYL)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_BILLRCYL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILLRCYL)" EXE=$@ build_libpd
$(TARGET8): $(OBJ_BILLROLL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILLROLL)" EXE=$@ build_libpd
$(TARGET9): $(OBJ_RATEROLL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATEROLL)" EXE=$@ build_libpd
$(TARGET10): $(OBJ_BILLROLLX)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILLROLLX)" EXE=$@ build_libpd
$(TARGET11): $(OBJ_PREPRCYL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_PREPRCYL)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) \
	$(TARGET11) *.o *.lis $(CLEANFILES)
