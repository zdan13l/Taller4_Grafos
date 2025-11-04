#include "Grafo.h"
#include "Sistema.h"

int main() {
    cout << endl;
    cout << "       ˙✦˙✦˙✦˙✦   TALLER 4  ˙✦˙✦˙✦˙✦" << endl;
    cout << "        Joselito recolector de basura" << endl;
    cout << "      ˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦" << endl;

    Sistema sistema;
    string nombreArchivo;

    cout << endl << "~~~~~~ Sistema de recolección con Grafs ~~~~~~   " << endl;
    cout << "Ingrese el nombre del archivo a cargar: ";
    cin >> nombreArchivo;

    if (sistema.cargarArchivo(nombreArchivo)) {
        sistema.mostrarResumen();
    } else {
        cout << "No se pudo cargar el archivo. Verifique el nombre o formato." << endl;
    }

    return 0;
}
