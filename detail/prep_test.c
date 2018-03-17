#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

char seps[] = " \t\n";

int main(int argc, char **argv)
{
	char UserNum[10][5][3][20], TicketNum[10][5][3][20], CallNum[10][5][3][20];
	char stmp[1024], string[10][20];
	char *token;
	int i, subs[3];
	FILE *fp1, *fp2;
	if((fp1 = fopen("./test.in","r")) == NULL)
	{
		printf("Open test.in fail!\n");
		exit(1);
	}
		
	while(fgets(stmp, 1024, fp1) != NULL){
		//printf("%s", stmp);
		token = strtok(stmp, seps);
		i = 0;
		while(token != NULL){//½ØÈ¥×Ö·û´®
				strcpy(string[i], token);
				token = strtok(NULL, seps);
				AllTrim(string[i++]);
		}
		
		subs[0] = atoi(string[0]);
		subs[1] = atoi(string[1]);
		subs[2] = atoi(string[2]);
		strcpy(UserNum[600 - subs[0]][subs[1]][subs[2]], string[3]);
		strcpy(TicketNum[600 - subs[0]][subs[1]][subs[2]], string[4]);
		strcpy(CallNum[600 - subs[0]][subs[1]][subs[2]], string[5]);
	}
	for(i = 9; i!=0; i--){
		printf("%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n",UserNum[i][0][2], UserNum[i][0][1], 
				 UserNum[i][1][2], UserNum[i][1][1], UserNum[i][2][2], UserNum[i][2][1],
				 UserNum[i][3][2], UserNum[i][4][2], UserNum[i][3][1], UserNum[i][4][1]);
		printf("%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n",TicketNum[i][0][2], TicketNum[i][0][1], 
				 TicketNum[i][1][2], TicketNum[i][1][1], TicketNum[i][2][2], TicketNum[i][2][1],
				 TicketNum[i][3][2], TicketNum[i][4][2], TicketNum[i][3][1], TicketNum[i][4][1]);
		printf("%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n\n",CallNum[i][0][2], CallNum[i][0][1], 
				 CallNum[i][1][2], CallNum[i][1][1], CallNum[i][2][2], CallNum[i][2][1],
				 CallNum[i][3][2], CallNum[i][4][2], CallNum[i][3][1], CallNum[i][4][1]);
	}
	fclose(fp1);
	return 0;
}
