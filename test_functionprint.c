#include<stdio.h>
void input(int* ,int* , char* );

void main(){



    int type_repat,*P_type_repat;
    P_type_repat=&type_repat;
    int nombre_ticket,*P_nombre_ticket;
    P_nombre_ticket=&nombre_ticket;
    char date[9];
    
   input(P_type_repat, P_nombre_ticket, date);
   
   printf("le repat est %d:\n",type_repat);
   printf("le nombre de ticket est %d:\n",nombre_ticket);
   puts(date);


}













void input(int* P_type_repat,int* P_nombre_ticket, char* date){

    printf("Donnez la date de repat que vous voulez avoiren cette forme: jeur-moi-anne(exemple: 04-06-22): ");
    gets(date);

    printf("Donnez le repat que vous voulez avoir (entrez 0:pour le petit dejeune,1:pour le dejeuner,2:pour le denner.):");
    scanf("%d",P_type_repat);
    
    printf("Donnez le nombre de ticket que voulez acheter:");
    scanf("%d",P_nombre_ticket);
    
}

