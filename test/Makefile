include ../makebss/Make.defines
MAKEFILE=./Makefile
TARGET1=../ext/telnettest
TARGET2=../ext/servtest
TARGET3=../ext/socktest
TARGET4=../bin/unsql
TARGET5=../ext/testds
TARGET6=../ext/mytest1
TARGET7=../ext/mytest2
TARGET8=../ext/mytest3
TARGET9=../ext/param_test
TARGET10=../bin/chkdbf
TARGET11=../bin/dmpdbf
TARGET12=../bin/proxy
TARGET14=../ext/proe
TARGET15=../bin/like
TARGET16=../ext/prol
TARGET17=../ext/lexhtm
TARGET18=../ext/cvhtm
TARGET19=../ext/dir2list
TARGET20=../ext/locktest

CLEANFILES= chkdbf.c sms_supp.c

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) \
	$(TARGET11) $(TARGET13) $(TARGET14) $(TARGET15) \
	$(TARGET16) $(TARGET17) $(TARGET18) $(TARGET19) $(TARGET20)

$(TARGET1): telnettest.o
	$(MAKE) -f $(MAKEFILE) OBJS="telnettest.o " EXE=$@ build_libos
$(TARGET2): servtest.o 
	$(MAKE) -f $(MAKEFILE) OBJS="servtest.o " EXE=$@ build_libos
$(TARGET3): socktest.o 
	$(MAKE) -f $(MAKEFILE) OBJS="socktest.o " EXE=$@ build_libos
$(TARGET4): unsql.o
	$(MAKE) -f $(MAKEFILE) OBJS="unsql.o" EXE=$@ build_libdb
$(TARGET5): testds.o
	$(MAKE) -f $(MAKEFILE) OBJS="testds.o" EXE=$@ build_libdb
$(TARGET6): mytest1.o
	$(MAKE) -f $(MAKEFILE) OBJS="mytest1.o" EXE=$@ build_libdb
$(TARGET7): mytest2.o
	$(MAKE) -f $(MAKEFILE) OBJS="mytest2.o" EXE=$@ build_libos
$(TARGET8): mytest3.o
	$(MAKE) -f $(MAKEFILE) OBJS="mytest3.o" EXE=$@ build_libos
$(TARGET9): param_test.o
	$(MAKE) -f $(MAKEFILE) OBJS="param_test.o" EXE=$@ build_libpa
$(TARGET10): chkdbf.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkdbf.o" EXE=$@ build_libdb
$(TARGET11): dmpdbf.o
	$(MAKE) -f $(MAKEFILE) OBJS="dmpdbf.o" EXE=$@ build_libos
$(TARGET12): proxy.o
	$(MAKE) -f $(MAKEFILE) OBJS="proxy.o" EXE=$@ build
$(TARGET14): proe.o
	$(MAKE) -f $(MAKEFILE) OBJS="proe.o" EXE=$@ build_libpa
$(TARGET15): like.o
	$(MAKE) -f $(MAKEFILE) OBJS="like.o" EXE=$@ build_libos
$(TARGET16): prol.o
	$(MAKE) -f $(MAKEFILE) OBJS="prol.o" EXE=$@ build_libpa
$(TARGET17): lexhtm.o
	$(MAKE) -f $(MAKEFILE) OBJS="lexhtm.o" EXE=$@ build_libos
$(TARGET18): cvhtm.o
	$(MAKE) -f $(MAKEFILE) OBJS="cvhtm.o" EXE=$@ build_libos
$(TARGET19): dir2list.o
	$(MAKE) -f $(MAKEFILE) OBJS="dir2list.o" EXE=$@ build_libos
$(TARGET20): locktest.o
	$(MAKE) -f $(MAKEFILE) OBJS="locktest.o" EXE=$@ build_libos
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) \
	$(TARGET12) $(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) \
	$(TARGET17) $(TARGET18) $(TARGET19) $(TARGET20) *.lis *.o $(CLEANFILES)
