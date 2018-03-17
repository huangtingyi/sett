include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/biintf_4fj
TARGET2=../bin/biintf_4gs
TARGET3=../bin/biintf_4xj
TARGET4=../bin/biintf_nbr_4fj

all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)
CLEANFILES=biintf_supp.c biintf_nbr_supp.c *.lis

$(TARGET1): biintf_4fj.o ../case/get_supp.o biintf_supp.o                                         
	$(MAKE) -f $(MAKEFILE) OBJS="biintf_4fj.o  biintf_supp.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET2): biintf_4gs.o ../case/get_supp.o biintf_supp.o                                              
	$(MAKE) -f $(MAKEFILE) OBJS="biintf_4gs.o  biintf_supp.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET3): biintf_4xj.o ../case/get_supp.o biintf_supp.o                                         
	$(MAKE) -f $(MAKEFILE) OBJS="biintf_4xj.o  biintf_supp.o ../case/get_supp.o" EXE=$@ build_libpd
$(TARGET4): biintf_nbr_4fj.o ../stat/sett_nbr_supp.o biintf_nbr_supp.o                                         
	$(MAKE) -f $(MAKEFILE) OBJS="biintf_nbr_4fj.o ../stat/sett_nbr_supp.o biintf_nbr_supp.o" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) *.o $(CLEANFILES)
