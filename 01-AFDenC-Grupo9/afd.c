#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t tablaDeEstados[][6] = {
    {1,2,2,6,6,6},
    {5,5,6,6,3,6},
    {2,2,2,6,6,6},
    {4,4,4,4,6,6},
    {4,4,4,4,6,6},
    {5,5,6,6,6,6},
    {6,6,6,6,6,6}
};

size_t finales [] = {1,2,4,5};  
size_t  cant_finales = 4 ;

size_t simbolos[] = {0,1,2,3,4,5,6,7,8,9,'a','b','c','d','e','f','A','B','C','D','E','F','x','X'};
size_t cant_simbolos = 24;


int automata(char c[],int);
size_t posicionAlfabeto(char);
int esFinal(size_t estado);
int tipoDeNumero(size_t tipo); 
void guardar(char c[],int,int);

int main(int argc, char **args) {

    FILE *entrada = fopen("entrada.txt", "r"); 
    FILE *salida = fopen("salida.txt","wt");

    if (entrada == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    char c;
    int tipo, i = 0;
    char palabra [100];

    while (c = fgetc(entrada)){
        if (c == EOF){tipo = automata(palabra,i);
            int j ;
            char k ;
            for(j = 0; j < i ; j ++){
            k = palabra[j];
            fputc(k,salida);
            }
        switch (tipo)
        {
        case 1:
                fputs ("  Es octal\n",salida);
            break;
        case 2:
                fputs ("  Es Decimal\n", salida);
            break;
        case 3:
                fputs ("  Es Hexadecimal\n",salida);
            break;
        default:
                fputs("  No es valido\n",salida);
            break;
        }break;};

        if (c != ','){
            palabra[i] = c;
            i++;
        }
        else {  
            tipo = automata(palabra,i);
            int j ;
            char k ;
            for(j = 0; j < i ; j ++){
            k = palabra[j];
            fputc(k,salida);
            }
        switch (tipo)
        {
        case 1:
                fputs ("  Es octal\n",salida);
            break;
        case 2:
                fputs ("  Es Decimal\n", salida);
            break;
        case 3:
                fputs ("  Es Hexadecimal\n",salida);
            break;
        default:
                fputs("  No es valido\n",salida);
            break;
        }
                i = 0;
        }
    }
    fclose(salida);
    fclose(entrada);
    return 0;
    }


 

int automata(char palabra[], int i){
    int j , estado ;
    char c ;
    estado = 0;

    for(j = 0; j < i ; j ++){
        c = palabra[j];
        estado = tablaDeEstados[estado][posicionAlfabeto(c)];
    } 

    return esFinal(estado);
}

size_t posicionAlfabeto(char c){
    switch (c) {
    case '0':
         return 0;
    case '1' ... '7':
        return 1;
    case '8' ... '9':
        return 2;
    case 'a' ... 'f':
    case 'A' ... 'F':
        return 3;
    case 'x':
    case 'X':
         return 4;
    default:
         return 5;
    }
}


int esFinal(size_t estado){

   switch (estado){
   case 1:
   case 5:
        return 1;
    case 2:
        return 2;
    case 4:
        return 3;
   default:
        return 0;
   }
}


