include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/chkts
TARGET2=../bin/chkpick
TARGET3=../bin/chkdelay
TARGET4=../bin/chkdatadelay
TARGET5=../bin/chkcnt
TARGET6=../bin/chktrunk
TARGET7=../bin/chkfileseq
TARGET8=../bin/fileverify
TARGET9=../bin/recordverify

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
$(TARGET7) $(TARGET8) $(TARGET9)

CLEANFILES=
$(TARGET1):chkts.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkts.o" EXE=$@ build_libdb

$(TARGET2): chkpick.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkpick.o" EXE=$@ build_libdb

$(TARGET3): chkdelay.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkdelay.o" EXE=$@ build_libdb

$(TARGET4): chkdatadelay.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkdatadelay.o" EXE=$@ build_libdb

$(TARGET5): chkcnt.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkcnt.o" EXE=$@ build_libdb

$(TARGET6): chktrunk.o
	$(MAKE) -f $(MAKEFILE) OBJS="chktrunk.o" EXE=$@ build_libdb

$(TARGET7): chkfileseq.o
	$(MAKE) -f $(MAKEFILE) OBJS="chkfileseq.o" EXE=$@ build_libdb

$(TARGET8): fileverify.o
	$(MAKE) -f $(MAKEFILE) OBJS="fileverify.o" EXE=$@ build_libpa

$(TARGET9): recordverify.o
	$(MAKE) -f $(MAKEFILE) OBJS="recordverify.o" EXE=$@ build_libpa

clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) *.o $(CLEANFILES)
