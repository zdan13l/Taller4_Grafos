#include "Sistema.h"

Sistema::Sistema() {
    grafo = nullptr;
    capacidad = 0;
    cantidadProductos = 0;
    escenarios = 0;
}

Sistema::~Sistema() {
    delete grafo;
}

// Lee el archivo de entrada
bool Sistema::cargarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << " Error: No se pudo abrir el archivo." << endl;
        return false;
    }

    archivo >> escenarios;          // n: cantidad de escenarios
    archivo >> capacidad;           // k: capacidad máxima
    archivo >> cantidadProductos;   // m: número de productos

    cout << "\nArchivo cargado correctamente." << endl;
    cout << "Escenarios(n): " << escenarios << endl;
    cout << "Capacidad(k): " << capacidad << endl;
    cout << "Productos(m): " << cantidadProductos << endl;

    // Crea el grafo (productos + base)
    int totalVertices = cantidadProductos + 1; // +1 de la base (robot)
    grafo = new Grafo(totalVertices, false);

    // Agrega coordenada base (0,0)
    grafo->agregarArista(0, 0);

    // Leer coordenadas de productos
    double x, y;
    for (int i = 0; i < cantidadProductos; i++) {
        if (!(archivo >> x >> y)) {
            cout << " Error al leer coordenadas del archivo." << endl;
            return false;
        }
        grafo->agregarArista(x, y);
    }

    archivo.close();

    // Calcular matriz de distancias
    grafo->calcularMatrizDistancias();

    // Mostrar las coordenadas cargadas correctamente
    cout << "\nCoordenadas cargadas (incluyendo base):" << endl;
    for (int i = 0; i < cantidadProductos + 1; i++) {
        cout << "Vértice " << i << ": (" 
        << grafo->coordenadas[i].first << ", " 
        << grafo->coordenadas[i].second << ")" << endl;
    }

    return true;
}

void Sistema::mostrarResumen() const {
    if (!grafo) {
        cout << " No hay un grafo cargado." << endl;
        return;
    }

    cout << "\n    ~~~~ Datos obtenidos ~~~~   " << endl;
    cout << "Capacidad del robot (k): " << capacidad << endl;
    cout << "Número de productos (m): " << cantidadProductos << endl;
    grafo->mostrarMatriz();
}
