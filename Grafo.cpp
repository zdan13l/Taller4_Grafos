#include "Grafo.h"
#include <iomanip>

// Constructor.
Grafo::Grafo(int numVertices, bool esDirigido) {
    this->numVertices = numVertices;
    this->esDirigido = esDirigido;
    matrizAdyacencia = vector<vector<double>>(numVertices, vector<double>(numVertices, 0));
}

// Agregar coordenada.
void Grafo::agregarVertice(double x, double y) {
    coordenadas.push_back({x, y});
}

// Calcular distancias (genera el grafo completo).
void Grafo::calcularMatrizDistancias() {
    double dx, dy, distancia;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j) {
                dx = coordenadas[i].first - coordenadas[j].first;
                dy = coordenadas[i].second - coordenadas[j].second;

                distancia = sqrt(dx * dx + dy * dy);
                matrizAdyacencia[i][j] = distancia;

                if (!esDirigido) {
                    matrizAdyacencia[j][i] = distancia;
                }
            }
        }
    }
}

// Mostrar matriz de adyacencia.
void Grafo::mostrarMatriz() {
    if (esDirigido) {
        cout << "Grafo Dirigido" << endl;
    } else {
        cout << "Grafo No Dirigido" << endl;
    }
    cout << " - Matriz de Adyacencia (distancias):" << endl;

    // Mostrar encabezado de columnas.
    cout << "\t";
    for (int j = 0; j < numVertices; j++) {
        cout << "(" << coordenadas[j].first << ", " << coordenadas[j].second << ")\t";
    }
    cout << endl;

    // Mostrar filas con coordenadas.
    for (int i = 0; i < numVertices; i++) {
        cout << "(" << coordenadas[i].first << ", " << coordenadas[i].second << ")\t";
        for (int j = 0; j < numVertices; j++) {
            cout << matrizAdyacencia[i][j] << "\t";
        }
        cout << endl;
    }
}



// BFS y DFS (idénticos, usan matriz > 0 como conexión)
void Grafo::BFS(int verticeInicio) const {
    vector<bool> visitado(numVertices, false);
    queue<int> cola;

    visitado[verticeInicio] = true;
    cola.push(verticeInicio);

    cout << "Recorrido BFS: ";
    while (!cola.empty()) {
        int v = cola.front();
        cola.pop();
        cout << v << " ";

        for (int i = 0; i < numVertices; i++) {
            if (matrizAdyacencia[v][i] > 0 && !visitado[i]) {
                visitado[i] = true;
                cola.push(i);
            }
        }
    }
    cout << endl;
}

void Grafo::DFS(int verticeInicio) const {
    vector<bool> visitado(numVertices, false);
    cout << "Recorrido DFS: ";
    const_cast<Grafo*>(this)->DFSRecursivo(verticeInicio, visitado);
    cout << endl;
}

void Grafo::DFSRecursivo(int v, vector<bool>& visitado) {
    visitado[v] = true;
    cout << v << " ";

    for (int i = 0; i < numVertices; i++) {
        if (matrizAdyacencia[v][i] > 0 && !visitado[i])
            DFSRecursivo(i, visitado);
    }
}

