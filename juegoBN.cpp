#include <stdio.h>
#include "utilerias.cpp"
#include <ios>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;

class JuegoBN {
    public:
        char matriz[8][8]; 
        char file[100];      
        int aciertos=0;
        int errores=0;
        char nombre_file[30];
    
    public:
        JuegoBN() {
            printf("============================================================\n");
            printf("INDICA EL NOMBRE DEL ARCHIVO\n");
            printf("============================================================\n");
            printf("SI DESEAS UNN JUEGO NUEVO PON UN ENTER\n"); 
            printf("============================================================\n");
            printf("ESCRIBE EL NOMBRE DEL ARCHIVO SIN EXTENSION\n");
            printf("=============================================================\n");

            gets(file);
            if (strlen(file) == 0) {
                strcpy(file, "archivobatalla1.csv");
            } else {
                strcat(file, ".csv");
            }

            carga_matriz();
        }
    
    void carga_matriz() {
        bool boton = false;
        while (!boton) { 
            ifstream arch;
            arch.open(file, ios::in);
            if (arch.is_open()) {
                int ren = 0, col = 0;
                char cad[100];
                while (!arch.eof()) {
                    arch >> cad;
                    if (!arch.eof()) {
                        for (int i = 0; i < strlen(cad); i += 2) {
                            matriz[ren][col] = cad[i];
                            col++;
                        }
                        col = 0;
                        ren++;
                    }
                }
                arch.close();
                cargar_score();
                boton = true;
            } else {
                printf("ARCHIVO INEXISTENTE.\n");
                printf("Ingresa el nombre del archivo: ");
                scanf("%s", file);
                if (strlen(file) == 0) {
                    strcpy(file, "archivobatalla1.csv");
                } else {
                    strcat(file, ".csv");
                }
            }
        }
    }

    
    void cargar_score() { 
    aciertos = 0; 
    errores = 0;
        for (int ren = 0; ren < 8; ren++) {
            for (int col = 0; col < 8; col++) {
                if (matriz[ren][col] == 'X') {
                    errores++;
                }
                if (matriz[ren][col] == 'A') {
                    aciertos++;
                }
            }
        }

        printf("Errores: %d\n", errores);
        printf("Aciertos: %d\n", aciertos);
    }

    void muestra_tablero() {
        printf("   0 1 2 3 4 5 6 7\n");
        printf("  %s\n", "-----------------");

        for (int ren = 0; ren < 8; ren++) {
            printf("%d |", ren);
            for (int col = 0; col < 8; col++) {
                if (matriz[ren][col] == 'V' || matriz[ren][col] == 'B') {
                    printf(" |");
                } else {
                    printf("%c|", matriz[ren][col]);
                }
            }
            if (ren == 0) {
                printf("     Aciertos= %d / 9", aciertos);
            }
            if (ren == 1) {
                printf("     Errores = %d / 10", errores);
            }
            printf("\n  %s\n", "-----------------");
        }
    }

void descarga_matriz() {
    Utilerias obj_ut;
    char nombre_file[100];
    strcpy(nombre_file, obj_ut.pide_cadena("Indica el nombre a guardar del archivo: ", 1, 10));
    strcat(nombre_file, ".csv");
    ofstream arch;
    arch.open(nombre_file, ios::app);
    if (!arch.is_open()) {
        printf("Error al abrir el archivo.\n");
        return;
    } else {
        for (int ren = 0; ren < 8; ren++) {
            for (int col = 0; col < 8; col++) {
                arch << matriz[ren][col];
                if (col < 7) {
                    arch << ",";
                }
            }
            arch << "\n";
        }
        arch.close();
    }

    char respuesta;
    printf("¿Deseas continuar? [S/N] ");
    scanf(" %c", &respuesta);
    if (respuesta == 'N' || respuesta == 'n') {
        printf("Hasta luego\n");
        exit(0);
    } else {
        printf("¡Super!, sigue jugando\n");
    }
}
    void tiro(int ren, int col) { 
        if (ren == 8 || col == 8) {
            descarga_matriz();
        } else {  
            if (matriz[ren][col] == 'X' || matriz[ren][col] == 'A') {
                printf("YA TIRASTE AHÍ\n");
            } else {
                if (matriz[ren][col] == 'V') {
                    printf("AHÍ NO HAY NADA \n");
                    errores++; 
                    matriz[ren][col] = 'X';
                } else {
                    printf("LE ATINASTE,FELICIDADES\n");
                    aciertos++; 
                    matriz[ren][col] = 'A';
                }
            }
        }
    }
};

