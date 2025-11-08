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

// Agregar el origen siempre al inicio
void Grafo::agregarOrigen() {
    // Insertar origen al inicio.
    Vertice origen(0, 0, 0);
    vertices.insert(vertices.begin(), origen);
    cout << "[DEBUG] Origen agregado: ID=0, x=0, y=0" << endl;
    int n = vertices.size();

    // Crear nueva matriz de tamaño correcto.
    vector<vector<double>> nuevaMatriz(n, vector<double>(n, 0.0));

    // Calcular distancias entre el origen y los demás.
    for (int i = 1; i < n; i++) {
        double distancia = calcularDistancia(vertices[0], vertices[i]);
        nuevaMatriz[0][i] = distancia;
        nuevaMatriz[i][0] = distancia;
        cout << "[DEBUG] Distancia entre 0 y " << i << " = " << distancia << endl;
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
        cout << "[DEBUG] Vertice reasignado: ID=" << i << ", x=" << vertices[i].getX() << ", y=" << vertices[i].getY() << endl;
    }
}

// Agregar un vértice al grafo.
void Grafo::agregarVertice(int x, int y) {
    int id = vertices.size();
    Vertice vertice (id, x, y);
    vertices.push_back(vertice  );
    cout << "[DEBUG] Vertice agregado: ID=" << id << ", x=" << x << ", y=" << y << endl;

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
        cout << "[DEBUG] Distancia entre " << i << " y " << id << " = " << distancia << endl;
    }
}

// Imprimir matriz de adyacencia.
void Grafo::imprimirMatriz() {
    // Iteradores para recorrer la matriz.
    vector<vector<double>>::const_iterator itFila;
    vector<double>::const_iterator itCol;

    // Recorrer e imprimir.
    for (itFila = matrizAdyacencia.begin(); itFila != matrizAdyacencia.end(); itFila++) {
        for (itCol = itFila->begin(); itCol != itFila->end(); itCol++) {
            cout << *itCol << "\t";
        }
        cout << endl;
    }
}

// Obtener matriz de adyacencia.
vector<vector<double>>& Grafo::getMatrizAdyacencia() { return matrizAdyacencia; }

// Obtener vértice por índice.
Vertice& Grafo::getVertice(int indice) { return vertices[indice]; }

// Obtener cantidad de vértices.
int Grafo::getCantidadVertices() { return vertices.size(); }
