#include "Bodega.h"

#include <iostream>

using namespace std;

int main() {
    char opcion;

    do {
        cout << endl;
        cout << "     ˙✦˙✦˙✦˙✦˙✦˙✦  TALLER 4  ✦˙✦˙✦˙✦˙✦˙" << endl;
        cout << "        Joselito recolector de basura" << endl;
        cout << "     ˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙" << endl;

        string nombreArchivo;
        cout << "\n~~~~~~ Sistema de recolección con Grafos ~~~~~~" << endl;
        cout << " - Ingrese el nombre del archivo a cargar: ";
        cin >> nombreArchivo;

        Bodega bodega;
        bodega.cargarArchivo(nombreArchivo);

        do {
            cout << "\n - ¿Desea procesar otro archivo? (S/N): ";
            cin >> opcion;

            if (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n') {
                cout << "   [ERROR]: Opción no válida. Ingrese S o N." << endl;
            }

        } while (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n');

    } while (opcion == 'S' || opcion == 's');

    cout << "\nPrograma finalizado." << endl;
    return 0;
}
