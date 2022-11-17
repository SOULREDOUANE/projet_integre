#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
int verify(char * );
void number_generator(char * );
void random_number(char*);
void main(){
    
    char code[23];
    // random_number(code);
   
    number_generator( code);
    
    
for (int  i = 0; i < 4; i++)
{
   printf("%c",*(code+i));
}
    
    
 

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
    sprintf(number,"%d",rand());
    // turning the number to 4 figures
    
        while (strlen(number)<4)
        {
            strcat(number,"0");  
        }
        for (int i = 0; i < 4; i++)
        {
            code[i]=number[i];
            // printf("%c",code[i]);
        }
        
}


int verify(char * code){
    FILE * file_code;
    char code_seconde[12];
    file_code=fopen("code_tiket.txt","r");
    int c=getc(file_code);
    int value_test;
    while (c !=EOF)
    {
        fgets(code_seconde,6,file_code);
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
