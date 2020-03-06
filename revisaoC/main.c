#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    char nameFloder[100];
    FILE *file;
    char texto[1000];
    if(argc<=1){
        printf("Entre com o nome do arquivo: ");
        scanf("%s", nameFloder);
        file = fopen(nameFloder,"r");
    }
    else{
        file = fopen(argv[1], "r");
    }

    if(file == NULL){
        printf("\n Nao foi possivel abrir o arquivo");
        return 0;
    }
   
    while(!feof(file)){
        fscanf(file, "%[^\n]", texto);
        fscanf(file, "%*c");
        printf("%s\n", texto);
    }

   return 0;
}