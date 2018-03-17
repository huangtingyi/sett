include ../makebss/Make.defines
MAKEFILE = ./Makefile

TARGET1=../bin/getDetailTable
TARGET2=../bin/getMidStatTable
TARGET3=../bin/getUnlStatTable
TARGET4=../bin/anSettTrend
TARGET5=../bin/getUserTopInfo

#all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)
all: $(TARGET1) $(TARGET2) $(TARGET4) $(TARGET5)
CLEANFILES=*.a *.lis *.o


OBJ_GETDETAILTABLE=getDetailTable.o settle_supp.o ../shed/appsupp.o

OBJ_GETMIDSTATTABLE=getMidStatTable.o settle_supp.o 

OBJ_GETUNLSTATTABLE=getUnlStatTable.o settle_supp.o

OBJ_ANSETTTREND=anSettTrend.o settle_supp.o

OBJ_GETUSERTOPINFO=getUserTopInfo.o settle_supp.o

$(TARGET1): $(OBJ_GETDETAILTABLE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_GETDETAILTABLE)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_GETMIDSTATTABLE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_GETMIDSTATTABLE)" EXE=$@ build_libpd
$(TARGET3): $(OBJ_GETUNLSTATTABLE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_GETUNLSTATTABLE)" EXE=$@ build_libpd
$(TARGET4): $(OBJ_ANSETTTREND)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_ANSETTTREND)" EXE=$@ build_libpd
$(TARGET5): $(OBJ_GETUSERTOPINFO)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_GETUSERTOPINFO)" EXE=$@ build_libpd
		
clean:
	$(RM) -f $(CLEANFILES) $(TARGET1) $(TARGET2) $(TARGET3) \
	$(TARGET4) $(TARGET5) settle_supp.c
	
	
