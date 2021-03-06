#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "pila.h"

#define MAX 0x100

double (*operacion [])(double, double) = { sum, res, mul, dvd, quit };
const char *comando[] = {
    "suma",
    "resta",
    "multiplica",
    "divide",
    "salir"
};
int comandos = sizeof(comando)/sizeof(char *);

int find(const char *entrada){
    for (int i=0; i<comandos; i++)
        if (strcmp(entrada, comando[i]) == 0)
            return i;
}

int main(int argc, const char **argv){

    char buffer[MAX];
    struct Stack operando;

    do {

        system("clear");
        for (int i=0; i<operando.cima; i++)
            printf("%.2lf\n", operando.data[i]);

        printf("Comando: ");
        scanf(" %s", buffer);

        if (isdigit(buffer[0]))
            push(atof(buffer), &operando);
        else
            push(
                    operacion[find(buffer)](pop(&operando), pop(&operando)),
                    &operando
                );

    } while (strcasecmp(buffer, comando[comandos-1]));

    return EXIT_FAILURE;
}
