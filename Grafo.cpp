#include "Grafo.h"

// Constructor
Grafo::Grafo(int numVertices, bool esDirigido) {
    this->numVertices = numVertices;
    this->esDirigido = esDirigido;
    matrizAdyacencia = vector<vector<int>>(numVertices, vector<int>(numVertices, 0));
}

// Agregar una arista
void Grafo::agregarArista(int origen, int destino) {
    if (origen < 0 || origen >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Error: índice de vértice fuera de rango." << endl;
        return;
    }

    matrizAdyacencia[origen][destino] = 1;

    // Si es no dirigido, marcamos también la conexión inversa
    if (!esDirigido)
        matrizAdyacencia[destino][origen] = 1;
}

// Eliminar una arista
void Grafo::eliminarArista(int origen, int destino) {
    if (origen < 0 || origen >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Error: índice de vértice fuera de rango." << endl;
        return;
    }

    matrizAdyacencia[origen][destino] = 0;

    // Si no es dirigido, eliminar también la inversa
    if (!esDirigido)
        matrizAdyacencia[destino][origen] = 0;
}

// Mostrar la matriz de adyacencia
void Grafo::mostrarMatriz() const {
    cout << (esDirigido ? "Grafo Dirigido" : "Grafo No Dirigido") << endl;
    cout << "Matriz de Adyacencia:" << endl;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

// Recorrido BFS
void Grafo::BFS(int verticeInicio) const {
    if (verticeInicio < 0 || verticeInicio >= numVertices) {
        cout << "Error: vértice de inicio fuera de rango." << endl;
        return;
    }

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
            if (matrizAdyacencia[v][i] == 1 && !visitado[i]) {
                visitado[i] = true;
                cola.push(i);
            }
        }
    }
    cout << endl;
}

// Recorrido DFS (público)
void Grafo::DFS(int verticeInicio) const {
    if (verticeInicio < 0 || verticeInicio >= numVertices) {
        cout << "Error: vértice de inicio fuera de rango." << endl;
        return;
    }

    vector<bool> visitado(numVertices, false);
    cout << "Recorrido DFS: ";
    const_cast<Grafo*>(this)->DFSRecursivo(verticeInicio, visitado);
    cout << endl;
}

// DFS recursivo (privado)
void Grafo::DFSRecursivo(int v, vector<bool>& visitado) {
    visitado[v] = true;
    cout << v << " ";

    for (int i = 0; i < numVertices; i++) {
        if (matrizAdyacencia[v][i] == 1 && !visitado[i]) {
            DFSRecursivo(i, visitado);
        }
    }
}
