#include "Bodega.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

// Constructor.
Bodega::Bodega() {
    cout << "[DEBUG] Constructor Bodega iniciado." << endl;
    escenarios.clear();
    robots.clear();
    recorridos.clear();
}

// Cargar archivo, procesar y guardar resultados.
void Bodega::cargarArchivo(const string& nombreArchivo) {
    cout << "[DEBUG] Intentando abrir archivo: " << nombreArchivo << endl;
    // Abrir archivo de entrada.
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << " [ERROR] No se pudo abrir el archivo." << endl;
        return;
    }

    // Limpiar datos previos.
    escenarios.clear();
    robots.clear();
    recorridos.clear();

    // Leer número de escenarios.
    int nEscenarios;
    archivo >> nEscenarios;
    cout << "[DEBUG] Número de escenarios: " << nEscenarios << endl;

    // Procesar cada escenario.
    for (int escenario = 0; escenario < nEscenarios; escenario++) {
        int capacidad, productos;
        if (!(archivo >> capacidad >> productos)) {
            cout << " [ERROR] Formato incorrecto en archivo." << endl;
            return;
        }
        cout << "[DEBUG] Escenario " << escenario << ": capacidad=" << capacidad << ", cantidad de vértices=" << productos << endl;

        // Declarar grafo y vértice de origen.
        Grafo grafo;
        grafo.agregarOrigen();
        cout << "[DEBUG] Origen agregado al grafo." << endl;

        // Leer y agregar vértices al grafo.
        for (int i = 0; i < productos; i++) {
            int x, y;
            if (!(archivo >> x >> y)) {
                cout << "[ERROR] Datos incompletos en el archivo." << endl;
                return;
            }
            grafo.agregarVertice(x, y);
            cout << "[DEBUG] Vértice agregado: (" << x << ", " << y << ")" << endl;
        }

        // Almacenar grafo y crear robot.
        escenarios.push_back(grafo);
        robots.emplace_back(capacidad, escenarios.back());
        cout << "[DEBUG] Robot creado con capacidad " << capacidad << endl;
    }
    archivo.close();
    cout << "[DEBUG] Archivo cerrado." << endl;

    // Procesar recorridos para cada robot.
    for (int i = 0; i < escenarios.size(); i++) {
        cout << "[DEBUG] Procesando recorrido para escenario " << i << endl;
        robots[i].recorrer();
        recorridos.push_back(robots[i].getRecorrido());
        cout << "[DEBUG] Recorrido completado. Tamaño: " << recorridos[i].size() << endl;

        // Mostrar tablero con emojis.
        simularMovimiento(i);
    }

    // Imprimir recorridos en consola.
    imprimirRecorridos();

    // Guardar resultados en archivo.
    guardarResultados(nombreArchivo);
}

// Guardar resultados en archivo.
void Bodega::guardarResultados(const string& nombreArchivo) {
    // Guardar resultados en archivo de salida.
    string nombreSalida = "salida_" + nombreArchivo;
    ofstream archivoSalida(nombreSalida);
    if (!archivoSalida.is_open()) {
        cout << "[ERROR] No se pudo crear el archivo de salida." << endl;
        return;
    }

    cout << "[DEBUG] Guardando archivo de salida: " << nombreSalida << endl;
    archivoSalida << "Cantidad de recorridos: " << recorridos.size() << endl;

    // Guardar cada recorrido.
    for (int i = 0; i < recorridos.size(); i++) {
        archivoSalida << "Capacidad del robot: " << robots[i].getCapacidad() << endl;
        archivoSalida << "Cantidad de vértices: " << recorridos[i].size() << endl;

        // Guardar cada vértice del recorrido.
        for (int j = 0; j < recorridos[i].size(); j++) {
            int id = recorridos[i][j];
            Vertice& vertice = escenarios[i].getVertice(id);
            archivoSalida << vertice.getX() << " " << vertice.getY() << endl;
            cout << "[DEBUG] Guardando vértice: (" << vertice.getX() << ", " << vertice.getY() << ")" << endl;
        }
    }
    archivoSalida.close();

    // Confirmar guardado.
    cout << endl;
    cout << " - Archivo de salida guardado como: " << nombreSalida << endl;
}

