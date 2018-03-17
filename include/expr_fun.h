#ifndef __EXPR_FUN_H__
#define __EXPR_FUN_H__

#include "wwcoding.h"


void RegExprFun();
void InitFileDataDate();

extern char	sFileDataDate[15];

int mv_sp2bp(int d1,int r);
int mv_bp2sp(int d1,int r);
int clear_variant(int d1,int r);

#endif

