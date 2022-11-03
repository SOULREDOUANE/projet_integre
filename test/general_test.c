#include<stdio.h>
#include<string.h>

int verify(char* );
void main(){
    char code[23];
    for (int i = 0; i < 4; i++)
    {
        code[i]='1';
    }
    
    printf("la resultat est: %d\n",verify(code));


}


int verify(char * code){
    FILE * file_code;
    char code_seconde[12];
    file_code=fopen("file_code.txt","r");
    int c=getc(file_code);
    int value_test;
    while (c !=EOF)
    {
        fgets(code_seconde,5,file_code);
        puts(code_seconde);
        value_test=0;
        for ( int i = 0; i < 4; i++)
        {
            printf("le code init est :%c\n",code[i]);
            printf("le code seconde est :%c\n",code_seconde[i]);

            if (code[i]!=code_seconde[i])
            {
                value_test=1;
            }
        }
        if (value_test==0)
        {
            fclose(file_code);
            return 0;
        }
        c=getc(file_code);
    }
    fclose(file_code);
    return 1;
}