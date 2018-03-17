#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwcoding.h>

int main(int argc,char **argv)
{
	int i,j,iFlag=0;
	char *pc,sInput[10],sOutput[10];

	if(argc!=2&&argc!=3){
		printf("Usage %s trk [0|1]\n",argv[0]);
		return -1;
	}
	
	strcpy(sInput,argv[1]);
	if(argc==3)iFlag=atoi(argv[2]);

	if(iFlag==0){
		if((pc=strchr(sInput,'*'))==NULL) return -1;
		pc++;
		i=atoi(sInput);
		j=atoi(pc);
		sprintf(sOutput,"%02x%02x",i,j);
		for(i=0;i<strlen(sOutput);i++)
			if(sOutput[i]>='a'&&sOutput[i]<='z')
				sOutput[i]+=('A'-'a');
	}
	else{
		char sTemp[3];
		
		strncpy(sTemp,sInput,2);sTemp[2]=0;
		i=HexStrToInt(sTemp);
		
		strncpy(sTemp,sInput+2,2);sTemp[2]=0;
		j=HexStrToInt(sTemp);
		
		sprintf(sOutput,"%d*%d",i,j);
	}

	printf("%s\n",sOutput);

	return 0;
}
