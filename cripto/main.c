#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


 #define work 1
 #define dwork 0

int matriz(int matrix[][27]);
int encrip(int matrix[][27]);
int desencrip(int matrix[][27]);


/** \brief This will fill the matriz with all the letters of the alphabet
 *
 * \return int
 *
 */
int matriz(int matrix[][27])
{

    int i,j,p=0;
    for(i=0; i<=26; i++)
    {
        p=0;
        for(j=0; j<=26; j++)
        {
            if(('A'+i+j)>'Z')
            {
                matrix[i][j]='A'+ p;
                p++;
            }
            else
            {
                matrix[i][j]='A'+ i + j;
            }
        }
    }
    return work;
}
/** \brief This function will encrypetd every word or sentence using a key(word) that you choose.
 *
 * \return int
 *
 */
int encrip(int matrix[][27])
{
    FILE *fe;
    FILE * fp;
    fe=fopen("encript.txt", "a+");
    fp=fopen("encriptsave.txt","a+");
    char palavra[255];
    char key[255];
    char palavra2[255];
    int i=0;
    int j=0;
    int p=0;
    int v=1;
    printf(" ____________________________________________________________\n");
    printf("|Attention ! This method only uses alphabetic words for keys!|\n");
    printf("|____________________________________________________________|\n");
    printf(" ____________________________________________\n");
    printf("|Word or sentece read off the file to encrypt|\n");
    printf("|____________________________________________|\n");
    fflush(stdin);
    fgets(palavra,255,fe);
    strupr(palavra);
    printf(" _____________\n");
    printf("|Insert a key |\n");
    printf("|_____________|\n");
    gets(key);
    strupr(key);
    if(strlen(key)< strlen(palavra))
    {
        v=strlen(palavra)/strlen(key);
    }
    for(i=0; i<=v; i++)
    {
        for(j=0; j<strlen(key); j++)
        {
            palavra2[p]=key[j];
            p++;
        }
    }
    palavra2[p]='\0';
    j=0;
    system("cls");
    printf(" _______________________________\n");
    printf("|word encrypted and save in file!|\n");
    printf("|________________________________|\n");
    for(i=0; i<strlen(palavra); i++)
    {
        if(palavra[i]==' ')
        {
            printf(" ");
        }
        else
        {
            if(i==0)
            {
                fprintf(fe," ");
            }
            printf("%c",matrix[palavra[i]-65][palavra2[j]-65]);
            fprintf(fp,"%c",matrix[palavra[i]-65][palavra2[j]-65]);
            j++;
        }
    }
    printf("\n");
    fclose(fe);
    fclose(fp);
    return work;
}
int desencrip(int matrix[][27])
{
    FILE *fp;
    FILE * fd;
    FILE * fn;
    fn=fopen("newdecrypt.txt","a+");
    fp=fopen("dencrypt.txt", "a+");/**< File where you can you can insert the encrypted word to decrypted */
    fd=fopen("encriptsave.txt","a+");
    int i=0;
    int j=0;
    int p=0;
    int v;
    char option;
    char palavra[255];
    char key[255];
    char palavra2[255];
    printf(" __________________________________________________________\n");
    printf("|Do you want to read from an existing file or new sentence?|\n");
    printf("|s- for existing file  n- new sentence                     |\n");
    printf("|__________________________________________________________|\n");
    scanf("%c",&option);
    if(option=='s')
    {
        fflush(stdin);
        fgets(palavra, 255, fd);
        strupr(palavra);
    }
    if(option=='n')
    {
        fflush(stdin);
        fgets(palavra, 255, fn);
        strupr(palavra);
    }
    printf(" _____________________________________________\n");
    printf("|Encrypted word or sentence read off the file:|\n");
    printf("|_____________________________________________|\n");
    printf(" _____________\n");
    printf("|Insert a key |\n");
    printf("|_____________|\n");
    fflush(stdin);
    gets(key);
    strupr(key);
    printf("\n");
    v=1;
    if (strlen(key)<strlen(palavra))
    {
        v=strlen(palavra)/strlen(key);
    }
    p=0;
    for (i=0; i<=v; i++)
    {
        for (j=0; j<strlen(key); j++)
        {
            palavra2[p]=key[j];
            p++;
        }
    }
    palavra2[p]='\0';
    printf(" ____________________________\n");
    printf("|Word or sentece Decrypted:  |\n");
    printf("|____________________________|\n");
    v=0;
    for (i=0; i<strlen(palavra); i++)
    {
        if(palavra[i]== ' ')
        {
            printf(" ");
            v--;
        }
        else
        {
            for (j=0; j<26; j++)
            {
                if (matrix[j][palavra2[v]-65] == palavra[i])
                {
                    if(i==0)
                    {
                        fprintf(fp," ");
                    }
                    printf("%c", j+65);
                    fprintf(fp,"%c", j+65);
                }
            }
        }
        v++;
    }
    fclose(fp);
    printf("\n\n");
    return work;
}
int main()
{
    int matrix[27][27];
    char l[15]="leave";
    char e[15]="encrypt";
    char d[15]="decrypt";
    char a[15];

    while(strcmp(l,a)!=0)
    {
        printf(" ________________________________________________\n");
        printf("|**Welcome to encrypt transposition method**     |\n");
        printf("|**warning, there is text in the encrypt file !**|\n");
        printf("|**Choose a option to:**                         |\n");
        printf("|**'encrypt' to encrypt**                        |\n");
        printf("|**'decrypt' to decrypt**                        |\n");
        printf("|**'leave' to leave the program**                |\n");
        printf("|________________________________________________|\n");
        fflush(stdin);
        gets(a);
        strlwr(a);
        if(strcmp(e,a)==0)
        {
            matriz(matrix);
            encrip(matrix);
            break;
        }
        if(strcmp(d,a)==0)
        {
            matriz(matrix);
            desencrip(matrix);
            break;
        }
        if(strcmp(l,a)==0)
        {
            break;
        }
    }
    return 1;
}
