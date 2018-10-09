#include<stdio.h>
#include<string.h>
#include <errno.h>
#define KRED  "\e[91m"
#define KBOLD  "\e[1m"
#define KWHT  "\x1B[37m"
#define KNRM  "\e[0m"
int main(int argc, char *argv[]) {
    FILE *fp;
    char c;
    int pos[100];
    int i=0, occ = 0,j=0,k;
    if (argc < 3) 
    {   printf("Not enough command line parameters given!\n");
        return 3;
    } 
    fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {   printf("File could not be opened errno is %d\n",errno);
        return 3;
    } 
     while ((c = getc(fp)) != EOF)
    {   
        if(c==argv[2][j])
        {   
            j++;
        }
        else
        {   j=0;
        
        } 
        if(j==strlen(argv[2]))
        {   j=0;
            pos[occ]=i-strlen(argv[2]);
            occ++;
        } 
        i++;
    }
    fseek(fp, 0, SEEK_SET);
    i=0;j=0;
    while ((c = getc(fp)) != EOF)
    {   if(i==pos[j])
        {   for(k=0;k<=strlen(argv[2]);k++)
            {   printf("%s%s%c", KRED,KBOLD,c);
                c = getc(fp);
                i++;
            }
            j++;
        }  
        printf("%s%s%c",KNRM,KWHT,c);
        i++;
    }    
    printf("%d\n",occ);
    fclose(fp);
    return 1;
}
