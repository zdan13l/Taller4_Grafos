#include <iostream>
#include "Sistema.h"

using namespace std;

int main() {
    char opcion;

    do {
        // Encabezado bonito
        cout << endl;
        cout << "       ˙✦˙✦˙✦˙✦   TALLER 4  ˙✦˙✦˙✦˙✦" << endl;
        cout << "        Joselito recolector de basura" << endl;
        cout << "      ˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦" << endl << endl;

        string nombreArchivo;
        cout << "Ingrese el nombre del archivo de entrada: ";
        cin >> nombreArchivo;

        // Crear Sistema y ejecutar
        Sistema sistema;
        sistema.cargarArchivo(nombreArchivo); // Este método leerá, procesará y guardará

        cout << "¿Desea procesar otro archivo? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
