include ../makebss/Make.defines
MAKEFILE = ./Makefile
TARGET3= ../bin/arch
TARGET4= ../bin/sample

all:libpb.a $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET6) $(TARGET7) $(TARGET8)
CLEANFILES=*.a *.lis *.o intfsupp.c

ARCH_OBJS=arch.o intfsupp.o se.o servac.o ac.o servpr.o interface.o

$(TARGET3): $(ARCH_OBJS)
	$(MAKE) -f $(MAKEFILE) OBJS="$(ARCH_OBJS)" EXE=$@ build_libpd
$(TARGET4): sample.o 
	$(MAKE) -f $(MAKEFILE) OBJS="sample.o" EXE=$@ build_libpb


LIB_OBJS = interface.o

libpb.a:$(LIB_OBJS)
	$(RM) -rf libpb.a
	$(AR) libpb.a $(LIB_OBJS)
	$(CP) libpb.a $(LIB_PATH)

clean:
	$(RM) -f ../lib/libpb.a $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(CLEANFILES)
