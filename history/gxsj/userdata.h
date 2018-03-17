#ifndef __USERDATA_H__
#define __USERDATA_H__
int SearchPayRelation( LONGINT lCustomerNo,LONGINT lUserNo,
	struct PayRelationStruct  **pptHead);
int SearchInfoLine( char sDeviceNumber[],struct InfoLineStruct  **pptHead );
int SearchAtomBillIntf( char sBillAtom[], int iTicketTypeID,
	struct AtomBillIntfStruct **pptHead );
void RegShmUserDataExprFun();
int CreateUserDataShmBinTree();
int GetAtomBillIntf(char sBillAtom[], int iTicketTypeID,char sResult[]);
int GetInfoLine(char sDeviceNumber[],char sResult[]);
int GetPayRelation( LONGINT lCustomerNo,LONGINT lUserNo,char sResult[]);	
#endif
