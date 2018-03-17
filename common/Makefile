include ../makebss/Make.defines

MAKEFILE = ./Makefile

TARGETS= libos.a libdb.a

PUBLIC_LIBS=

all: $(TARGETS) $(TARGET1)


CLFUNCS = wwdb.c dbsupp.c $(TARGETS)

LIB_OBJS = list.o bintree.o trie.o queue.o hnixs.o wwcoding.o wwdir.o wwfile.o wwsem.o wwshm.o wwtiny.o wwdecrypt.o wwlog.o expr.o expr_supp.o expr_fmp.o expr_var.o expr_fun.o wwnet.o wwtelnet.o wwxml.o wwsupp.o md5.o

libos.a:$(LIB_OBJS)
	$(RM) -rf libos.a
	$(AR) libos.a $(LIB_OBJS)
	$(CP) libos.a $(LIB_PATH)
	
libdb.a:wwdb.o dbsupp.o
	$(RM) -rf libdb.a
	$(AR) libdb.a wwdb.o dbsupp.o
	$(CP) libdb.a $(LIB_PATH)
	
clean:
	$(RM) -f ../lib/libdb.a ../lib/libos.a *.o $(CLFUNCS) $(CLEANFILES)
