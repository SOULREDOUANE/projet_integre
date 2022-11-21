#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// declaration des fonction
void poser_le_code_ticket(char*,char*,int,int);
int count_taille(char*);
void solde_replace(char* ,int );
void input(int *, int *, char *);
void recuperer_solde(char *, int);
void acheter_ticket(int, int, int, char *, char*);
void password_generator(char *);
void number_generator(char *);
void random_number(char *);

// la fonctio main qui va afficher les resultat final
void main()
{

    int identifiant_commun = 2;
    char user[50];
    char ticket;

    // declaration des entier et leur pointeur pour stocker les donnee qui sera saiser par l'utilisateur.
    int type_repat;
    int nombre_ticket;
    char date[18];
    char code[23];

    // printf("Donnez la date de repat que vous voulez avoiren cette forme: jeur-moi-anne(exemple: 04-06-22): ");
    // gets(date);

    printf("Donnez le repat que vous voulez avoir (entrez 0:pour le petit dejeune,1:pour le dejeuner,2:pour le denner.):");
    scanf("%d", &type_repat);

    printf("Donnez le nombre de ticket que voulez acheter:");
    scanf("%d", &nombre_ticket);

    printf("Donnez votre identifiant:");
    scanf("%d", &identifiant_commun);

    printf("Donnez la date  du ticket que vous voulez acheter.sous la forme(2022-10-23):");
    scanf("%s",date);
    

    // char resultat[23];
    acheter_ticket(type_repat, nombre_ticket, identifiant_commun, code, date) ;


    for (int i = 0; i < 4; i++)
    {
        printf("%c", *(code +i));
    }
}

// void input(int* P_type_repat,int* P_nombre_ticket, char* date){

//     printf("Donnez la date de repat que vous voulez avoiren cette forme: jeur-moi-anne(exemple: 04-06-22): ");
//     gets(date);

//     printf("Donnez le repat que vous voulez avoir (entrez 0:pour le petit dejeune,1:pour le dejeuner,2:pour le denner.):");
//     scanf("%d",P_type_repat);

//     printf("Donnez le nombre de ticket que voulez acheter:");
//     scanf("%d",P_nombre_ticket);

// }

// cette fonction recuper le solde de l'etudaint dans les fichier qui contient les solde
void recuperer_solde(char *solde, int identifiant_commun)
{
    // declaration des pointeur des fichiers
    FILE *file_solde;
    file_solde = fopen("solde.txt", "r");
    for (int i = 0; i <= identifiant_commun+1; i++)
    {
        fgets(solde, 17, file_solde);
    }
    fclose(file_solde);
}

// cette fonction generes des nombre aleatoire de 4 chiffres.
void random_number(char *code)
{

    char number[320];
    // generating a random number
    srand(time(NULL));
    sprintf(number, "%d", rand());
    // turning the number to 4 figures

    while (strlen(number) < 4)
    {
        strcat(number, "0");
    }
    for (int i = 0; i < 4; i++)
    {
        code[i] = number[i];
    }
    code[4]='\0';
}

// cette fonction verifier si le code exit dans le fichier des codes de ticket
int verify(char* code){
    FILE * file_code;
    // char buffer[430];
    // code_seconde[0]='a';
   
    int number_of_lines;
    char buffer[232];

    number_of_lines=count_taille("ticket.txt");
    printf("le nombre des element exist dans le fichier est :%d\n",number_of_lines);
    file_code = fopen("ticket.txt", "r"); 
    for (int i = 0; i < number_of_lines; i++)
    {
        
        // fscanf(file_code,"%s",buffer);
        fgets(buffer,100,file_code);

        if (buffer[0]==code[0] && buffer[1]==code[1]&&buffer[2]==code[2]&&buffer[3]==code[3])
        {
            fclose(file_code);
            return 0;
        }
    }
    return 1;
}

// le generateur de code de ticket
void number_generator(char *code)
{

    int start_test = 0;
    while (start_test == 0)
    {
        random_number(code);
        start_test = verify(code);
    }
}

