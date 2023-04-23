#include <stdio.h>


size_t estados[][6] = {
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

int automata(void);
size_t posicionAlfabeto(char);
int esFinal(size_t estado);

int main(int argc, char **args) {
    char c;
    int tipo;
    while((c = getc(stdin)) != EOF){
        ungetc(c,stdin);
        tipo = automata();
        }
        if(tipo == 1){
            printf ("Es octal\n");
        }
        if(tipo == 2){
            printf ("Es Decimal\n");
        }
        if(tipo == 3){
            printf ("Es Hexadecimal\n");
        }
        else{
            printf("No Valido\n");}
    return 0;
    }

    /*FILE *archivo;
    char caracter;

    archivo = fopen("archivo.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {
        printf("%c", caracter);
    }

    fclose(archivo);

    return 0;*/
 

int automata(void){
    size_t estado = 0;
    char c;
    while((c = getc(stdin)) != '\n'){ 
        estado = estados[estado][posicionAlfabeto(c)];
    }
    return esFinal(estado);
}

size_t posicionAlfabeto(char c){
    size_t i ;
    switch (c) {

    case '0':
         i = 0;
         return i;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
        i = 1;
        return i;
    case '8':
    case '9':
        i = 2;
        return i;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        i = 3;
        return i;
    case 'x':
    case 'X':
         i = 4;
         return i;
    default:
         i = 5;
         return i;
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


