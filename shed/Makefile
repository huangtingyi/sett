include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/shedtsk
TARGET2=../bin/pick_sh
TARGET3=../bin/prep_sh
TARGET4=../bin/disp_sh
TARGET5=../bin/ins2db_sh
TARGET6=../bin/bill_sh
TARGET7=../bin/putpick_sh
TARGET8=../bin/acctdb_sh
TARGET9=../bin/updata_intf_sh
TARGET10=../bin/rcyl_sh
TARGET11=../bin/roll_sh
TARGET12=../bin/acctdb

TARGET101=../bin/billing_sh
TARGET102=../bin/rate_sh
TARGET103=../bin/billrcyl_sh
TARGET104=../bin/ratercyl_sh
TARGET105=../bin/billroll_sh
TARGET106=../bin/rateroll_sh

OBJ_ACCTDB_SH=acctdb_sh.o acct_supp.o ../case/sett_item.o ../case/ins_impl.o ../case/ins_supp.o appsupp.o
OBJ_INS2DB_SH=ins2db_sh.o appsupp.o ../case/ins_impl.o ../case/ins_supp.o
OBJ_BILL_SH=bill_sh.o appsupp.o ../billing/bill_supp.o
OBJ_PREP_SH=prep_sh.o appsupp.o ../prep/chkdup_supp.o ../prep/dupsupp.o
OBJ_UPDATA_INTF_SH=updata_intf_sh.o appsupp.o
OBJ_RCYL_SH=rcyl_sh.o appsupp.o
OBJ_ROLL_SH=roll_sh.o appsupp.o
OBJ_ACCTDB=acctdb.o acct_supp.o appsupp.o ../case/sett_item.o ../case/ins_supp.o ../case/ins_impl.o 

CLEANFILES=*.lis

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
	$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12) \
	$(TARGET101) $(TARGET102) $(TARGET103) $(TARGET104) $(TARGET105) $(TARGET106)
test:$(TARGET5)
$(TARGET1): shedtsk.o
	$(MAKE) -f $(MAKEFILE) OBJS="shedtsk.o" EXE=$@ build_libos
$(TARGET2): pick_sh.o appsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="pick_sh.o appsupp.o" EXE=$@ build_libpd
$(TARGET3): $(OBJ_PREP_SH)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_PREP_SH)" EXE=$@ build_libpd
$(TARGET4): disp_sh.o appsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="disp_sh.o appsupp.o" EXE=$@ build_libpd
$(TARGET5): $(OBJ_INS2DB_SH)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_INS2DB_SH)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_BILL_SH)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BILL_SH)" EXE=$@ build_libpd
$(TARGET7): putpick_sh.o appsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="putpick_sh.o appsupp.o" EXE=$@ build_libpd
$(TARGET8): $(OBJ_ACCTDB_SH)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_ACCTDB_SH)" EXE=$@ build_libpd
$(TARGET9): $(OBJ_UPDATA_INTF_SH)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_UPDATA_INTF_SH)" EXE=$@ build_libpd
$(TARGET10): $(OBJ_RCYL_SH)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RCYL_SH)" EXE=$@ build_libpd
$(TARGET11): $(OBJ_ROLL_SH)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_ROLL_SH)" EXE=$@ build_libpd
$(TARGET12): $(OBJ_ACCTDB)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_ACCTDB)" EXE=$@ build_libpd

$(TARGET101): $(TARGET6)
	cp $(TARGET6) $(TARGET101)
$(TARGET102): $(TARGET6)
	cp $(TARGET6) $(TARGET102)
$(TARGET103): $(TARGET10)
	cp $(TARGET10) $(TARGET103)
$(TARGET104): $(TARGET10)
	cp $(TARGET10) $(TARGET104)
$(TARGET105): $(TARGET11)
	cp $(TARGET11) $(TARGET105)
$(TARGET106): $(TARGET10)
	cp $(TARGET11) $(TARGET106)

clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
 $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) \
 $(TARGET12) $(TARGET101) $(TARGET102) $(TARGET103) $(TARGET104) $(TARGET105) \
 $(TARGET106) *.o $(CLEANFILES)




