#include "Bodega.h"

#include <fstream>
#include <iostream>
#include <iomanip>

// Constructor.
Bodega::Bodega() {
    escenarios.clear();
    robots.clear();
    recorridos.clear();
}

// Cargar archivo, procesar y guardar resultados.
void Bodega::cargarArchivo(const string& nombreArchivo) {
    // Abrir archivo de entrada.
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << " Error... No se pudo abrir el archivo." << endl;
        return;
    }

    // Limpiar datos previos.
    escenarios.clear();
    robots.clear();
    recorridos.clear();

    // n: Cantidad de escenarios.
    int nEscenarios;
    archivo >> nEscenarios;

    // Leer parámetros iniciales.
    for (int e = 0; e < nEscenarios; ++e) {
        int capacidad, m;
        if (!(archivo >> capacidad >> m)) {
            cout << "Error: formato incorrecto en archivo." << endl;
            return;
        }

        Grafo grafo;
        grafo.agregarOrigen(); // origen siempre al inicio

        for (int i = 0; i < m; ++i) {
            int x, y;
            if (!(archivo >> x >> y)) {
                cout << "Error: datos incompletos en el archivo." << endl;
                return;
            }
            grafo.agregarVertice(x, y);
        }

        escenarios.push_back(grafo);
        robots.emplace_back(capacidad, escenarios.back()); // referencia al grafo
    }

    archivo.close();

    // Procesar recorridos
    for (size_t i = 0; i < escenarios.size(); ++i) {
        robots[i].recorrer();
        recorridos.push_back(robots[i].getRecorrido());
    }

    // Imprimir en consola
    imprimirRecorridos();

    // Guardar archivo de salida
    string nombreSalida = "salida_" + nombreArchivo;
    ofstream archivoSalida(nombreSalida.c_str());
    if (!archivoSalida.is_open()) {
        cout << "Error al crear el archivo de salida." << endl;
        return;
    }

    archivoSalida << recorridos.size() << endl;

    for (size_t i = 0; i < recorridos.size(); ++i) {
        archivoSalida << robots[i].getCapacidad() << endl;
        archivoSalida << recorridos[i].size() << endl;
        for (size_t j = 0; j < recorridos[i].size(); ++j) {
            int id = recorridos[i][j];
            const Vertice& v = escenarios[i].getVertice(id);
            archivoSalida << v.getX() << " " << v.getY() << endl;
        }
    }

    archivoSalida.close();
    cout << "Archivo de salida guardado como: " << nombreSalida << endl;
}

// Imprime los recorridos en consola.
void Bodega::imprimirRecorridos() {
    for (size_t i = 0; i < recorridos.size(); i++) {
        cout << "Escenario " << i + 1 << ": ";
        for (size_t j = 0; j < recorridos[i].size(); j++) {
            cout << recorridos[i][j];
            if (j != recorridos[i].size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

// Mostrar tablero con emojis
void Bodega::mostrarTablero(int escenarioIndex) const {
    if (escenarioIndex < 0 || escenarioIndex >= (int)escenarios.size()) {
        cout << "Escenario inválido." << endl;
        return;
    }

    const Grafo& grafo = escenarios[escenarioIndex];
    const vector<int>& recorrido = robots[escenarioIndex].getRecorrido();

    // Definir emojis como strings
    const string ROBOT = "\xF0\x9F\xA4\x96"; // 🤖
    const string CAJA  = "\xF0\x9F\x93\xA6"; // 📦
    

    // Escala para mostrar en consola
    const int ESCALA = 2;
    const int TAM_TABLERO = 100 / ESCALA + 1;

    // Crear tablero vacío
    vector<vector<string>> tablero(TAM_TABLERO, vector<string>(TAM_TABLERO, "·"));

    // Colocar productos en el tablero
    for (int i = 1; i < grafo.getCantidadVertices(); ++i) { // omitir origen
        int x = grafo.getVertice(i).getX() / ESCALA;
        int y = grafo.getVertice(i).getY() / ESCALA;
        if (x >= TAM_TABLERO) x = TAM_TABLERO - 1;
        if (y >= TAM_TABLERO) y = TAM_TABLERO - 1;
        tablero[y][x] = CAJA;
    }

    // Colocar robot en la posición final del recorrido
    int idRobot = recorrido.back();
    int rx = grafo.getVertice(idRobot).getX() / ESCALA;
    int ry = grafo.getVertice(idRobot).getY() / ESCALA;
    if (rx >= TAM_TABLERO) rx = TAM_TABLERO - 1;
    if (ry >= TAM_TABLERO) ry = TAM_TABLERO - 1;
    tablero[ry][rx] = ROBOT;

    // Imprimir tablero invertido para que y=0 quede abajo
    for (int y = TAM_TABLERO - 1; y >= 0; --y) {
        for (int x = 0; x < TAM_TABLERO; ++x) {
            cout << tablero[y][x] << " ";
        }
        cout << endl;
    }
}