// Imprime los recorridos en consola.
void Bodega::imprimirRecorridos() {
    cout << "[DEBUG] Imprimiendo recorridos..." << endl;
    for (int i = 0; i < recorridos.size(); i++) {
        cout << "Escenario " << i + 1 << ": ";

        for (int j = 0; j < recorridos[i].size(); j++) {
            cout << recorridos[i][j];
            if (j != recorridos[i].size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

// Mostrar tablero con emojis.
void Bodega::mostrarTablero(int escenarioIndex) {
    cout << "[DEBUG] Mostrando tablero para escenario " << escenarioIndex << endl;
    // Validar índice.
    if (escenarioIndex < 0 || escenarioIndex >= (int) escenarios.size()) {
        cout << "[ERROR] Escenario inválido." << endl;
        return;
    }

    // Obtener grafo y recorrido.
    Grafo& grafo = escenarios[escenarioIndex];
    vector<int>& recorrido = robots[escenarioIndex].getRecorrido();

    // Emojis.
    string robotEmoji = "\xF0\x9F\xA4\x96"; // 🤖
    string cajaEmoji  = "\xF0\x9F\x93\xA6"; // 📦

    // Parámetros del tablero.
    int escala = 2;
    int tamTablero = 100 / escala + 1;
    vector<vector<string>> tablero(tamTablero, vector<string>(tamTablero, "·"));

    // Colocar cajas.
    for (int i = 1; i < grafo.getCantidadVertices(); i++) {
        int ejeX = grafo.getVertice(i).getX() / escala;
        int ejeY = grafo.getVertice(i).getY() / escala;
        ejeX = min(ejeX, tamTablero - 1);
        ejeY = min(ejeY, tamTablero - 1);
        tablero[ejeY][ejeX] = cajaEmoji;
        cout << "[DEBUG] Caja colocada en: (" << ejeX << ", " << ejeY << ")" << endl;
    }

    // Colocar robot.
    int idRobot = recorrido.back();
    int x = grafo.getVertice(idRobot).getX() / escala;
    int y = grafo.getVertice(idRobot).getY() / escala;
    x = min(x, tamTablero - 1);
    y = min(y, tamTablero - 1);
    tablero[y][x] = robotEmoji;
    cout << "[DEBUG] Robot colocado en: (" << x << ", " << y << ")" << endl;

    // Imprimir tablero.
    cout << "[DEBUG] Tablero generado:" << endl;
    for (int y = tamTablero - 1; y >= 0; y--) {
        for (int x = 0; x < tamTablero; x++) {
            cout << tablero[y][x] << " ";
        }
        cout << endl;
    }
}

// Simular movimiento del robot en el tablero.
void Bodega::simularMovimiento(int escenarioIndex) {
    if (escenarioIndex < 0 || escenarioIndex >= (int)escenarios.size()) {
        cout << "[ERROR] Escenario inválido." << endl;
        return;
    }

    Grafo& grafo = escenarios[escenarioIndex];
    vector<int>& recorrido = robots[escenarioIndex].getRecorrido();

    // Emojis
    string robotEmoji = "\xF0\x9F\xA4\x96"; // 🤖
    string cajaEmoji  = "\xF0\x9F\x93\xA6"; // 📦
    string recogidaEmoji = "❌";            // Caja ya recogida

    // Calcular los límites máximos para escalar el tablero
    int maxX = 0, maxY = 0;
    for (int i = 0; i < grafo.getCantidadVertices(); i++) {
        maxX = max(maxX, (int)grafo.getVertice(i).getX());
        maxY = max(maxY, (int)grafo.getVertice(i).getY());
    }

    // Ajuste dinámico de escala
    int escala = max(1, max(maxX, maxY) / 20); // tablero ~20x20
    int tamTablero = max(maxX, maxY) / escala + 2;

    // Mantener registro de las cajas recogidas
    vector<vector<string>> tablero(tamTablero, vector<string>(tamTablero, "·"));

    // Colocar inicialmente todas las cajas
    for (int i = 1; i < grafo.getCantidadVertices(); i++) {
        int ejeX = grafo.getVertice(i).getX() / escala;
        int ejeY = grafo.getVertice(i).getY() / escala;
        ejeX = min(ejeX, tamTablero - 1);
        ejeY = min(ejeY, tamTablero - 1);
        tablero[ejeY][ejeX] = cajaEmoji;
    }

    // Simulación paso a paso (sin limpiar la pantalla)
    for (int paso = 0; paso < recorrido.size(); paso++) {
        int idRobot = recorrido[paso];
        int x = grafo.getVertice(idRobot).getX() / escala;
        int y = grafo.getVertice(idRobot).getY() / escala;
        x = min(x, tamTablero - 1);
        y = min(y, tamTablero - 1);

        // Si no es el origen (id=0) y hay una caja, marcarla como recogida
        if (idRobot != 0 && tablero[y][x] == cajaEmoji) {
            tablero[y][x] = recogidaEmoji;
        }

        // Mostrar el tablero actual
        cout << "=== ESCENARIO " << escenarioIndex + 1 << " | PASO " << paso + 1 << "/" << recorrido.size() << " ===" << endl;

        for (int fila = tamTablero - 1; fila >= 0; fila--) {
            for (int col = 0; col < tamTablero; col++) {
                // Dibujar el robot si está en esta celda
                if (fila == y && col == x)
                    cout << robotEmoji << " ";
                else
                    cout << tablero[fila][col] << " ";
            }
            cout << endl;
        }

        // Pausa entre pasos (más visible para observar cambios)
        this_thread::sleep_for(chrono::milliseconds(800));

        cout << endl;
    }

    cout << "[DEBUG] Simulación completada para escenario " << escenarioIndex << endl;
}
