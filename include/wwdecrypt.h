#ifndef __WW_DECRYPT_H__
#define __WW_DECRYPT_H__

#define DB_KEY    "12345678"

void decodepass(char *key,char *inblock,char * outblock);
void encodepass(char *key,char *inblock,char * outblock);

#endif
