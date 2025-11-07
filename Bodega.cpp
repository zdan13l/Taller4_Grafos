#include "Bodega.h"

// Constructor.
Bodega::Bodega() {
    grafo = nullptr;
    capacidad = 0;
    cantidadProductos = 0;
    nEscenarios = 0;
}

// Destructor.
Bodega::~Bodega() {
    delete grafo;
}

// Lee el archivo de entrada.
bool Bodega::cargarArchivo(const string& nombreArchivo) {
    // Abrir archivo
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << " Error... No se pudo abrir el archivo." << endl;
        return false;
    }

    // Leer parámetros iniciales.
    archivo >> nEscenarios;          // n: Cantidad de escenarios.

    for (int i = 0; i < nEscenarios; i++) {
        archivo >> capacidad;           // k: Capacidad máxima.
        archivo >> cantidadProductos;   // m: Número de productos.

        // Validar parámetros
        if (capacidad <= 0 || cantidadProductos <= 0) {
            cout << " Error... Parámetros inválidos en el archivo." << endl;
            archivo.close();
            return false;
        }

        // Mensajes de confirmación.
        mostrarResumen(i + 1);

        // Crear grafo para este escenario.
        if (grafo) {
            delete grafo;
            grafo = nullptr;
        }

        // Crea el grafo (productos + base).
        int totalVertices = cantidadProductos + 1; // +1 de la base (robot)
        grafo = new Grafo(totalVertices, false);

        // Agrega coordenada base (0,0).
        grafo->agregarVertice(0, 0);

        // Leer coordenadas de productos.
        double x, y;
        for (int j = 0; j < cantidadProductos; j++) {
            if (!(archivo >> x >> y)) {
                cout << " Error... Al leer coordenadas del archivo." << endl;
                archivo.close();
                return false;
            }
            grafo->agregarVertice(x, y);
        }
        archivo.close();

        // Calcular matriz de distancias.
        grafo->calcularMatrizDistancias();

        // Mostrar las coordenadas cargadas correctamente.
        cout << endl << "Coordenadas cargadas (incluyendo base):" << endl;
        for (int j = 0; j < cantidadProductos + 1; j++) {
            cout << "Vértice " << j << ": (" << grafo->coordenadas[j].first << ", " << grafo->coordenadas[j].second << ")" << endl;
        }

        return true;
    }
}

// Muestra un resumen del escenario cargado.
void Bodega::mostrarResumen(int escenario) {
    cout << endl;
    if (!grafo) {
        cout << " No hay un grafo cargado." << endl;
        return;
    }

    cout << endl << "Archivo cargado correctamente." << endl;
    cout << endl << "Escenario " << escenario << "/" << nEscenarios << " cargado correctamente." << endl;
    cout << "Capacidad(k): " << capacidad << endl;
    cout << "Productos(m): " << cantidadProductos << endl;
}
