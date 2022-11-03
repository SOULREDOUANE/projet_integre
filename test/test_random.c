#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void password_generator(char * );
void main(){
    char password[23];
    password_generator(password);
    for (int  i = 0; i < 4; i++)
    {
        printf("%c",password[i]);
    }
    printf("\n");
    puts(password);
    
}







void password_generator(char* password){

    char code[320];
    // generating a random number
    srand(time(NULL));
    sprintf(code,"%d",rand());;
    // turning the number to 4 figures
    
        while (strlen(code)<4)
        {
            strcat(code,"0");  
        }
        for (int i = 0; i < 4; i++)
        {
            password[i]=code[i];
        }
    
    
    
}
  
