include ../makebss/Make.defines
MAKEFILE=./Makefile
TARGET1=../bin/kpistat
TARGET2=../bin/kpiintf_4fj
TARGET3=../bin/kpiintf_4gs
TARGET4=../bin/kpiintf_4nx


CLEANFILES= kpistat_supp.c

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

$(TARGET1): kpistat.o kpistat_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="kpistat.o kpistat_supp.o" EXE=$@ build_libdb
$(TARGET2): kpiintf_4fj.o kpistat_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="kpiintf_4fj.o kpistat_supp.o" EXE=$@ build_libdb
$(TARGET3): kpiintf_4gs.o kpistat_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="kpiintf_4gs.o kpistat_supp.o" EXE=$@ build_libdb
$(TARGET4): kpiintf_4nx.o kpistat_supp.o
	$(MAKE) -f $(MAKEFILE) OBJS="kpiintf_4nx.o kpistat_supp.o" EXE=$@ build_libdb

clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) \
	 *.lis *.o $(CLEANFILES)
