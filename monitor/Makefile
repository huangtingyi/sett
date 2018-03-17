include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET3=../bin/srvd

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET6) $(TARGET7) $(TARGET8)
SRVD_OBJS=srvd.o wwhttpd.o
$(TARGET3): $(SRVD_OBJS)
	$(MAKE) -f $(MAKEFILE) OBJS="$(SRVD_OBJS)" EXE=$@ build_libos
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) *.o $(CLEANFILES)
