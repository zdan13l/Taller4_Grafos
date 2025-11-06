#include "Grafo.h"

Grafo::Grafo() {
    vertices.clear();
    matrizAdyacencia.clear();
}

double Grafo::calcularDistancia(const Vertice& a, const Vertice& b) const {
    int dx = abs(a.getX() - b.getX());
    int dy = abs(a.getY() - b.getY());

    if (dy == 0) return dx;      // misma fila
    else if (dx == 0) return dy; // misma columna
    else return sqrt(dx*dx + dy*dy); // diagonal
}

// Método normal para agregar productos
void Grafo::agregarVertice(int x, int y) {
    int id = vertices.size();
    Vertice v(id, x, y);
    vertices.push_back(v);

    // Agregar nueva fila a la matriz
    vector<double> nuevaFila(vertices.size(), 0.0);
    matrizAdyacencia.push_back(nuevaFila);

    // Calcular distancias con todos los anteriores
    for (vector<Vertice>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
        int i = it->getId();
        int j = id;
        if (i != j) {
            double d = calcularDistancia(*it, v);
            matrizAdyacencia[i][j] = d;
            matrizAdyacencia[j][i] = d;
        }
    }
}

// Agregar el origen siempre al inicio
void Grafo::agregarOrigen() {
    Vertice origen(0, 0, 0); // id=0, x=0, y=0
    vertices.insert(vertices.begin(), origen);

    // Crear nueva matriz de adyacencia
    int n = vertices.size();
    vector<vector<double>> nuevaMatriz(n, vector<double>(n, 0.0));

    // Copiar distancias existentes y calcular las nuevas
    for (int i = 1; i < n; ++i) {
        double d = calcularDistancia(vertices[0], vertices[i]);
        nuevaMatriz[0][i] = d;
        nuevaMatriz[i][0] = d;
    }

    // Copiar distancias antiguas a la nueva matriz (desplazadas 1)
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            nuevaMatriz[i][j] = matrizAdyacencia[i-1][j-1];
        }
    }

    matrizAdyacencia = nuevaMatriz;

    // Reasignar IDs a los vértices
    for (int i = 0; i < n; ++i) {
        vertices[i] = Vertice(i, vertices[i].getX(), vertices[i].getY());
    }
}

int Grafo::getCantidadVertices() const {
    return vertices.size();
}

const Vertice& Grafo::getVertice(int indice) const {
    return vertices[indice];
}

const vector<vector<double>>& Grafo::getMatrizAdyacencia() const {
    return matrizAdyacencia;
}

void Grafo::imprimirMatriz() const {
    for (vector<vector<double>>::const_iterator itFila = matrizAdyacencia.begin(); itFila != matrizAdyacencia.end(); ++itFila) {
        for (vector<double>::const_iterator itCol = itFila->begin(); itCol != itFila->end(); ++itCol) {
            cout << *itCol << "\t";
        }
        cout << endl;
    }
}