void acheter_ticket(int type_repat, int nombre_ticket, int identifiant_commun, char *code, char* date)
{
    float solde_entier;
    float prix_total;
    float prix_ticket;
    // char code[25];
    char solde[50];
    if (type_repat == 0)
    {
        prix_ticket = 1;
    }
    if (type_repat==1 || type_repat==2)
    {
        prix_ticket = 1.5;
        printf("le prix est 1.5\n");
    }
    prix_total = nombre_ticket * prix_ticket;
    printf("le prix total est %f\n", prix_total);

    // void recuperer_solde( solde, identifiant_commun);

    recuperer_solde(solde, identifiant_commun);

    solde_entier = atoi(solde);
    
    printf(" le solde est :%f\n" ,solde_entier);

    if (solde_entier < prix_total)
    {
        printf("votre solde n'est pas suffisant pour affectuer cette operation.");
    }
    else
    {
        solde_entier-=prix_total;
        sprintf(solde,"%f",solde_entier);
        strcat(solde,"\n");
        solde_replace(solde,identifiant_commun);
        number_generator(code);
        // return code;
    }
    poser_le_code_ticket(code,date,type_repat,nombre_ticket);


}

// une fonction qui fait changer la valeur du solde dans le fichier apres qu'on fait une operation d'achat
void solde_replace(char* solde,int identifiant_commun){
    FILE *open_main;
    FILE *open_clone;

    open_main=fopen("solde.txt","r");
    open_clone=fopen("solde_temp.txt","w");

    char  buffer[50];
    int  lines_of_file;

    lines_of_file=count_taille("solde.txt");
    printf("les ligne de la fichier sont de nombre :%d\n",lines_of_file);
    // fscanf(open_main,"%d",&lines_of_file);
    // fprintf(open_clone,"%d",lines_of_file);
    fprintf(open_clone,"%s","\n");
        for (int i = 0; i < lines_of_file; i++){
        if (i<identifiant_commun)
        {
        fscanf(open_main,"%s",buffer);
        strcat(buffer,"\n");
        fprintf(open_clone,"%s",buffer);  
        }
        else if(i==identifiant_commun)
        {
            fscanf(open_main,"%s", buffer);
            fprintf(open_clone,"%s",solde);
        }
        else
        {
        fscanf(open_main,"%s", buffer);
        strcat(buffer,"\n");
        fprintf(open_clone,"%s",buffer);
        }
    }

    fclose(open_clone);
    fclose(open_main);

    remove("solde.txt");
    rename("solde_temp.txt","solde.txt");
    
}

// une fonction qui compte le nombres des element dans un fichiers donnee 
int count_taille(char* file_path){
    FILE * open_file;
    open_file=fopen(file_path, "r");
    int c;
    int conteur=0;
    char buffer[242];
    c=fgetc(open_file);
    fgets(buffer,123,open_file);
    while (c !=EOF)
    {
    conteur++;
    c=fgetc(open_file);
    fgets(buffer,143,open_file);
    }
    fclose(open_file);
    return conteur;
}
//  cette derniere fonction permet de poser le code de la ticket dans un fichiers qui contient tous les tickets
void poser_le_code_ticket(char *code, char *date, int type_repat, int nombre_ticket)
{

    FILE *open_ticket;

    char buffer[20];
    char replacer[23];
    replacer[0] = '-';
    strcat(code,"-");
    strcat(code, date);
    printf("%s\n", code);

    sprintf(buffer, "%d", type_repat);
    strcat(replacer, buffer);

    strcat(code, replacer);
    printf("%s\n", code);

    sprintf(buffer, "%d", nombre_ticket);
    replacer[1]='\0';
    strcat(replacer, buffer);
    strcat(replacer, "\n");
    strcat(code, replacer);
    printf("%s\n", code);

    open_ticket = fopen("ticket.txt", "a");
    // fprintf(open_ticket,"%s",code);
    fputs(code, open_ticket);

    fclose(open_ticket);
}