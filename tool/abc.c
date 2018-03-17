#include <stdio.h>
#include <stdlib.h>

int main()
{
        int i=0;

        printf("hello world.\n");

        while(i<20000){
                if(malloc(1024*1024)==NULL){
                        printf("hello fail.i=%d.\n",i);
                        break;
                }
                i++;
        }

        printf("hello success.i=%d.\n",i);

        return 0;
}

