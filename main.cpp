#include "Bodega.h"

#include <iostream>

using namespace std;

// Programa principal.
int main() {
    char opcion;

    do {
        cout << endl;
        cout << "     ˙✦˙✦˙✦˙✦˙✦˙✦  TALLER 4  ✦˙✦˙✦˙✦˙✦˙" << endl;
        cout << "        Joselito recolector de basura" << endl;
        cout << "     ˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙" << endl;

        string nombreArchivo;
        cout << endl;
        cout << "~~~~~~ Sistema de recolección con Grafos ~~~~~~" << endl;
        cout << " - Ingrese el nombre del archivo a cargar: ";
        cin >> nombreArchivo;

        Bodega bodega;
        bodega.cargarArchivo(nombreArchivo);

        do {
            cout << endl;
            cout << " - ¿Desea procesar otro archivo? (S/N): ";
            cin >> opcion;

            if (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n') {
                cout << "[ERROR] Opción inválida, ingrese S o N." << endl;
            }
        } while (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n');
    } while (opcion == 'S' || opcion == 's');

    cout << endl;
    cout << " - Sistema de recolección finalizado." << endl;
    return 0;
}
