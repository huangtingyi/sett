#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>
#include <wwfile.h>
#include <wwdir.h>
#include <stt_ticket.h>
#include <dbsupp.h>

int main( int argc, char **argv )
{
	struct MyTabColumnsStruct *ptHead=NULL;
	char sTableName[32],statement[8192];

	if( argc != 2 ){
		printf("Usage %s table_name.\n",argv[0]);
		return -1;
	}

	strcpy(sTableName,argv[1]);
	Upper(sTableName);

	InitAppRes(argv[0]);

	if(ConnectDataDB()<0) return -1;

/*	if(GetXStrTableName(sTableName,"WHERE ROWNUM<10",statement)<0)
		return -1;
*/	

	if(InitMyTabColumns(sTableName,&ptHead)<0) return -1;
	
	GetUpdSqlStmt(ptHead,sTableName,statement);

	printf("%s",statement);

	CommitWork();
	DisconnectDatabase();
	return 0;
}
