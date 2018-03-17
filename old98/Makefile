include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/ferr
TARGET2=../bin/prep_split
TARGET3=../bin/sp_prop
TARGET4=../bin/toll_voip193
TARGET5=../bin/tll_dat_stat
TARGET6=../bin/dayly_stat

OBJ_FERR=ferr.o ../case/get_impl.o ../case/get_supp.o ../case/ins_impl.o ../case/ins_supp.o
OBJ_PREP_SPLIT=prep_split.o ../case/get_supp.o ../case/ins_supp.o
OBJ_SP_PROP=sp_prop.o ../case/get_impl.o ../case/get_supp.o ../case/ins_impl.o ../case/ins_supp.o
OBJ_TLL_DAT_STAT=tll_dat_stat.o  tll_dat_stat_supp.o ../case/ins_supp.o ../case/get_supp.o
OBJ_TOLL_VOIP193=toll_voip193.o toll_voip193_supp.o
OBJ_DAYLY_STAT=dayly_stat.o dayly_stat_supp.o ../case/get_impl.o ../case/get_supp.o ../serv/serv_intf.o

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12)

CLEANFILES=

$(TARGET1): $(OBJ_FERR)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_FERR)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_PREP_SPLIT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_PREP_SPLIT)" EXE=$@ build_libpd
$(TARGET3): $(OBJ_SP_PROP)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SP_PROP)" EXE=$@ build_libpd
$(TARGET4): $(OBJ_TOLL_VOIP193)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_TOLL_VOIP193)" EXE=$@ build_libpd
$(TARGET5): $(OBJ_TLL_DAT_STAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_TLL_DAT_STAT)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_DAYLY_STAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_DAYLY_STAT)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7)  $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) \
	$(TARGET12) *.o *.lis $(CLEANFILES)
