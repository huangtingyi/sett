include ../makebss/Make.defines
MAKEFILE = ./makefile

TARGET1=../bin/settbillstor
TARGET2=../bin/getMidStatTable_new
TARGET3=../bin/biintf_nbr_4fj_new

all: $(TARGET1) $(TARGET2) $(TARGET3)
CLEANFILES=*.a *.lis *.o sett_supp.c
 
OBJ_SETTBILLSTOR=settbillstor.o sett_supp.o ../case/get_impl.o ../case/get_supp.o \
../public/ticket_field.o ../billing/upd_supp.o ../settaudit/ausett_intf.o \
../settaudit/ausett_supp.o ../shed/appsupp.o

OBJ_GETMIDSTATTABLE=getMidStatTable.o sett_supp.o ../case/get_impl.o ../case/get_supp.o \
../public/ticket_field.o ../billing/upd_supp.o ../settaudit/ausett_intf.o \
../settaudit/ausett_supp.o ../shed/appsupp.o

OBJ_BIINTFNBR4FJ=biintf_nbr_4fj.o sett_supp.o ../stat/sett_nbr_supp.o ../intf/biintf_nbr_supp.o 

$(TARGET1): $(OBJ_SETTBILLSTOR)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETTBILLSTOR)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_GETMIDSTATTABLE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_GETMIDSTATTABLE)" EXE=$@ build_libpd
$(TARGET3): $(OBJ_BIINTFNBR4FJ)                                         
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_BIINTFNBR4FJ)" EXE=$@ build_libpd

clean:
	$(RM) -f $(CLEANFILES) $(TARGET1) $(TARGET2) $(TARGET3)
