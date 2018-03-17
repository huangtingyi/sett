include ../makebss/Make.defines
MAKEFILE = ./Makefile

TARGET1=../bin/datediff
TARGET2=../bin/filemodifydate
TARGET3=../bin/tolocal
TARGET4=../bin/filemodifydiff
TARGET5=../bin/filebackupdate
TARGET6=../bin/getdir
TARGET7=../bin/addtime
TARGET8=../bin/readtts
TARGET9=../bin/writettt
TARGET10=../bin/ftpdirsize
TARGET11=../bin/mvfile


all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
	$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11)

$(TARGET1): datediff.o
	$(MAKE) -f $(MAKEFILE) OBJS="datediff.o" EXE=$@ build_libos
$(TARGET2): filemodifydate.o
	$(MAKE) -f $(MAKEFILE) OBJS="filemodifydate.o" EXE=$@ build_libos
$(TARGET3): tolocal.o
	$(MAKE) -f $(MAKEFILE) OBJS="tolocal.o" EXE=$@ build_libos
$(TARGET4): filemodifydiff.o
	$(MAKE) -f $(MAKEFILE) OBJS="filemodifydiff.o" EXE=$@ build_libos
$(TARGET5): filebackupdate.o
	$(MAKE) -f $(MAKEFILE) OBJS="filebackupdate.o" EXE=$@ build_libos
$(TARGET6): getdir.o
	$(MAKE) -f $(MAKEFILE) OBJS="getdir.o" EXE=$@ build_libos
$(TARGET7): addtime.o
	$(MAKE) -f $(MAKEFILE) OBJS="addtime.o" EXE=$@ build_libos
$(TARGET8): readtts.o ftam.o
	$(MAKE) -f $(MAKEFILE) OBJS="readtts.o ftam.o" EXE=$@ build_libos
$(TARGET9): writettt.o ftam.o
	$(MAKE) -f $(MAKEFILE) OBJS="writettt.o ftam.o" EXE=$@ build_libos
$(TARGET10): ftpdirsize.o
	$(MAKE) -f $(MAKEFILE) OBJS="ftpdirsize.o" EXE=$@ build_libos
$(TARGET11): mvfile.o
	$(MAKE) -f $(MAKEFILE) OBJS="mvfile.o" EXE=$@ build_libos
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
	$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) *.o $(CLEANFILES)
