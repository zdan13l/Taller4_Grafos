#include "Bodega.h"

#include <iostream>

using namespace std;

int main() {
    char opcion;

    do {
        cout << endl;
        cout << "     ˙✦˙✦˙✦˙✦˙✦   TALLER 4  ✦˙✦˙✦˙✦˙✦˙" << endl;
        cout << "       Joselito recolector de basura" << endl;
        cout << "     ˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙" << endl;

        string nombreArchivo;
        cout << endl;
        cout << "~~~~~~ Sistema de recolección con Grafos ~~~~~~" << endl;
        cout << " - Ingrese el nombre del archivo a cargar: ";
        cin >> nombreArchivo;

        Bodega bodega;
        bodega.cargarArchivo(nombreArchivo);

        cout << endl;
        cout << " - ¿Desea procesar otro archivo? (S/N): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
