#include<stdio.h>
int count_taille(char*);
int verify(char*);

void main(){
int valeur;
valeur= verify("0000");
printf("la valeur de verify est : %d",valeur);
}

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