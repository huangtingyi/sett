include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../ext/cmdserv
TARGET2=../ext/huaweiagent
TARGET3=../ext/bellagent
TARGET4=../ext/cmdnode
TARGET5=../ext/cdmaresult
TARGET6=../ext/huaweicmd
TARGET7=../ext/bellcmd
TARGET9=../ext/cdmaadapt
TARGET10=../ext/nortelcmd
TARGET11=../ext/nortelagent
TARGET12=../ext/c1xadapt

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) \
	$(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12)
$(TARGET1): cmdserv.o cmdsupp.o intfcmd.o
	$(MAKE) -f $(MAKEFILE) OBJS="cmdserv.o cmdsupp.o intfcmd.o" EXE=$@ build_libpd
$(TARGET2): huaweiagent.o cmdsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="huaweiagent.o cmdsupp.o" EXE=$@ build_libpd
$(TARGET3): bellagent.o cmdsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="bellagent.o cmdsupp.o" EXE=$@ build_libpd
$(TARGET4): cmdnode.o
	$(MAKE) -f $(MAKEFILE) OBJS="cmdnode.o" EXE=$@ build_libos
$(TARGET5): cdmaresult.o intfcmd.o cmdsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="cdmaresult.o intfcmd.o cmdsupp.o" EXE=$@ build_libpd
$(TARGET6): huaweicmd.o cmdparse.o cmdsupp.o 
	$(MAKE) -f $(MAKEFILE) OBJS="huaweicmd.o cmdparse.o cmdsupp.o" EXE=$@ build_libpd
$(TARGET7): bellcmd.o cmdparse.o cmdsupp.o 
	$(MAKE) -f $(MAKEFILE) OBJS="bellcmd.o cmdparse.o cmdsupp.o" EXE=$@ build_libpd
$(TARGET9): cdmaadapt.o intfcmd.o cmdsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="cdmaadapt.o intfcmd.o cmdsupp.o" EXE=$@ build_libpd
$(TARGET10): nortelcmd.o cmdparse.o cmdsupp.o 
	$(MAKE) -f $(MAKEFILE) OBJS="nortelcmd.o cmdparse.o cmdsupp.o" EXE=$@ build_libpd
$(TARGET11): nortel1xagent.o cmdsupp.o 
	$(MAKE) -f $(MAKEFILE) OBJS="nortel1xagent.o cmdsupp.o" EXE=$@ build_libpd	
$(TARGET12): c1xadapt.o intfcmd.o cmdsupp.o
	$(MAKE) -f $(MAKEFILE) OBJS="c1xadapt.o  intfcmd.o cmdsupp.o" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) \
	$(TARGET10) $(TARGET11) $(TARGET12) intfcmd.c *.o $(CLEANFILES)
