include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/ins2db
TARGET2=../bin/tollfile
TARGET3=../bin/settevd
TARGET4=../bin/settbid
TARGET5=../bin/updata_intf
TARGET6=../ext/myd
TARGET7=../ext/myp
TARGET8=../ext/myq
TARGET9=../bin/t193file
TARGET11=../bin/cdma1xprep
TARGET12=../bin/chkuser
TARGET13=../bin/scpchk
TARGET14=../bin/settbid2
TARGET15=../bin/chktik
TARGET16=../bin/hbacctfile
TARGET17=../bin/imsiesn
TARGET18=../bin/sendmail
TARGET19=../bin/mytab
TARGET20=../bin/settreport
TARGET21=../bin/ciiupfile
TARGET22=../bin/tomd5
TARGET23=../bin/highticket
TARGET24=../bin/highreport
TARGET25=../bin/imei2db
TARGET26=../bin/imeiprep

OBJ_INS2DB=ins2db.o ins_impl.o ins_supp.o imsi.o
OBJ_TOLLFILE=tollfile.o get_impl.o get_supp.o
OBJ_SETTEVD=settevd.o sett_item.o get_impl.o get_supp.o 
OBJ_SETTBID=settbid.o sett_item.o get_impl.o get_supp.o
OBJ_INTF=updata_intf.o updata_ticket.o md5.o
OBJ_MYD=myd.o ins_impl.o ins_supp.o get_impl.o get_supp.o
OBJ_MYP=myp.o ins_impl.o ins_supp.o get_impl.o get_supp.o
OBJ_MYQ=myq.o ins_impl.o ins_supp.o get_impl.o get_supp.o
OBJ_MYR=myr.o ins_impl.o ins_supp.o get_impl.o get_supp.o
OBJ_T193FILE=t193file.o get_impl.o get_supp.o
OBJ_CHKUSER=chkuser.o chkuser_db.o ins_impl.o ins_supp.o get_impl.o get_supp.o
OBJ_SCPCHK=scpchk.o scp_supp.o ins_impl.o ins_supp.o get_impl.o get_supp.o
OBJ_SETTBID2=settbid2.o settbid_supp.o sett_item.o get_impl.o get_supp.o
OBJ_HBACCTFILE=hbacctfile.o updata_ticket.o md5.o
OBJ_IMSIESN=imsiesn.o imsiesn_supp.o get_supp.o
OBJ_SENDMAIL=sendmail.o
OBJ_MYTAB=mytab.o get_impl.o get_supp.o
OBJ_SETTREPORT=settreport.o sett_item.o get_impl.o get_supp.o settreport_supp.o
OBJ_CIIUPFILE=ciiupfile.o get_impl.o get_supp.o ../public/gen_supp.o
OBJ_TOMD5=tomd5.o
OBJ_HIGHTICKET=highticket.o high_supp.o ../shed/appsupp.o
OBJ_HIGHREPORT=highreport.o high_supp.o
OBJ_IMEI2DB=imei2db.o imei_supp.o
OBJ_IMEIPREP=imeiprep.o imei_supp.o

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
	$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12) \
	$(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) $(TARGET17) \
	$(TARGET18) $(TARGET19) $(TARGET20) $(TARGET21) $(TARGET22)

high:$(TARGET23) $(TARGET24)
all1:$(TARGET25) $(TARGET26)
test:$(TARGET1)


CLEANFILES=sett_item.c ins_supp.c get_supp.c highcharge.c chkdbf.c \
	scp_supp.c other_supp.c chkuser_db.c settbid_supp.c imsiesn_supp.c \
	sendmail.c imei_supp.c settreport_supp.c *.lis

$(TARGET1): $(OBJ_INS2DB)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_INS2DB)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_TOLLFILE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_TOLLFILE)" EXE=$@ build_libpd
$(TARGET3): $(OBJ_SETTEVD)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETTEVD)" EXE=$@ build_libpd
$(TARGET4): $(OBJ_SETTBID)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETTBID)" EXE=$@ build_libpd
$(TARGET5): $(OBJ_INTF)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_INTF)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_MYD)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_MYD)" EXE=$@ build_libpd
$(TARGET7): $(OBJ_MYP)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_MYP)" EXE=$@ build_libpd
$(TARGET8): $(OBJ_MYQ)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_MYQ)" EXE=$@ build_libpd
$(TARGET9): $(OBJ_T193FILE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_T193FILE)" EXE=$@ build_libpd
$(TARGET11): cdma1xprep.o
	$(MAKE) -f $(MAKEFILE) OBJS="cdma1xprep.o" EXE=$@ build_libos
$(TARGET12):  $(OBJ_CHKUSER)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_CHKUSER)" EXE=$@ build_libpd
$(TARGET13):  $(OBJ_SCPCHK)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SCPCHK)" EXE=$@ build_libpd
$(TARGET14): $(OBJ_SETTBID2)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETTBID2)" EXE=$@ build_libpd
$(TARGET15): chktik.o other_supp.o 
	$(MAKE) -f $(MAKEFILE) OBJS="chktik.o other_supp.o" EXE=$@ build_libpd
$(TARGET16): $(OBJ_HBACCTFILE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_HBACCTFILE)" EXE=$@ build_libpd
$(TARGET17): $(OBJ_IMSIESN)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_IMSIESN)" EXE=$@ build_libdb
$(TARGET18): $(OBJ_SENDMAIL)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SENDMAIL)" EXE=$@ build_libdb
$(TARGET19): $(OBJ_MYTAB)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_MYTAB)" EXE=$@ build_libdb
$(TARGET20): $(OBJ_SETTREPORT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETTREPORT)" EXE=$@ build_libpd
$(TARGET21): $(OBJ_CIIUPFILE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_CIIUPFILE)" EXE=$@ build_libpd
$(TARGET22): $(OBJ_TOMD5)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_TOMD5)" EXE=$@ build_libpd
$(TARGET23): $(OBJ_HIGHTICKET)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_HIGHTICKET)" EXE=$@ build_libpd
$(TARGET24): $(OBJ_HIGHREPORT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_HIGHREPORT)" EXE=$@ build_libpd
$(TARGET25): $(OBJ_IMEI2DB)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_IMEI2DB)" EXE=$@ build_libpd
$(TARGET26): $(OBJ_IMEIPREP)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_IMEIPREP)" EXE=$@ build_libpd
	
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) \
	$(TARGET12) $(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) \
	$(TARGET17) $(TARGET18) $(TARGET19) $(TARGET20) $(TARGET21) $(TARGET22) \
	$(TARGET23) $(TARGET24) *.o *.lis $(CLEANFILES)
	
clean1:
	$(RM) -f $(TARGET25) $(TARGET26) imei_supp.c imei_supp.o imei2db.o imeiprep.o
cleantest:
	$(RM) -f $(TARGET1) ins_supp.o ins_supp.c ins2db.o
cleanhigh:
	$(RM) -f $(TARGET23) $(TARGET24) high_supp.c high_supp.o highticket.o highreport.o