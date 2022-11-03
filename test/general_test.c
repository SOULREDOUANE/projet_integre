#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void random_number(char *);
void number_generator(char *);
int verify(char* );
void main(){
    char code [24];
    number_generator(code);
    puts(code);
    // printf("la resultat est: %d\n",);


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
        value_test=0;
        for ( int i = 0; i < 4; i++)
        {
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

void number_generator(char * code){

                int start_test=0;
                while (start_test==0)
                {
                random_number(code);
                start_test=verify( code) ;
                }


}

void random_number(char * code){

    char number[320];
    
    // generating a random number
    srand(time(NULL));
    sprintf(number,"%d",rand());;
    // turning the number to 4 figures
    
        while (strlen(number)<4)
        {
            strcat(number,"0");  
        }
        for (int i = 0; i < 4; i++)
        {
            code[i]=number[i];
        }
}