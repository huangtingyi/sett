include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/spdbsplit
TARGET2=../bin/spzb_intf
TARGET3=../bin/sp_prop_new
TARGET4=../bin/sp_tpup
TARGET5=../bin/sp_yssj_deal
TARGET6=../bin/sp_user_stat

OBJ_SPDB_SPLIT=spdbsplit.o spzb_ticket_supp.o  spzb_supp.o ../serv/serv_intf.o ../case/ins_impl.o ../case/ins_supp.o ../case/get_impl.o ../case/get_supp.o 
OBJ_PBZB_INTF=spzb_intf.o spzb_supp.o  spzb_ticket_supp.o ../case/get_impl.o ../case/get_supp.o 
OBJ_SP_PROP_NEW=sp_prop_new.o ../case/get_impl.o ../case/get_supp.o  spzb_ticket_supp.o spzb_supp.o 
OBJ_SP_TPUP=sp_tpup.o  spzb_ticket_supp.o ../case/get_impl.o ../case/get_supp.o  
OBJ_SP_YSSJ_DEAL=sp_yssj_deal.o  spzb_ticket_supp.o ../case/get_impl.o ../case/get_supp.o spzb_supp.o 
OBJ_SP_USER_STAT=sp_user_stat.o  spzb_ticket_supp.o ../case/get_impl.o ../case/get_supp.o spzb_supp.o 

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6)
CLEANFILES=spzb_ticket_supp.c

$(TARGET1): $(OBJ_SPDB_SPLIT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SPDB_SPLIT)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_PBZB_INTF)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_PBZB_INTF)" EXE=$@ build_libpd
$(TARGET3): $(OBJ_SP_PROP_NEW)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SP_PROP_NEW)" EXE=$@ build_libpd
$(TARGET4): $(OBJ_SP_TPUP)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SP_TPUP)" EXE=$@ build_libpd
$(TARGET5): $(OBJ_SP_YSSJ_DEAL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SP_YSSJ_DEAL)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_SP_USER_STAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SP_USER_STAT)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) *.o *.lis $(CLEANFILES)
