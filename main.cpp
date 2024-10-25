#include <stdio.h>
#include "juegoBN.cpp"
#include "utilerias.cpp"
#include <conio.h>

main() {
    Utilerias obj_ut;
    juegoBN obj_jbn;
    obj_jbn.carga_matriz_file();

    while (obj_jbn.aciertos < 9 && obj_jbn.fallos < 10) {
        obj_jbn.muestra_matriz();
        int ren = obj_ut.pide_entero("Indica el renglon de tiro  :", 0, 8);
        int col = obj_ut.pide_entero("Indica la columna de tiro  :", 0, 8);
        obj_jbn.tiro(ren, col);
    }

    if (obj_jbn.aciertos == 9) {
        obj_ut.error("Ganaste");
    } else {
        obj_ut.error("Perdiste");
    }

}

