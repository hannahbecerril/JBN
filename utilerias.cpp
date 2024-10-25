#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
class Utilerias {
public:
// Función error
void error(char *msg) {
    printf("%s\n", msg);
    printf("Oprima [ENTER] para continuar\n"); 
}

// Función pide_entero
int pide_entero(char *msg, int LI, int LS) {
    char v[100];
    int valor;
    bool ok;

    while (true) {
        printf("%s", msg);
        scanf("%s", v);

        ok = true;
        for (int i = 0; v[i] != '\0'; i++) {
            if (!isdigit(v[i])) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            error("Error, valor no válido");
        } else {
            valor = atoi(v);
            if (valor < LI || valor > LS) {
                error("Error, valor fuera de rango");
            } else {
                return valor;
            }
        }
    }
}


char* pide_cadena(char *msg, int LI, int LS) {
     char cad[100]; 
    char let[100];
    while (1) {
        printf("%s", msg);
        scanf("%s", cad);
        if (strlen(cad) < LI || strlen(cad) > LS) {
            sprintf(let, "Error, la cadena debe tener entre %d y %d caracteres", LI, LS);
            error(let);
        } else {
            return cad;
        }
    }
}
};
