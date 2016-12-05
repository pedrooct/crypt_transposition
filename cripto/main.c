#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


 #define work 1
 #define dwork 0


int matrix[27][27];

/** \brief This will fill the matriz with alll the letters of the alphabet
 *
 * \return int
 *
 */
int matriz()
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
int encrip()
{
    FILE *fe;
    fe=fopen("encript.txt", "a+");
    char palavra[255];
    char key[255];
    char palavra2[255];
    int i=0;
    int j=0;
    int p=0;
    int v=1;

    printf("\nWord or sentece read off the file to encrypt\n");
    fflush(stdin);
    fgets(palavra,255,fe);
    strupr(palavra);
    printf("Insert a key \n");
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
    printf("word encrypted: ");
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
            fprintf(fe,"%c",matrix[palavra[i]-65][palavra2[j]-65]);
            j++;
        }
    }
    printf("\n");
    fclose(fe);
    return work;
}
int desencrip()
{
    FILE *fp;
    fp=fopen("desncript.txt", "a+");/**< File where you can you can insert the encrypted word to decrypted */
    int i=0;
    int j=0;
    int p=0;
    int v;
    char palavra[255];
    char key[255];
    char palavra2[255];
    printf ("\nEncrypted word or sentence read off the file:\n");
    fflush(stdin);
    fgets(palavra, 255, fp);
    strupr(palavra);
    printf ("Insert a key:\n");
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
    printf ("Word or sentece Decrypted: ");
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
    char l;

    while(l!='c')
    {
        printf("**Welcome to encrypt**\n");
        printf("**Choose a option to:**\n");
        printf("**'a' to encrypt**\n");
        printf("**'b' to decrypt**\n");
        printf("**'c' to leave the program**\n");
        scanf("%c",&l);
        switch(l)
        {
        case('a'):
            matriz();
            encrip();


            break;
        case('b'):
            matriz();
            desencrip();

            break;
        }
    }
    return 1;
}
