#include<stdio.h>
#include<string.h>
void recuperer_solde(char* ,int );
void main(){
    int identifiant_commun=2;
    char solde[242];
    
    recuperer_solde(solde,identifiant_commun);
    puts(solde);
}
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