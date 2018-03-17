include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/pickcheck
TARGET2=../bin/picklog
TARGET3=../bin/prepcheck
TARGET4=../bin/preplog
TARGET5=../bin/billingcheck
TARGET6=../bin/billinglog
TARGET7=../bin/pickdup
TARGET10=../bin/dbdiff
TARGET11=../bin/verdiff
TARGET12=../bin/verprot
TARGET13=../bin/znw
TARGET14=../bin/smsdupchk
TARGET15=../ext/expch
TARGET16=../ext/cvhead
TARGET17=../bin/execsql
TARGET18=../ext/cvtrk
TARGET19=../ext/cvrpt
TARGET20=../ext/genpasswd
TARGET21=../bin/genimei
TARGET22=../ext/cvhead2
TARGET23=../bin/joincdr
TARGET24=../bin/ftxt2bin

TARGET101=../bin/putcheck
TARGET102=../bin/putlog
TARGET103=../bin/putdup
TARGET104=../bin/abc


CLEANFILES=dbdiff.c

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
	$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) \
	$(TARGET12) $(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) \
	$(TARGET17) $(TARGET18) $(TARGET19) $(TARGET20) $(TARGET21) \
	$(TARGET22) $(TARGET23) $(TARGET24) $(TARGET101) $(TARGET102) $(TARGET103)

$(TARGET1): pickcheck.o
	$(MAKE) -f $(MAKEFILE) OBJS="pickcheck.o" EXE=$@ build_libdb
$(TARGET2): picklog.o
	$(MAKE) -f $(MAKEFILE) OBJS="picklog.o" EXE=$@ build_libdb
$(TARGET3): prepcheck.o
	$(MAKE) -f $(MAKEFILE) OBJS="prepcheck.o" EXE=$@ build_libdb
$(TARGET4): preplog.o
	$(MAKE) -f $(MAKEFILE) OBJS="preplog.o" EXE=$@ build_libdb
$(TARGET5): billingcheck.o
	$(MAKE) -f $(MAKEFILE) OBJS="billingcheck.o" EXE=$@ build_libdb
$(TARGET6): billinglog.o
	$(MAKE) -f $(MAKEFILE) OBJS="billinglog.o" EXE=$@ build_libdb
$(TARGET7): pickdup.o
	$(MAKE) -f $(MAKEFILE) OBJS="pickdup.o" EXE=$@ build_libdb
$(TARGET10): dbdiff.o
	$(MAKE) -f $(MAKEFILE) OBJS="dbdiff.o" EXE=$@ build_libdb
$(TARGET11): verdiff.o
	$(MAKE) -f $(MAKEFILE) OBJS="verdiff.o" EXE=$@ build_libos
$(TARGET12): verprot.o
	$(MAKE) -f $(MAKEFILE) OBJS="verprot.o" EXE=$@ build_libos
$(TARGET13): znw.o
	$(MAKE) -f $(MAKEFILE) OBJS="znw.o" EXE=$@ build
$(TARGET14): smsdupchk.o ../case/md5.o ../case/ins_impl.o ../case/ins_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="smsdupchk.o ../case/md5.o ../case/ins_impl.o ../case/ins_supp.o" EXE=$@ build_libpd
$(TARGET15): expch.o
	$(MAKE) -f $(MAKEFILE) OBJS="expch.o" EXE=$@ build
$(TARGET16): cvhead.o
	$(MAKE) -f $(MAKEFILE) OBJS="cvhead.o" EXE=$@ build_libos
$(TARGET17): execsql.o
	$(MAKE) -f $(MAKEFILE) OBJS="execsql.o" EXE=$@ build_libdb
$(TARGET18): cvtrk.o
	$(MAKE) -f $(MAKEFILE) OBJS="cvtrk.o" EXE=$@ build_libos
$(TARGET19): cvrpt.o
	$(MAKE) -f $(MAKEFILE) OBJS="cvrpt.o" EXE=$@ build_libos
$(TARGET20): genpasswd.o
	$(MAKE) -f $(MAKEFILE) OBJS="genpasswd.o" EXE=$@ build_libpd
$(TARGET21): genimei.o
	$(MAKE) -f $(MAKEFILE) OBJS="genimei.o" EXE=$@ build_libpd
$(TARGET22): cvhead2.o
	$(MAKE) -f $(MAKEFILE) OBJS="cvhead2.o" EXE=$@ build_libos
$(TARGET23): joincdr.o
	$(MAKE) -f $(MAKEFILE) OBJS="joincdr.o" EXE=$@ build_libos
$(TARGET24): ftxt2bin.o
	$(MAKE) -f $(MAKEFILE) OBJS="ftxt2bin.o" EXE=$@ build_libos

$(TARGET104): abc.o
	$(MAKE) -f $(MAKEFILE) OBJS="abc.o" EXE=$@ build_libos
	
$(TARGET101): $(TARGET1)
	cp $(TARGET1) $(TARGET101)
$(TARGET102): $(TARGET2)
	cp $(TARGET2) $(TARGET102)
$(TARGET103): $(TARGET7)
	cp $(TARGET7) $(TARGET103)
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) \
 	$(TARGET12) $(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) \
	$(TARGET17) $(TARGET18) $(TARGET19) $(TARGET20) $(TARGET21) \
	$(TARGET22) $(TARGET23) $(TARGET24) $(TARGET101) $(TARGET102) \
	$(TARGET103) $(CLEAN_LIST) *.o *.lis $(CLEANFILES)
