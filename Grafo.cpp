#include "Grafo.h"

using namespace std;

// Calcular distancia entre dos vértices.
double Grafo::calcularDistancia(Vertice& a, Vertice& b) {
    int dx = abs(a.getX() - b.getX());
    int dy = abs(a.getY() - b.getY());

    // Mismas fila, columna o diagonal.
    if (dy == 0) {
        return dx;
    } else if (dx == 0) {
        return dy;
    } else {
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }
}

// Constructor del grafo.
Grafo::Grafo() {
    vertices.clear();
    matrizAdyacencia.clear();
}

// Agregar el origen siempre al inicio.
void Grafo::agregarOrigen() {
    // Insertar origen al inicio.
    Vertice origen(0, 0, 0);
    vertices.insert(vertices.begin(), origen);
    int n = vertices.size();

    // Crear nueva matriz de tamaño correcto.
    vector<vector<double>> nuevaMatriz(n, vector<double>(n, 0.0));

    // Calcular distancias entre el origen y los demás.
    for (int i = 1; i < n; i++) {
        double distancia = calcularDistancia(vertices[0], vertices[i]);
        nuevaMatriz[0][i] = distancia;
        nuevaMatriz[i][0] = distancia;
    }

    // Copiar las distancias antiguas (si existían).
    if (!matrizAdyacencia.empty()) {
        int antiguaD = matrizAdyacencia.size();

        for (int i = 1; i <= antiguaD; i++) {
            for (int j = 1; j <= antiguaD; j++) {
                // Evitar acceso fuera de rango si hay desfase.
                if (i - 1 < antiguaD && j - 1 < antiguaD) {
                    nuevaMatriz[i][j] = matrizAdyacencia[i - 1][j - 1];
                }
            }
        }
    }
    matrizAdyacencia = nuevaMatriz;

    // Reasignar IDs.
    for (int i = 0; i < n; i++) {
        vertices[i] = Vertice(i, vertices[i].getX(), vertices[i].getY());
    }
}

// Agregar un vértice al grafo.
void Grafo::agregarVertice(int x, int y) {
    int id = vertices.size();
    Vertice vertice (id, x, y);
    vertices.push_back(vertice  );

    int n = vertices.size();

    // Ajustar tamaño de la matriz de adyacencia.
    vector<vector<double>>::iterator it;
    for (it = matrizAdyacencia.begin(); it != matrizAdyacencia.end(); ++it) {
        it->resize(n, 0.0);
    }

    // Agregar una nueva fila completamente inicializada.
    matrizAdyacencia.push_back(vector<double>(n, 0.0));

    // Calcular distancias con todos los anteriores.
    for (int i = 0; i < n - 1; i++) {
        double distancia = calcularDistancia(vertices[i], vertice);
        matrizAdyacencia[i][id] = distancia;
        matrizAdyacencia[id][i] = distancia;
    }
}

// Imprimir matriz de adyacencia.
void Grafo::imprimirMatriz() {
    cout << endl;
    cout << "============== MATRIZ DE ADYACENCIA ==============" << endl;

    int n = matrizAdyacencia.size();
    if (n == 0) {
        cout << "[INFO] La matriz está vacía." << endl;
        return;
    }

    // Encabezado de columnas.
    cout << setw(6) << " ";
    for (int j = 0; j < n; j++) {
        cout << setw(6) << ("V" + to_string(j));
    }
    cout << endl;

    // Separador visual.
    cout << "     ";
    for (int j = 0; j < n; j++) cout << "------";
    cout << endl;

    // Filas de la matriz.
    for (int i = 0; i < n; i++) {
        cout << setw(4) << ("V" + to_string(i)) << " |";
        for (int j = 0; j < n; j++) {
            double valor = matrizAdyacencia[i][j];
            if (valor == 0) {
                cout << setw(6) << "-";
            } else {
                cout << setw(6) << fixed << setprecision(1) << valor;
            }
        }
        cout << endl;
    }
    cout << "=================================================" << endl;
}

// Obtener matriz de adyacencia.
vector<vector<double>>& Grafo::getMatrizAdyacencia() { return matrizAdyacencia; }

// Obtener vértice por índice.
Vertice& Grafo::getVertice(int indice) { return vertices[indice]; }

// Obtener cantidad de vértices.
int Grafo::getCantidadVertices() { return vertices.size(); }
