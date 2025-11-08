#include "Grafo.h"

Grafo::Grafo() {
    vertices.clear();
    matrizAdyacencia.clear();
    cout << "[DEBUG] Grafo inicializado, listas limpiadas." << endl;
}

double Grafo::calcularDistancia(const Vertice& a, const Vertice& b) const {
    int dx = abs(a.getX() - b.getX());
    int dy = abs(a.getY() - b.getY());

    cout << "[DEBUG] Calculando distancia entre vértices " << a.getId() << " y " << b.getId() << ": dx=" << dx << ", dy=" << dy << endl;

    if (dy == 0) return dx;      // misma fila
    else if (dx == 0) return dy; // misma columna
    else return sqrt(dx*dx + dy*dy); // diagonal
}

// Método normal para agregar productos
void Grafo::agregarVertice(int x, int y) {
    int id = vertices.size();
    Vertice v(id, x, y);
    vertices.push_back(v);
    cout << "[DEBUG] Vertice agregado: ID=" << id << ", x=" << x << ", y=" << y << endl;

    int n = vertices.size();

    // 🔒 Asegurar que TODAS las filas tengan tamaño n
    for (auto &fila : matrizAdyacencia) {
        fila.resize(n, 0.0);
    }

    // 🔒 Agregar una nueva fila completamente inicializada
    matrizAdyacencia.push_back(vector<double>(n, 0.0));

    // ✅ Calcular distancias con todos los anteriores (ahora sin overflow)
    for (int i = 0; i < n - 1; ++i) {
        double d = calcularDistancia(vertices[i], v);
        matrizAdyacencia[i][id] = d;
        matrizAdyacencia[id][i] = d;
        cout << "[DEBUG] Distancia entre " << i << " y " << id << " = " << d << endl;
    }
}

// Agregar el origen siempre al inicio
void Grafo::agregarOrigen() {
    // 1️⃣ Insertar origen al inicio
    Vertice origen(0, 0, 0);
    vertices.insert(vertices.begin(), origen);
    cout << "[DEBUG] Origen agregado al inicio." << endl;

    int n = vertices.size();

    // 2️⃣ Crear nueva matriz de tamaño correcto
    vector<vector<double>> nuevaMatriz(n, vector<double>(n, 0.0));

    // 3️⃣ Calcular distancias entre el origen y los demás
    for (int i = 1; i < n; ++i) {
        double d = calcularDistancia(vertices[0], vertices[i]);
        nuevaMatriz[0][i] = d;
        nuevaMatriz[i][0] = d;
        cout << "[DEBUG] Distancia del origen a " << i << " = " << d << endl;
    }

    // 4️⃣ Copiar las distancias antiguas (si existían)
    if (!matrizAdyacencia.empty()) {
        int oldN = matrizAdyacencia.size();
        for (int i = 1; i <= oldN; ++i) {
            for (int j = 1; j <= oldN; ++j) {
                // Evitar acceso fuera de rango si hay desfase
                if (i - 1 < oldN && j - 1 < oldN)
                    nuevaMatriz[i][j] = matrizAdyacencia[i - 1][j - 1];
            }
        }
    }

    matrizAdyacencia = nuevaMatriz;

    // 5️⃣ Reasignar IDs coherentes
    for (int i = 0; i < n; ++i) {
        vertices[i] = Vertice(i, vertices[i].getX(), vertices[i].getY());
        cout << "[DEBUG] ID reasignado: nuevo ID=" << i << endl;
    }

    cout << "[DEBUG] Origen agregado al grafo correctamente." << endl;
}

int Grafo::getCantidadVertices() const {
    cout << "[DEBUG] Cantidad de vértices: " << vertices.size() << endl;
    return vertices.size();
}

const Vertice& Grafo::getVertice(int indice) const {
    cout << "[DEBUG] Accediendo al vértice con índice: " << indice << endl;
    return vertices[indice];
}

const vector<vector<double>>& Grafo::getMatrizAdyacencia() const {
    cout << "[DEBUG] Accediendo a la matriz de adyacencia." << endl;
    return matrizAdyacencia;
}

void Grafo::imprimirMatriz() const {
    cout << "[DEBUG] Imprimiendo matriz de adyacencia:" << endl;
    for (vector<vector<double>>::const_iterator itFila = matrizAdyacencia.begin(); itFila != matrizAdyacencia.end(); ++itFila) {
        for (vector<double>::const_iterator itCol = itFila->begin(); itCol != itFila->end(); ++itCol) {
            cout << *itCol << "\t";
        }
        cout << endl;
    }
}