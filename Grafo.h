#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Clase Grafo representa un grafo usando una matriz de adyacencia.
class Grafo {
    private:
        int numVertices;
        bool esDirigido;
        vector<vector<double>> matrizAdyacencia;
        void DFSRecursivo(int v, vector<bool>& visitado);

    public:
        Grafo(int numVertices, bool esDirigido);

        // Métodos básicos.
        vector<pair<double, double>> coordenadas;
        void agregarVertice(double x, double y);
        void calcularMatrizDistancias();
        void mostrarMatriz();

        // Recorridos.
        void BFS(int verticeInicio) const;
        void DFS(int verticeInicio) const;
};

#endif
