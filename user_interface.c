#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
// declaration des fonction 
void input(int*,int*,char*);
void recuperer_solde(char* ,int);
void acheter_ticket(int type_repat,int nombre_ticket,char* solde,int identifiant_commun);
void password_generator(char * );
void number_generator(char * );
void random_number(char * );


// la fonctio main qui va afficher les resultat final
void main(){

    int identifiant_commun=1;
    // declactation des tableau distine pour contenir les donnee des fichiers
    char user[50];
    char ticket;
    char solde;
    // declaration des entier et leur pointeur pour stocker les donnee qui sera saiser par l'utilisateur.
    int type_repat;
    int nombre_ticket;
    char date[9];

    
    acheter_ticket(  type_repat,  nombre_ticket, solde, identifiant_commun);
 
}


void input(int* P_type_repat,int* P_nombre_ticket, char* date){

    printf("Donnez la date de repat que vous voulez avoiren cette forme: jeur-moi-anne(exemple: 04-06-22): ");
    gets(date);

    printf("Donnez le repat que vous voulez avoir (entrez 0:pour le petit dejeune,1:pour le dejeuner,2:pour le denner.):");
    scanf("%d",P_type_repat);

    printf("Donnez le nombre de ticket que voulez acheter:");
    scanf("%d",P_nombre_ticket);
    
}

// cette fonction recuper le solde de l'etudaint dans les fichier qui contient les solde
void recuperer_solde(char* solde,int identifiant_commun){
    // declaration des pointeur des fichiers
    FILE *file_solde;
    file_solde=fopen("solde.txt","r");
    for (int i = 0; i <= identifiant_commun; i++)
    {
        fgets(solde,17,file_solde);
        
    }
    fclose(file_solde);
    }


// cette fonction generes des nombre aleatoire de 4 chiffres.
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



// cette fonction verifier si le code exit dans le fichier des codes de ticket
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


// le generateur de code de ticket
void number_generator(char * code){

                int start_test=0;
                while (start_test==0)
                {
                random_number(code);
                start_test=verify( code) ;
                }
}



void acheter_ticket( int type_repat, int nombre_ticket,char* solde,int identifiant_commun){
        int solde_entier;
        int prix_total;
        int prix_ticket;
        char code[25];
        if (type_repat==0)
        {
            prix_ticket=1;
        }
        else
        {
            prix_ticket=1.5;
        }
        prix_total=nombre_ticket*prix_ticket;

        void recuperer_solde( solde, identifiant_commun);

        solde_entier=atoi(solde);
        
        if (solde_entier<prix_total)
        {
            printf("votre solde n'est pas suffisant pour affectuer cette operation.");
        }
        else
        {
            void number_generator(char * code);
            puts(code);
        }
        
        
        
}