
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
FILE *arg1, *arg2;
 
int main(int argc,char *argv[])
{
    char censored[100];
    arg1 = fopen(argv[1],"r");  // censored list
 
    while(fscanf(arg1,"%s",censored)!=EOF)
    {
        arg2 = fopen(argv[2],"r");  // open file
        int sayac=0, i=0;
        char ch, word[250];
 
        while( (ch=fgetc(arg2)) != EOF )
        {
            if( ('A'<=ch && ch<='Z') || ('a'<=ch && ch<='z') || ('0'<=ch && ch<='9') )  // if character in these situation
            {
                word[i]=ch;
                i++;
            }else
            {
                word[i]='\0';
                i=0;
                if(strcmp(censored,word) == 0)   // if censonred word equal to other words
                    sayac++;
            }
        }//while
 
        if(sayac != 0)  // if it has any censonred words
    {
            printf("%d adet %sn",sayac ,censored);
    }
 
    }//while
 
    return 0;
}
