include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../ext/splitfile
TARGET2=../ext/splitfile2
TARGET3=../ext/myf
TARGET4=../ext/myl
TARGET5=../ext/cdma1xup_ret
TARGET6=../ext/btb
TARGET7=../bin/filesplit
TARGET8=../ext/btp
TARGET9=../ext/btq
TARGET10=../ext/btr
TARGET11=../ext/bts
TARGET12=../bin/gensql
TARGET13=../bin/gensqljc
TARGET14=../bin/gensqlbak
TARGET15=../bin/gensqljctj

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
	$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12) $(TARGET13) \
	$(TARGET14) $(TARGET15)

CLEANFILES=

$(TARGET1): splitfile.o
	$(MAKE) -f $(MAKEFILE) OBJS="splitfile.o" EXE=$@ build_libos
$(TARGET2): splitfile2.o
	$(MAKE) -f $(MAKEFILE) OBJS="splitfile2.o" EXE=$@ build_libos
$(TARGET3): myf.o ../case/get_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="myf.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET4): myl.o
	$(MAKE) -f $(MAKEFILE) OBJS="myl.o" EXE=$@ build_libos
$(TARGET5): cdma1xup_ret.o
	$(MAKE) -f $(MAKEFILE) OBJS="cdma1xup_ret.o" EXE=$@ build_libos
$(TARGET6): btb.o ../case/get_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="btb.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET7): filesplit.o 
	$(MAKE) -f $(MAKEFILE) OBJS="filesplit.o" EXE=$@ build_libpa
$(TARGET8): btp.o ../case/get_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="btp.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET9): btq.o ../case/get_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="btq.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET10): btr.o ../case/get_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="btr.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET11): bts.o ../case/get_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="bts.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET12): gensql.o
	$(MAKE) -f $(MAKEFILE) OBJS="gensql.o" EXE=$@ build_libos
$(TARGET13): gensqljc.o
	$(MAKE) -f $(MAKEFILE) OBJS="gensqljc.o" EXE=$@ build_libos
$(TARGET14): gensqlbak.o
	$(MAKE) -f $(MAKEFILE) OBJS="gensqlbak.o" EXE=$@ build_libos
$(TARGET15): gensqljctj.o
	$(MAKE) -f $(MAKEFILE) OBJS="gensqljctj.o" EXE=$@ build_libos
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7)  $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) \
	$(TARGET12) $(TARGET13)  $(TARGET14) $(TARGET15) *.o *.lis $(CLEANFILES)
