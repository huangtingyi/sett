include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET4=../bin/rate3
TARGET5=../bin/rate3r
TARGET6=../bin/userdata_supp
TARGET7=../bin/ma

OBJ_RATE3=rate3.o ../billing/ticket.o userdata.o shmbintree.o user_ticket.o
OBJ_RATE3R=rate3r.o ../billing/ticket.o userdata.o shmbintree.o user_ticket.o
OBJ_USERDATA=userdata_supp.o userdata.o shmbintree.o user_ticket.o
OBJ_MA=ma.o ../billing/ticket.o userdata.o shmbintree.o user_ticket.o

all:$(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8)

$(TARGET4): $(OBJ_RATE3)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATE3)" EXE=$@ build_libpd
$(TARGET5): $(OBJ_RATE3R)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_RATE3R)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_USERDATA)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_USERDATA)" EXE=$@ build_libpd		
$(TARGET7): $(OBJ_MA)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_MA)" EXE=$@ build_libpd		
clean:
	$(RM) -f $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) *.o user_ticket.c $(CLEANFILES)
