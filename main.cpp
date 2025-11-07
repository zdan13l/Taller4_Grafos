#include "Grafo.h"
#include "Bodega.h"

int main() {
    cout << endl;
    cout << "     ˙✦˙✦˙✦˙✦˙✦   TALLER 4  ✦˙✦˙✦˙✦˙✦˙" << endl;
    cout << "         Joselito recolector de basura" << endl;
    cout << "     ˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙✦˙" << endl;

    Bodega bodega;
    string nombreArchivo;

    cout << endl << "~~~~~~ Sistema de recolección con Grafos ~~~~~~" << endl;
    cout << " - Ingrese el nombre del archivo a cargar: ";
    cin >> nombreArchivo;

    if (!bodega.cargarArchivo(nombreArchivo)) {
        cout << " - Error... No se pudo cargar el archivo." << endl;
        cout << " - Verifique el nombre o formato." << endl;
    }

    return 0;
}
