include ../makebss/Make.defines
MAKEFILE = ./Makefile

TARGET1=../bin/highticket
TARGET2=../bin/highreport

all: $(TARGET1) $(TARGET2) 

CLEANFILES=*.a *.lis *.o


OBJ_HIGHTICKET=highticket.o high_supp.o ../shed/appsupp.o

OBJ_HIGHREPORT=highreport.o high_supp.o 

$(TARGET1): $(OBJ_HIGHTICKET)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_HIGHTICKET)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_HIGHREPORT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_HIGHREPORT)" EXE=$@ build_libpd
	
clean:
	$(RM) -f $(CLEANFILES) $(TARGET1) $(TARGET2) high_supp.c
	
	
