include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET1=../bin/sms_stat
TARGET2=../bin/sp_prop
TARGET3=../bin/t130_ord
TARGET4=../bin/user_stat
TARGET5=../bin/znw_file
TARGET6=../bin/sett_sum
TARGET7=../bin/stt_file
TARGET8=../bin/getpickparam
TARGET9=../bin/sett_nbr_stat_new
TARGET10=../bin/msisdn_imsi_stat

OBJ_STT=../case/get_impl.o ../case/get_supp.o ../case/ins_impl.o ../case/ins_supp.o

OBJ_SMS_STAT=sms_stat.o $(OBJ_STT)
OBJ_SP_PROP=sp_prop.o $(OBJ_STT)
OBJ_T130_ORD=t130_ord.o t130_supp.o
OBJ_USER_STAT=user_stat.o $(OBJ_STT)
OBJ_ZNW_FILE=znw_file.o $(OBJ_STT)
OBJ_SETT_SUM=sett_sum.o $(OBJ_STT)
OBJ_STT_FILE=stt_file.o $(OBJ_STT) ../case/sett_item.o
OBJ_GETPICKPARAM=getpickparam.c ../public/gen_supp.o

OBJ_SETT_NBR_STAT=sett_nbr_stat.c sett_nbr_supp.o $(OBJ_STT)  ../serv/serv_intf.o ../srtaudit/sett_supp.o

OBJ_MSISDN_IMSI_STAT=msisdn_imsi_stat.o msisdn_imsi.o ../case/get_supp.o



all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
$(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10)

test:$(TARGET9)

CLEANFILES=t130_supp.c user_stat_supp.c znw_file_supp.c sett_sum_supp.c \
stt_file_supp.c gen_supp.c sett_nbr_supp.c msisdn_imsi.c

$(TARGET1): $(OBJ_SMS_STAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SMS_STAT)" EXE=$@ build_libpd
$(TARGET2): $(OBJ_SP_PROP)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SP_PROP)" EXE=$@ build_libpd
$(TARGET3): $(OBJ_T130_ORD)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_T130_ORD)" EXE=$@ build_libpd
$(TARGET4): $(OBJ_USER_STAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_USER_STAT)" EXE=$@ build_libpd
$(TARGET5): $(OBJ_ZNW_FILE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_ZNW_FILE)" EXE=$@ build_libpd
$(TARGET6): $(OBJ_SETT_SUM)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETT_SUM)" EXE=$@ build_libpd
$(TARGET7): $(OBJ_STT_FILE)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_STT_FILE)" EXE=$@ build_libpd
$(TARGET8): $(OBJ_GETPICKPARAM)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_GETPICKPARAM)" EXE=$@ build_libpd
$(TARGET9): $(OBJ_SETT_NBR_STAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_SETT_NBR_STAT)" EXE=$@ build_libpd
$(TARGET10): $(OBJ_MSISDN_IMSI_STAT)
	$(MAKE) -f $(MAKEFILE) OBJS="$(OBJ_MSISDN_IMSI_STAT)" EXE=$@ build_libpd
clean:
	$(RM) -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) \
	$(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) *.o *.lis $(CLEANFILES)
