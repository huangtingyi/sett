#include <stdio.h>
#include <stdlib.h>

struct TNls_lang {
	int	iCode;
	char	*sLang;
};

struct TNls_lang *PTNls_lang;

struct TNls_lang pNls_lang[] = {
	{ 1,   "US7ASCII"       },
	{ 850, "ZHS16CGB231280" },
	{ 860, "ZHT32EUC"       },
	{ 852, "ZHS16GBK"       },
	{ 861, "ZHT32SOPS"      },
	{ 862, "ZHT16DBT"       },
	{ 863, "ZHT32TRIS"      },
	{ 865, "ZHT16BIG5"      },
};

int main(int argc, char *argv[])
{
	FILE * fp;
	int   i, j, iCurNum, iOriNum;
	char  sCurTag[2], sOriTag[2];

	if (argc < 3) {
		printf("Usage:%s iCurNumber filename...\n", argv[0]);
		for (i = 0;i<sizeof(pNls_lang)/sizeof(pNls_lang[0]);i++)
	    		printf("%3d, %s\n",
	    			pNls_lang[i].iCode,pNls_lang[i].sLang);
		return -1;
	}
	iCurNum = atoi(argv[1]);

/*检查字符集的合法性*/
	for (i=0,j=-1;i<sizeof(pNls_lang)/sizeof(pNls_lang[0]);i++){
		if (iCurNum == pNls_lang[i].iCode) {
			j = i;
			break;
		}
	}
	if (j<0){
		printf("Not found Nls_lang for %d\n", iCurNum);
		return -2;
	}
	sCurTag[0]=iCurNum/256;sCurTag[1]=iCurNum%256;

/*将dmp文件的字符集改为合适的字符集*/
	for (i = 2; i < argc; i++) {
		fp  = fopen(argv[i], "r+");
		if (!fp) {
			printf("open file %s error\n", argv[i]);
			continue;
		}
		fseek(fp,1,SEEK_SET);
		fread(sOriTag, 1, 2, fp);

		iOriNum=sOriTag[1]+256*sOriTag[0];

		fseek(fp,1,SEEK_SET);
		fwrite(sCurTag,1,2,fp);

		fclose(fp);

		printf("%s: %d => %d.\n", argv[i], iOriNum, iCurNum);
	}

	return 0;
}

